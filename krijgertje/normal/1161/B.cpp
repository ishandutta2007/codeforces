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
#include <bitset>
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

const int MAXN=100000;
const int MAXSEG=200000;

int n,nseg;
int a[MAXSEG],b[MAXSEG];

vector<int> adj[MAXN];
int id[MAXN],nid;
map<vector<int>,int> mp; 

int kmp[MAXN+1]; // kmp[i] = longest suffix prefix of id[0..i-1] that is also a prefix

bool solve() {
	REP(i,n) adj[i].clear();
	REP(i,nseg) { int aa=a[i],bb=b[i]; if(aa>bb) swap(aa,bb); adj[aa].PB(bb-aa); adj[bb].PB(n-bb+aa); }
	REP(i,n) sort(adj[i].begin(),adj[i].end());
	//REP(i,n) { printf("%d:",i); REPSZ(j,adj[i]) printf(" %d",adj[i][j]); puts(""); }

	nid=0; mp.clear();
	REP(i,n) { auto it=mp.find(adj[i]); if(it==mp.end()) { id[i]=nid++; mp[adj[i]]=id[i]; } else { id[i]=it->second; } }
	//printf("id:"); REP(i,n) printf(" %d",id[i]); puts("");

	kmp[0]=kmp[1]=0;
	FORE(i,2,n) {
		int cur=kmp[i-1]; while(cur!=0&&id[i-1]!=id[cur]) cur=kmp[cur];
		if(id[i-1]==id[cur]) ++cur;
		kmp[i]=cur;
	}
	//printf("kmp:"); REPE(i,n) printf(" %d",kmp[i]); puts("");

	int period=n-kmp[n];
	return period!=n&&n%period==0;
}

void run() {
	scanf("%d%d",&n,&nseg);
	REP(i,nseg) scanf("%d%d",&a[i],&b[i]),--a[i],--b[i];
	printf("%s\n",solve()?"Yes":"No");
}

int main() {
	run();
	return 0;
}