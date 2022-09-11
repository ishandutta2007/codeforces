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

const int MAXSLEN=100001;
const int MAXQLEN=100000;
const int MAXTNODE=MAXQLEN+1;
const int MAXQ=100000;
struct TNode { int nxt[26]; int qid,qk; };

char s[MAXSLEN+1]; int slen;
int nq;
char buff[MAXQLEN+1];
TNode t[MAXTNODE]; int nt,troot;

int maket() { int ret=nt++; memset(t[ret].nxt,-1,sizeof(t[ret].nxt)); t[ret].qid=t[ret].qk=-1; return ret; }


int sa[MAXSLEN]; // pos->id
int cnt[MAXSLEN]; // id->#
int as[MAXSLEN]; // rnk->pos
int tmp[MAXSLEN];
int lcp[MAXSLEN-1];


void buildsa(int n) {
	//printf("%s\n",s);
	int nid=256;
	REP(i,n) sa[i]=(int)s[i];
	REPE(i,nid) cnt[i]=0; REP(i,n) ++cnt[sa[i]]; REP(i,nid) cnt[i+1]+=cnt[i];
	for(int i=n-1;i>=0;--i) as[--cnt[sa[i]]]=i;
	
	for(int gap=1;gap<n;gap*=2) {
		//printf("sa:"); REP(i,n) printf(" %d",sa[i]); puts("");
		//printf("as:"); REP(i,n) printf(" %d",as[i]); puts(""); puts("");
		REPE(i,nid) cnt[i]=0; REP(i,n) ++cnt[sa[i]]; REP(i,nid) cnt[i+1]+=cnt[i];
		for(int i=n-1;i>=0;--i) { int x=as[i]-gap; if(x<0) x+=n; tmp[--cnt[sa[x]]]=x; }
		REP(i,n) as[i]=tmp[i];
		nid=0; REP(i,n) if(i==0||sa[as[i]]!=sa[as[i-1]]||sa[as[i]+gap>=n?as[i]+gap-n:as[i]+gap]!=sa[as[i-1]+gap>=n?as[i-1]+gap-n:as[i-1]+gap]) tmp[as[i]]=nid++; else tmp[as[i]]=tmp[as[i-1]];
		REP(i,n) sa[i]=tmp[i];
	}
	//printf("sa:"); REP(i,n) printf(" %d",sa[i]); puts("");
	//printf("as:"); REP(i,n) printf(" %d",as[i]); puts("");
	//REP(i,n) { printf("%2d: ",as[i]); REP(j,n) printf("%c",s[(as[i]+j)%n]); puts(""); }

	int cur=0;
	REP(i,n) {
		if(sa[i]==n-1) { cur=0; continue; }
		int j=as[sa[i]+1]; while(cur<n&&s[i+cur>=n?i+cur-n:i+cur]==s[j+cur>=n?j+cur-n:j+cur]) ++cur;
		lcp[sa[i]]=cur; //printf("%d %d vs %d : %c vs %c\n",cur,as[i]+cur>=n?as[i]+cur-n:as[i]+cur,as[j]+cur>=n?as[j]+cur-n:as[j]+cur,s[as[i]+cur>=n?as[i]+cur-n:as[i]+cur],s[as[j]+cur>=n?as[j]+cur-n:as[j]+cur]);
		if(cur!=0) --cur;
	}
	//printf("lcp:"); REP(i,n-1) printf(" %d",lcp[i]); puts("");
}

int cur[MAXSLEN],ncur;
int ans[MAXQ];

int findfst(int l,int r,int dep,char c) {
	--l;
	while(l+1<r) {
		int m=l+(r-l)/2;
		int off=as[m];
		char cnow=off+dep>=slen?'`':s[off+dep];
		if(cnow>=c) r=m; else l=m;
	}
	return r;
}

void go(int at,int dep,int l,int r) {
	if(t[at].qid!=-1&&r-l>=t[at].qk) {
		//printf("[%d..%d)\n",l,r);
		ncur=0; FOR(i,l,r) cur[ncur++]=as[i];
		sort(cur,cur+ncur);
		int mn=INT_MAX;
		REPE(i,ncur-t[at].qk) mn=min(mn,cur[i+t[at].qk-1]-cur[i]);
		ans[t[at].qid]=mn+dep;
	}
	REP(i,26) if(t[at].nxt[i]!=-1) {
		int nl=findfst(l,r,dep,'a'+i),nr=findfst(l,r,dep,'a'+i+1);
		go(t[at].nxt[i],dep+1,nl,nr);
	}
}


void run() {
	scanf("%s",s); slen=strlen(s);
	scanf("%d",&nq);
	nt=0; troot=maket();
	REP(i,nq) {
		int k; scanf("%d%s",&k,buff);
		int at=troot; for(int j=0;buff[j]!='\0';++j) { int x=buff[j]-'a'; if(t[at].nxt[x]==-1) t[at].nxt[x]=maket(); at=t[at].nxt[x]; }
		assert(t[at].qid==-1&&t[at].qk==-1); t[at].qid=i; t[at].qk=k;
	}

	 s[slen++]='`'; s[slen]='\0';
	 buildsa(slen);
	 //REP(i,slen) printf("%2d: %s\n",i,s+as[i]);

	 REP(i,nq) ans[i]=-1;
	 go(troot,0,1,slen);
	 REP(i,nq) printf("%d\n",ans[i]);
}

int main() {
	run();
	return 0;
}