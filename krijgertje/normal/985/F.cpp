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

const int MAXLEN=200000;


char s[MAXLEN+1]; int slen;
int nq;

int HMLT[2],HMOD[2]={1000000007,1000000009},HINV[2];
int HPW[2][MAXLEN+1];
int HIPW[2][MAXLEN+1];

int fst[MAXLEN][26];
int lst[MAXLEN][26];

int posidx[MAXLEN];
vector<int> pos[26];
vector<int> diff[26];


vector<int> h[26][2];

bool match(int a,int ax,int b,int bx,int len) {
	//printf("matching(%d,%c,%d,%c,%d)\n",a,'a'+ax,b,'a'+bx,len);
	if(fst[a][ax]>=a+len||fst[b][bx]>=b+len) return false;
	int al=posidx[fst[a][ax]],ar=posidx[lst[a+len-1][ax]],acnt=ar-al+1;
	int bl=posidx[fst[b][bx]],br=posidx[lst[b+len-1][bx]],bcnt=br-bl+1;
	if(acnt!=bcnt) return false;
	if(acnt==1) return true;
	//printf("pos[%d][%d..%d] vs pos[%d][%d..%d]\n",ax,al,ar,bx,bl,br);
	//printf("diff[%d][%d..%d] vs diff[%d][%d..%d]\n",ax,al,ar-1,bx,bl,br-1);
	REP(k,2) {
		int ahash=(ll)(h[ax][k][ar]-h[ax][k][al]+HMOD[k])*HIPW[k][al]%HMOD[k];
		int bhash=(ll)(h[bx][k][br]-h[bx][k][bl]+HMOD[k])*HIPW[k][bl]%HMOD[k];
		//printf("%d: %d vs %d\n",k,ahash,bhash);
		if(ahash!=bhash) return false;
	}
	return true;
}

bool solve(int a,int b,int len) {
	REP(i,26) if(fst[a][i]<a+len) {
		int off=fst[a][i]-a;
		int j=s[b+off]-'a';
		if(!match(a,i,b,j,len)) return false;
	}
	return true;
}

void init() {
	for(int i=slen-1;i>=0;--i) { REP(j,26) fst[i][j]=i+1>=slen?i+1:fst[i+1][j]; fst[i][s[i]-'a']=i; }
	REP(i,slen) { REP(j,26) lst[i][j]=i-1<0?i-1:lst[i-1][j]; lst[i][s[i]-'a']=i; }

	REP(j,26) pos[j].clear(); REP(i,slen) { int x=s[i]-'a'; posidx[i]=SZ(pos[x]); pos[x].PB(i); }
	REP(j,26) diff[j].clear(); REP(j,26) FORSZ(i,1,pos[j]) diff[j].PB(pos[j][i]-pos[j][i-1]);
	REP(j,26) REP(k,2) { h[j][k].clear(); h[j][k].PB(0); REPSZ(i,diff[j]) h[j][k].PB((h[j][k].back()+(ll)HPW[k][i]*diff[j][i])%HMOD[k]); }
}

void run() {
	scanf("%d%d",&slen,&nq); scanf("%s",s);
	init();

	REP(qi,nq) {
		int a,b,len; scanf("%d%d%d",&a,&b,&len); --a,--b;
		printf("%s\n",solve(a,b,len)?"YES":"NO");
	}
}

bool isprime(int x) { if(x<2) return false; for(int i=2;(ll)i*i<=x;++i) if(x%i==0) return false; return true; }

int pw(int x,int n,int mod) { int ret=1; while(true) { if(n&1) ret=(ll)ret*x%mod; if((n>>=1)==0) return ret; x=(ll)x*x%mod; } }
void inithmlt() {
	srand(std::chrono::high_resolution_clock::now().time_since_epoch().count());
	REP(j,2) {
		while(true) {
			int x=(rand()%2000*1000000+rand()%1000*1000+rand()%1000)%HMOD[j];
			if(isprime(x)) { HMLT[j]=x; break; }
		}
		//printf("HMLT[%d]=%d\n",j,HMLT[j]);
		HINV[j]=pw(HMLT[j],HMOD[j]-2,HMOD[j]);
		HPW[j][0]=1; FORE(i,1,MAXLEN) HPW[j][i]=(ll)HPW[j][i-1]*HMLT[j]%HMOD[j];
		HIPW[j][0]=1; FORE(i,1,MAXLEN) HIPW[j][i]=(ll)HIPW[j][i-1]*HINV[j]%HMOD[j];
	}
}


int mp[26]; bool mapped[26];
bool bfsolve(int a,int b,int len) {
	REP(i,26) mp[i]='?',mapped[i]=false;
	REP(i,len) {
		int x=s[a+i]-'a',y=s[b+i]-'a';
		if(mp[x]!='?') { if(mp[x]!='a'+y) return false; continue; }
		if(mapped[y]) return false;
		mp[x]='a'+y; mapped[y]=true;
	}
	return true;
}

void stress() {
	bool anyerr=false;
	REP(rep,100) {
		slen=100; REP(i,slen) s[i]='a'+rand()%5; s[slen]='\0';
		//printf("%s\n",s);
		init();
		REP(nq,1000) {
			int len=rand()%slen+1;
			int a=rand()%(slen-len+1);
			int b=rand()%(slen-len+1);
			bool have=solve(a,b,len);
			bool want=bfsolve(a,b,len);
			if(have==want) { printf("."); continue; }
			printf("%d %d %d\n",a+1,b+1,len);
			printf("err have=%s want=%s\n",have?"yes":"no",want?"yes":"no"); anyerr=true; break;
		}
		printf("!\n");
		if(anyerr) return;
	}
}

int main() {
	inithmlt();
	run();
	//stress();
	return 0;
}