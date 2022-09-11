#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXLEN=1500000;

const int MAXFFTK=21,MAXFFTN=1<<MAXFFTK;
const long double MPI=acos((long double)-1);
typedef struct cplx { long double x,y; cplx(long double x=0,long double y=0):x(x),y(y) {} } cplx;
inline cplx operator*(const cplx &a,const cplx &b) { return cplx(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x); }
inline cplx operator+(const cplx &a,const cplx &b) { return cplx(a.x+b.x,a.y+b.y); }
inline cplx operator-(const cplx &a,const cplx &b) { return cplx(a.x-b.x,a.y-b.y); }
inline cplx conj(const cplx &a) { return cplx(a.x,-a.y); }
typedef struct FFT {
	int n,lgn;
	int bitrev[MAXFFTN];
	cplx w[MAXFFTN];

	void prefft(int _n) {
		n=_n; lgn=0; while((1<<lgn)<n) ++lgn; assert(n==(1<<lgn));
		bitrev[0]=0; FOR(i,1,n) bitrev[i]=bitrev[i>>1]>>1|((i&1)<<(lgn-1));
		w[1]=cplx(1,0); REP(i,lgn-1) { long double a=MPI/(n>>(lgn-1-i)); cplx mlt=cplx(cos(a),sin(a)); FOR(j,1<<i,2<<i) w[2*j]=w[j],w[2*j+1]=w[j]*mlt; }
	}

	void fft(cplx *a,int n,bool inv=false) {
		if(n!=this->n) prefft(n);
		REP(i,n) if(i<bitrev[i]) swap(a[i],a[bitrev[i]]);
		if(inv) REP(i,n) a[i].y=-a[i].y;
		for(int len=1;len<n;len<<=1) for(int i=0;i<n;i+=len) for(int rep=0,j=i+len,wi=len;rep<len;++rep,++i,++j,++wi) { cplx tmp=a[j]*w[wi]; a[j]=a[i]-tmp; a[i]=a[i]+tmp; }
	}

	cplx A[MAXFFTN+1];
	int mult(int *a,int na,int *b,int nb,ll *c,int nc) {
		if(na==0||nb==0) return 0;
		int n=1; while(n<na+nb-1) n<<=1; assert(n<=MAXFFTN);
		REP(i,n) A[i]=cplx(i<na?a[i]:0,i<nb?b[i]:0);
		fft(A,n,false);
		A[n]=A[0]; for(int i=0,j=n;i<=j;++i,--j) A[i]=(A[i]*A[i]-conj(A[j]*A[j]))*cplx(0,(long double)-1/4/n),A[j]=conj(A[i]);
		fft(A,n,true);
		REP(i,nc) { ll cur=i>=n?0:(ll)floor(A[i].x+.5); /*assert(fabs(A[i].x-cur)<.1);*/ c[i]=cur; }
	}
} FFT;

FFT fft;


vector<int> mult(vector<int> &a,vector<int> &b) {
	vector<ll> c(SZ(a)+SZ(b),0);
	fft.mult(a.data(),SZ(a),b.data(),SZ(b),c.data(),SZ(c));
	int d=0; REPSZ(i,c) { d+=c[i]; c[i]=d%100; d/=100; } assert(d==0); while(SZ(c)>0&&c.back()==0) c.pop_back();
	vector<int> ret(SZ(c)); REPSZ(i,ret) ret[i]=c[i]; return ret;
}

string calcpw(int n) {
	vector<int> res(1,1),x(1,3);
	while(true) {
		if(n&1) res=mult(res,x);
		if((n>>=1)==0) break;
		x=mult(x,x);
	}
	//vector<int> nres(3*SZ(res),0); REPSZ(i,res) nres[3*i+0]=res[i]%10,nres[3*i+1]=res[i]/10%10,nres[3*i+2]=res[i]/100; while(SZ(nres)>0&&nres.back()==0) nres.pop_back(); res=nres;
	vector<int> nres(2*SZ(res),0); REPSZ(i,res) nres[2*i+0]=res[i]%10,nres[2*i+1]=res[i]/10; while(SZ(nres)>0&&nres.back()==0) nres.pop_back(); res=nres;
	string ret(SZ(res),'?'); REPSZ(i,ret) ret[SZ(ret)-i-1]='0'+res[i]; return ret;
}

bool greatereq(const string &a,const string &b) { if(SZ(a)!=SZ(b)) return SZ(a)>SZ(b); REPSZ(i,a) if(a[i]!=b[i]) return a[i]>b[i]; return true; }
string mult(const string &a,int x) { string b(SZ(a),'?'); int c=0; for(int i=SZ(a)-1;i>=0;--i) { c+=x*(a[i]-'0'); b[i]='0'+c%10; c/=10; } return c==0?b:string(1,'0'+c)+b; }

void run() {
	string s; cin>>s;
	//string s=string(1500000,'9');
	
	int slen=SZ(s);
	int bmn=max(0,(int)ceil((slen-1)/log10(3)-log(4)/log(3))-1);

	string bpw=calcpw(bmn);
	string bpw4=mult(bpw,4);
	assert(SZ(s)==1||!greatereq(bpw4,s));
	while(!greatereq(bpw4,s)) ++bmn,bpw=mult(bpw,3),bpw4=mult(bpw4,3);

	int ret=3*bmn+4;
	if(greatereq(bpw,s)) ret=min(ret,3*bmn+0);
	if(greatereq(mult(bpw,3),s)) ret=min(ret,3*bmn+3);
	if(greatereq(mult(bpw,2),s)) ret=min(ret,3*bmn+2);
	ret=max(ret,1);
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}