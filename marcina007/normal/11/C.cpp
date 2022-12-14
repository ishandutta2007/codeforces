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

#define MAXN 257
int t,n,m;
char c[MAXN][MAXN];
bool vis[MAXN][MAXN];
int ile[MAXN][MAXN];

int main(){
	scanf("%d", &t);
	while(t--){
		//in
		scanf("%d%d",&n,&m);
		CLR(c,0);
		REP(i,n) scanf("%s", c[i+1]+1);
		//pre
		int res = 0;
		CLR(vis, 0);
		CLR(ile, 0);
		FOR(i,1,n) FOR(j,1,m) if(c[i][j] == '1')
			FOR(ii,i-1,i+1) FOR(jj,j-1,j+1) if(ii==i || jj==j) if(c[ii][jj] == '1')
				ile[ii][jj]++;
		//sol
		FOR(i,1,n) FOR(j,1,m) if(ile[i][j] == 3 && !vis[i][j]) {
			int d = 0;
			while(ile[i+d][j] == 3) vis[i+(d++)][j] = true;
			if(d == 1) continue;
			bool ok = true;
			REP(k,d) {
				ok &= (ile[i+k][j] == 3);
				ok &= (ile[i][j+k] == 3);
				ok &= (ile[i+k][j+d-1] == 3);
				ok &= (ile[i+d-1][j+k] == 3);
			}
			ok &= (c[i-1][j-1] != '1');
			ok &= (c[i+d][j+d] != '1');
			ok &= (c[i-1][j+d] != '1');
			ok &= (c[i+d][j-1] != '1');
			res += ok;
		}
		//
		CLR(vis,0);
		CLR(ile,0);
		FOR(i,1,n) FOR(j,1,m) if(c[i][j] == '1')
			FOR(ii,i-1,i+1) FOR(jj,j-1,j+1) if(c[ii][jj] == '1')
				ile[ii][jj]++;
		//sol
		FOR(i,1,n) FOR(j,1,m) if(ile[i][j] == 3 && !vis[i][j]) {
			int d = 0;
			while(ile[i+d][j+d] == 3) {vis[i+d][j+d] = true; d++;}
			if(d == 1) continue;
			bool ok = true;
			REP(k,d) {
				ok &= (ile[i+k][j+k] == 3);
				ok &= (ile[i-k][j+k] == 3);
				ok &= (ile[i+k-(d-1)][j+k+(d-1)] == 3);
				ok &= (ile[i-k+(d-1)][j+k+(d-1)] == 3);
			}
			res += ok;
		}
		//out
		printf("%d\n", res);
	}
    return 0;
}