#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <cmath>
#include <sstream>
using namespace std;
#define PB push_back
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define FORE(i,x) for(__typeof((x).begin()) i=(x).begin();i != (x).end();++i)
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,w) memset((x),w,sizeof (x))
#define X first
#define Y second
typedef long long int lli;
typedef pair<int, int> P;
typedef vector<int> VI;

#define MAXN 100007
int n,m,p[MAXN],a,b,res[MAXN];
VI kraw[MAXN],kraw2[MAXN];
bool vis[MAXN], vis2[MAXN];

void dfs(int x){
	vis[x] = true;
	res[x] = 1;
	FORE(i,kraw[x]) {
		res[*i] = 1;
		if(!vis[*i] && p[*i] != 1)
			dfs(*i);
	}
}

void go(int x){
	vis2[x] = true;
	FORE(i,kraw2[x])
		if(!vis2[*i])
			go(*i);
}

int main(){ 
	//in
	scanf("%d%d",&n,&m);
	FOR(i,1,n) scanf("%d",&p[i]);
	while(m--){
		scanf("%d%d",&a,&b);
		kraw[b].PB(a);
		kraw2[a].PB(b);
	}
	//sol
	FOR(i,1,n) if(p[i] == 2 && !vis[i])
		dfs(i);
	FOR(i,1,n) if(p[i] == 1 && !vis2[i])
		go(i);
	FOR(i,1,n) if(!vis2[i])
		res[i] = 0;
	//out
	FOR(i,1,n)
		printf("%d\n", res[i]);
    return 0;
}