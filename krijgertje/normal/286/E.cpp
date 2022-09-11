#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
#include <chrono>
using namespace std;  

#define PB push_back  
#define MP make_pair  
#define SZ(v) ((int)(v).size())  
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  
#define FORSZ(i,a,v) FOR(i,a,SZ(v))  
#define REPSZ(i,v) REP(i,SZ(v))  
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }
//clock_t TBEGIN=clock();
//chrono::high_resolution_clock::time_point TBEGIN = chrono::high_resolution_clock::now();

const int MAXFFTK=21,MAXFFTN=1<<MAXFFTK;
const double MPI=acos((double)-1);
typedef struct cplx { double x,y; cplx(double x=0,double y=0):x(x),y(y) {} } cplx;
inline const cplx operator*(const cplx &a,const cplx &b) { return cplx(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x); }
inline const cplx operator+(const cplx &a,const cplx &b) { return cplx(a.x+b.x,a.y+b.y); }
inline const cplx operator-(const cplx &a,const cplx &b) { return cplx(a.x-b.x,a.y-b.y); }
inline const cplx conj(const cplx &a) { return cplx(a.x,-a.y); }
typedef struct FFT {
	int n,lgn;
	int bitrev[MAXFFTN];
	cplx w[MAXFFTN];

	void prefft(int _n) {
		n=_n; lgn=0; while((1<<lgn)<n) ++lgn; assert(n==(1<<lgn));
		bitrev[0]=0; FOR(i,1,n) bitrev[i]=bitrev[i>>1]>>1|((i&1)<<(lgn-1));
		w[1]=cplx(1,0); REP(i,lgn-1) { double a=MPI/(n>>(lgn-1-i)); cplx mlt=cplx(cos(a),sin(a)); FOR(j,1<<i,2<<i) w[2*j]=w[j],w[2*j+1]=w[j]*mlt; }
	}

	void fft(cplx *a,int n,bool inv=false) {
		//fprintf(stderr,"FFTa: %.3lf seconds\n",chrono::duration_cast<chrono::duration<double>>(chrono::high_resolution_clock::now() - TBEGIN).count());
		if(n!=this->n) prefft(n);
		//fprintf(stderr,"FFTb: %.3lf seconds\n",chrono::duration_cast<chrono::duration<double>>(chrono::high_resolution_clock::now() - TBEGIN).count());
		REP(i,n) if(i<bitrev[i]) swap(a[i],a[bitrev[i]]);
		//fprintf(stderr,"FFTc: %.3lf seconds\n",chrono::duration_cast<chrono::duration<double>>(chrono::high_resolution_clock::now() - TBEGIN).count());
		if(inv) REP(i,n) a[i].y=-a[i].y;
		//fprintf(stderr,"FFTd: %.3lf seconds\n",chrono::duration_cast<chrono::duration<double>>(chrono::high_resolution_clock::now() - TBEGIN).count());
		for(int len=1;len<n;len<<=1) for(int i=0;i<n;i+=len) for(int rep=0,j=i+len,wi=len;rep<len;++rep,++i,++j,++wi) { cplx tmp=a[j]*w[wi]; a[j]=a[i]-tmp; a[i]=a[i]+tmp; }
		//fprintf(stderr,"FFTe: %.3lf seconds\n",chrono::duration_cast<chrono::duration<double>>(chrono::high_resolution_clock::now() - TBEGIN).count());
	}

	cplx A[MAXFFTN+1];
	void mult(int *a,int na,int *b,int nb,int *c,int nc) {
		int n=1; while(n<na+nb-1) n<<=1; assert(n<=MAXFFTN);
		REP(i,n) A[i]=cplx(i<na?a[i]:0,i<nb?b[i]:0);
		//fprintf(stderr,"FFT0: %.3lf seconds\n",chrono::duration_cast<chrono::duration<double>>(chrono::high_resolution_clock::now() - TBEGIN).count());
		fft(A,n,false);
		//fprintf(stderr,"FFT1: %.3lf seconds\n",chrono::duration_cast<chrono::duration<double>>(chrono::high_resolution_clock::now() - TBEGIN).count());
		A[n]=A[0]; for(int i=0,j=n;i<=j;++i,--j) A[i]=(A[i]*A[i]-conj(A[j]*A[j]))*cplx(0,(double)-1/4/n),A[j]=conj(A[i]);
		//fprintf(stderr,"FFT2: %.3lf seconds\n",chrono::duration_cast<chrono::duration<double>>(chrono::high_resolution_clock::now() - TBEGIN).count());
		fft(A,n,true);
		//fprintf(stderr,"FFT3: %.3lf seconds\n",chrono::duration_cast<chrono::duration<double>>(chrono::high_resolution_clock::now() - TBEGIN).count());
		REP(i,nc) c[i]=floor(A[i].x+.5);
		//fprintf(stderr,"FFT4: %.3lf seconds\n",chrono::duration_cast<chrono::duration<double>>(chrono::high_resolution_clock::now() - TBEGIN).count());
	}
} FFT;
FFT fft;

const int BUFFSIZE=100000;
typedef struct Out {
	char buff[BUFFSIZE]; int nbuff;
	Out() { nbuff=0; }
	void flush() { fwrite(buff,sizeof(char),nbuff,stdout); nbuff=0; }
	void writeint(int x) { if(nbuff+50>=BUFFSIZE) flush(); if(x<0) buff[nbuff++]='-',x=-x; if(x==0) buff[nbuff++]='0'; else { int obuff=nbuff; while(x>0) buff[nbuff++]='0'+x%10,x/=10; reverse(buff+obuff,buff+nbuff); } }
	void writechar(char c) { if(nbuff>=BUFFSIZE) flush(); buff[nbuff++]=c; }
	void writestring(char *s) { for(int i=0;s[i]!='\0';++i) writechar(s[i]); }
	void writeln() { if(nbuff+50>=BUFFSIZE) flush(); buff[nbuff++]='\n'; }
} Out;
Out out;
typedef struct In {
	char buff[BUFFSIZE]; int at,nbuff;
	In() { nbuff=0; at=0; }
	int readint() {
		while(true) {
			if(at>=nbuff) { at=0; nbuff=fread(buff,sizeof(char),BUFFSIZE,stdin); assert(nbuff!=0); }
			if(buff[at]!=' '&&buff[at]!='\n') break; else ++at;
		}
		bool neg=false; int ret=0;
		if(buff[at]=='-') neg=true,++at;
		while(true) {
			if(at>=nbuff) { at=0; nbuff=fread(buff,sizeof(char),BUFFSIZE,stdin); assert(nbuff!=0); }
			char c=buff[at]; if(c<'0'||c>'9') break; else ret=10*ret+c-'0',++at;
		}
		return neg?-ret:+ret;
	}

} In;
In in;


const int MAXN=1000000;
const int MAXLIM=16000000;

int n,lim;
int a[MAXLIM+1];
int b[MAXLIM+1];

int ret[MAXN],nret;

bool solve() {
	fft.mult(a,lim+1,a,lim+1,b,lim+1);
	nret=0; REPE(i,lim) { if(b[i]!=0&&a[i]==0) return false; if(a[i]!=0&&b[i]==0) ret[nret++]=i; }
	return true;
}

void run() {
	n=in.readint(),lim=in.readint(); REPE(i,lim) a[i]=0; REP(i,n)  a[in.readint()]=1;
	//fprintf(stderr,"Read: %.3lf seconds\n",chrono::duration_cast<chrono::duration<double>>(chrono::high_resolution_clock::now() - TBEGIN).count());
	if(!solve()) { out.writestring("NO\n"); return; }
	//fprintf(stderr,"Solved: %.3lf seconds\n",chrono::duration_cast<chrono::duration<double>>(chrono::high_resolution_clock::now() - TBEGIN).count());
	out.writestring("YES\n");
	out.writeint(nret); out.writeln();
	REP(i,nret) { if(i!=0) out.writechar(' '); out.writeint(ret[i]); } out.writeln();
}

void stress() {
	n=0; lim=MAXLIM; REPE(i,lim) a[i]=0; FORE(i,100000,lim) a[i]=1,++n;
	//printf("%d %d\n",n,lim); REPE(i,lim) if(a[i]==1) printf("%d\n",i);
	solve();
}

int main() {
	run();
	//stress();
	out.flush();
	//fprintf(stderr,"Took: %.3lf seconds\n",chrono::duration_cast<chrono::duration<double>>(chrono::high_resolution_clock::now() - TBEGIN).count());
	return 0;
}