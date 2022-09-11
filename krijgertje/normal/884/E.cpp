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

const int MAXW=1<<14;
const int MAXLEN=MAXW/4;

int h,w;
char s[MAXLEN+1];

bool one[MAXW];

int nid;
int pid[MAXW];
int id[MAXW];

int par[2*MAXW];
int find(int x) { if(par[x]<0) return x; return par[x]=find(par[x]); }
void unite(int x,int y) { x=find(x),y=find(y); if(x==y) return; if(-par[x]<-par[y]) swap(x,y); par[x]+=par[y]; par[y]=x; }

int mp[2*MAXW],nmp;

void run() {
	scanf("%d%d",&h,&w);
	REP(y,w) pid[y]=-1; int ret=0; nid=0;
	REP(x,h) {
		scanf("%s",s);
		REP(i,w/4) {
			int x=isdigit(s[i])?s[i]-'0':s[i]-'A'+10;
			REP(j,4) one[4*i+j]=(x&(1<<(3-j)))!=0;
		}
		//REP(y,w) printf("%c",one[y]?'1':'0'); puts("");
		REP(y,w) id[y]=one[y]?nid++:-1;
		REP(i,nid) par[i]=-1;
		REP(y,w) if(id[y]!=-1) {
			if(pid[y]!=-1) unite(id[y],pid[y]);
			if(y-1>=0&&id[y-1]!=-1) unite(id[y],id[y-1]);
		}
		REP(y,w) if(id[y]!=-1) id[y]=find(id[y]);
		REP(y,w) if(pid[y]!=-1) pid[y]=find(pid[y]);
		nmp=0; REP(i,nid) mp[i]=-1;
		REP(y,w) if(id[y]!=-1) { if(mp[id[y]]==-1) mp[id[y]]=nmp++; id[y]=mp[id[y]]; }
		REP(y,w) if(pid[y]!=-1) { if(mp[pid[y]]==-1) mp[pid[y]]=-2,++ret; }
		nid=nmp; REP(y,w) pid[y]=id[y];
	}
	ret+=nid;
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}