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

const int MAXN=30;
const int MAXM=MAXN-1;


int n;
int ghead[MAXN],gnxt[2*MAXM],gto[2*MAXM],deg[MAXN];

vector<pair<int,pair<int,int> > > rotate(vector<pair<int,pair<int,int> > > cur) {
	vector<pair<int,pair<int,int> > > ret;
	REPSZ(i,cur) {
		int idx=cur[i].first,x=cur[i].second.first,y=cur[i].second.second;
		ret.PB(MP(idx,MP(-y,x)));
	}
	return ret;
}

vector<pair<int,pair<int,int> > > go(int at,int par) {
	vector<pair<int,pair<int,int> > > ret;
	ret.PB(MP(at,MP(0,0)));
	for(int x=ghead[at];x!=-1;x=gnxt[x]) {
		int to=gto[x]; if(to==par) continue;
		vector<pair<int,pair<int,int> > > cur=go(to,at);
		int retmx=INT_MIN; REPSZ(i,ret) if(ret[i].second.first>retmx) retmx=ret[i].second.first;
		int curmn=INT_MAX; REPSZ(i,cur) if(cur[i].second.first<curmn) curmn=cur[i].second.first;
		REPSZ(i,cur) ret.PB(MP(cur[i].first,MP(cur[i].second.first+retmx-curmn+1,cur[i].second.second)));
		ret=rotate(ret);
	}
	ret=rotate(rotate(ret));
	return ret;
}

pair<int,int> ret[MAXN];
void run() {
	scanf("%d",&n);
	REP(i,n) ghead[i]=-1,deg[i]=0;
	REP(i,n-1) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		gnxt[2*i+0]=ghead[a]; ghead[a]=2*i+0; gto[2*i+0]=b; ++deg[a];
		gnxt[2*i+1]=ghead[b]; ghead[b]=2*i+1; gto[2*i+1]=a; ++deg[b];
	}

	REP(i,n) if(deg[i]>4) { printf("NO\n"); return; }
	printf("YES\n");
	vector<pair<int,pair<int,int> > > res=go(0,-1);
	REP(i,n) ret[i]=MP(-1,-1); REPSZ(i,res) ret[res[i].first]=res[i].second;
	REP(i,n) printf("%d %d\n",ret[i].first,ret[i].second);



}

int main() {
	run();
	return 0;
}