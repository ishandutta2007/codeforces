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

const int MAXN=1000000;
const int MAXQ=1000000;
const int MAXM=MAXN-1;
const int MAXLG=20;
clock_t TBEGIN;

int n,nq;
int ghead[MAXN],gtail[MAXN],gnxt[2*MAXM],gto[2*MAXM],gprv[2*MAXM];

ll parinfo[MAXN][MAXLG];
ll encode(int c,int via,int mn) {
	return (((ll)c)<<40)|(((ll)via)<<20)|((ll)mn);
}
void decode(ll val,int &c,int &via,int &mn) {
	mn=val&((1<<20)-1); val>>=20; via=val&((1<<20)-1); val>>=20; c=val;
}

int cmn[MAXN],cvia[MAXN],cmn2[MAXN];


int sz[MAXN];
int dfssz(int at,int par) {
	sz[at]=1;
	for(int x=ghead[at];x!=-1;x=gnxt[x]) {
		int to=gto[x]; if(to==par) continue;
		sz[at]+=dfssz(to,at);
	}
	//printf("sz%d = %d\n",at+1,sz[at]);
	return sz[at];
}
int dfscentroid(int at,int par,int totsz) {
	int mx=totsz-sz[at];
	for(int x=ghead[at];x!=-1;x=gnxt[x]) {
		int to=gto[x]; if(to==par) continue;
		mx=max(mx,sz[to]);
	}
	if(2*mx<=totsz) { /*printf("at=%d mx=%d totsz=%d\n",at+1,mx,totsz);*/ return at; }
	for(int x=ghead[at];x!=-1;x=gnxt[x]) {
		int to=gto[x]; if(to==par) continue;
		int ret=dfscentroid(to,at,totsz);
		if(ret!=-1) return ret;
	}
	return -1;
}
int centroid(int at) {
	//printf("centroid(%d)\n",at+1);
	int totsz=dfssz(at,-1);
	int ret=dfscentroid(at,-1,totsz);
	return ret;
}

void dfsparinfo(int at,int par,int k,int c,int via,int mn) {
	//printf("parinfo[%d][%d]=%d,%d,%d\n",at+1,k,c+1,via+1,mn+1);
	parinfo[at][k]=encode(c,via,mn);
	for(int x=ghead[at];x!=-1;x=gnxt[x]) {
		int to=gto[x]; if(to==par) continue;
		dfsparinfo(to,at,k,c,via,min(mn,to));
	}
}

void removeedge(int x) {
	int a=gto[x^1],b=gto[x];
	if(gprv[x]==-1) ghead[a]=gnxt[x]; else gnxt[gprv[x]]=gnxt[x];
	if(gnxt[x]==-1) gtail[a]=gprv[x]; else gprv[gnxt[x]]=gprv[x];
}
void decompose(int at,int k) {
	at=centroid(at);
	//printf("centroid at level %d = %d\n",k,at+1);
	parinfo[at][k]=encode(at,at,at);
	for(int x=ghead[at];x!=-1;x=gnxt[x]) {
		removeedge(x^1);
		int to=gto[x];
		dfsparinfo(to,at,k,at,to,min(at,to));
		decompose(to,k+1);
	}
}

int qkind[MAXQ],qz[MAXQ];

void gen() {
	srand(42);
    n = 1000000;
    nq = 1000000;
	REP(i,n) ghead[i]=-1;
    auto f = [&](int x) { return n + 1 - x; };
    REP(i,n-1) {
		int a=f(i + 2),b=f(1 + rand() % (i + 1)); --a,--b;
		gnxt[2*i+0]=ghead[a],ghead[a]=2*i+0,gto[2*i+0]=b;
		gnxt[2*i+1]=ghead[b],ghead[b]=2*i+1,gto[2*i+1]=a;
    }
	qkind[0]=1,qz[0]=n-2;
	FOR(i,1,nq) qkind[i]=2,qz[i]=rand() % n + 1;
}

const int BUFFSIZE=100000;
typedef struct Out {
	char buff[BUFFSIZE]; int nbuff;
	Out() { nbuff=0; }
	void flush() { fwrite(buff,sizeof(char),nbuff,stdout); nbuff=0; }
	void writeint(int x) { if(nbuff+50>=BUFFSIZE) flush(); if(x<0) buff[nbuff++]='-',x=-x; if(x==0) buff[nbuff++]='0'; else { int obuff=nbuff; while(x>0) buff[nbuff++]='0'+x%10,x/=10; reverse(buff+obuff,buff+nbuff); } }
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

void run() {
	n=in.readint(); nq=in.readint();
	REP(i,n) ghead[i]=gtail[i]=-1;
	REP(i,n-1) {
		int a=in.readint(),b=in.readint(); --a,--b;
		if(ghead[a]==-1) gtail[a]=2*i+0; else gprv[ghead[a]]=2*i+0; gnxt[2*i+0]=ghead[a],ghead[a]=2*i+0,gto[2*i+0]=b,gprv[2*i+0]=-1; 
		if(ghead[b]==-1) gtail[b]=2*i+1; else gprv[ghead[b]]=2*i+1; gnxt[2*i+1]=ghead[b],ghead[b]=2*i+1,gto[2*i+1]=a,gprv[2*i+1]=-1;
	}
	REP(i,nq) qkind[i]=in.readint(),qz[i]=in.readint();
	//gen();
	fprintf(stderr,"Read input: %.3lf seconds\n",double(clock() - TBEGIN) / CLOCKS_PER_SEC);

	memset(parinfo,-1,sizeof(parinfo));
	decompose(0,0);
	REP(i,n) cmn[i]=cmn2[i]=INT_MAX,cvia[i]=-1;
	fprintf(stderr,"Decomposed: %.3lf seconds\n",double(clock() - TBEGIN) / CLOCKS_PER_SEC);

	/*REP(i,n) REP(k,MAXLG) if(parinfo[i][k]!=-1) {
		int c,mn,via; decode(parinfo[i][k],c,via,mn);
		printf("%d %d: c=%d mn=%d via=%d\n",i+1,k,c+1,mn+1,via+1);
	}*/

	int last=0;
	REP(i,nq) {
		int kind=qkind[i],z=qz[i]; int x=(z+last)%n+1; /*printf("q: %d %d\n",kind,x);*/ --x;
		if(kind==1) {
			REP(k,MAXLG) if(parinfo[x][k]!=-1) {
				int c,mn,via; decode(parinfo[x][k],c,via,mn);
				if(mn<cmn[c]) { if(cvia[c]!=via) cmn2[c]=cmn[c]; cmn[c]=mn,cvia[c]=via; } else if(via!=cvia[c]&&mn<cmn2[c]) cmn2[c]=mn;
			}
		}
		if(kind==2) {
			int ans=INT_MAX;
			REP(k,MAXLG) if(parinfo[x][k]!=-1) {
				int c,mn,via; decode(parinfo[x][k],c,via,mn);
				if(cmn[c]!=INT_MAX&&(cvia[c]!=via||via==c)) ans=min(ans,min(mn,cmn[c]));
				if(cmn2[c]!=INT_MAX) ans=min(ans,min(mn,cmn2[c]));
			}
			++ans; last=ans; out.writeint(ans); out.writeln();
		}
	}
	out.flush();
}

int main() {
	TBEGIN = clock();
	run();
	fprintf(stderr,"Took: %.3lf seconds\n",double(clock() - TBEGIN) / CLOCKS_PER_SEC);
	return 0;
}