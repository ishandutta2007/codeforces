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

const int MAXN=300000;
const int MAXM=300000;

int n,m;
int fst[MAXN];
int len[MAXM],nxt[2*MAXM],to[2*MAXM];
int s;

ll d[MAXN]; int bck[MAXN]; bool been[MAXN];
priority_queue<pair<pair<ll,ll>,int> > q;

ll retsum;
int ret[MAXM],nret;

void run() {
	scanf("%d%d",&n,&m);
	REP(i,n) fst[i]=-1;
	REP(i,m) {
		int a,b; scanf("%d%d%d",&a,&b,&len[i]); --a,--b;
		nxt[2*i+0]=fst[a]; fst[a]=2*i+0; to[2*i+0]=b;
		nxt[2*i+1]=fst[b]; fst[b]=2*i+1; to[2*i+1]=a;
	}
	scanf("%d",&s); --s;

	retsum=0; nret=0;
	REP(i,n) d[i]=LLONG_MAX,bck[i]=-1,been[i]=false;
	d[s]=0; bck[s]=-2; q.push(MP(MP(-d[s],0LL),s));
	while(!q.empty()) {
		ll cd=-q.top().first.first,cpd=-q.top().first.second; int at=q.top().second; q.pop();
		if(been[at]) continue; else been[at]=true;
		//printf("at %d (%lld,%lld)\n",at,cd,cpd);
		retsum+=cpd; if(bck[at]>=0) ret[nret++]=bck[at]/2;
		for(int x=fst[at];x!=-1;x=nxt[x]) {
			ll npd=len[x/2],nd=cd+npd; int nbck=x^1;
			if(nd<d[to[x]]||nd==d[to[x]]&&npd<len[bck[to[x]]/2]) { d[to[x]]=nd; bck[to[x]]=x^1; q.push(MP(MP(-nd,-npd),to[x])); }
		}
	}
	sort(ret,ret+nret);
	cout<<retsum<<endl;
	REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]+1); } puts("");
}


int main() {
	run();
	return 0;
}