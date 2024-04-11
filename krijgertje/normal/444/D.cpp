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

const int LIMIT=300;

int slen;
char s[50001];

int nsub;
int id[200000];
int substart[200000];
int sublen[200000];

int fst[475254];
int cnt[475254];
int nxt[200000];
int ans[475254];

typedef struct Q { int aid,bid,idx; } Q;
bool operator<(const Q &a,const Q &b) { return a.aid<b.aid; }
int nq;
Q q[100000];
int ret[100000];

int calc(int aid,int bid) {
	int ret=-1;
	int a=fst[aid],b=fst[bid];
	while(a!=-1&&b!=-1) {
		int cur=max(substart[a]+sublen[a],substart[b]+sublen[b])-min(substart[a],substart[b]); if(ret==-1||cur<ret) ret=cur;
		if(a<=b) a=nxt[a]; else b=nxt[b];
	}
	return ret;
}

void calc(int aid) {
	memset(ans,-1,sizeof(ans));
	int pa=-1,na=fst[aid];
	REP(i,nsub) {
		if(na!=-1&&substart[na]<=substart[i]) pa=na;
		if(na!=-1&&substart[na]<substart[i]) na=nxt[na];
		if(pa!=-1) { int cur=max(substart[pa]+sublen[pa],substart[i]+sublen[i])-min(substart[pa],substart[i]); if(ans[id[i]]==-1||cur<ans[id[i]]) ans[id[i]]=cur; }
		if(na!=-1) { int cur=max(substart[na]+sublen[na],substart[i]+sublen[i])-min(substart[na],substart[i]); if(ans[id[i]]==-1||cur<ans[id[i]]) ans[id[i]]=cur; }
	}
}

int offset[5]={0,0,26,26+26*26,26+26*26+26*26*26};
int getid(char *s,int slen) {
	int ret=0; REP(i,slen) ret=ret*26+(s[i]-'a'); return ret+offset[slen];
}

void run() {
	scanf("%s",s); slen=strlen(s);
	nsub=0;
	REP(i,slen) FORE(j,1,4) {
		if(i+j>slen) continue;
		id[nsub]=getid(s+i,j); substart[nsub]=i; sublen[nsub]=j; ++nsub;
	}
	//REP(i,nsub) printf("%d: %d %d -> %d\n",i,substart[i],sublen[i],id[i]);
	memset(fst,-1,sizeof(fst));
	memset(cnt,0,sizeof(cnt));
	for(int i=nsub-1;i>=0;--i) ++cnt[id[i]],nxt[i]=fst[id[i]],fst[id[i]]=i;

	scanf("%d",&nq);
	REP(i,nq) {
		char a[5],b[5]; scanf("%s%s",a,b); int alen=strlen(a),blen=strlen(b);
		int aid=getid(a,alen),bid=getid(b,blen);
		if(cnt[aid]<cnt[bid]) swap(aid,bid);
		q[i].aid=aid,q[i].bid=bid,q[i].idx=i;
	}
	sort(q,q+nq);

	for(int i=0,j=0;i<nq;i=j) {
		while(j<nq&&q[i].aid==q[j].aid) ++j;
		int aid=q[i].aid;
		if(cnt[aid]<=LIMIT) {
			FOR(k,i,j) ret[q[k].idx]=calc(q[k].aid,q[k].bid);
		} else {
			calc(q[i].aid);
			FOR(k,i,j) ret[q[k].idx]=ans[q[k].bid];
		}
	}
	REP(i,nq) printf("%d\n",ret[i]);
}

int main() {
	run();
	return 0;
}