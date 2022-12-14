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

#define MAXN 1007
int n,m,x,y,p,q;
int a[MAXN],b[MAXN],aa[MAXN][MAXN],bb[MAXN][MAXN];

int main(){ 
	//in
	scanf("%d%d",&n,&m);
	while(n--){
		scanf("%d%d",&x,&y);
		a[y]++;
		aa[x][y]++;
	}
	while(m--){
		scanf("%d%d",&x,&y);
		b[y]++;
		bb[x][y]++;
	}
	//sol
	REP(i,MAXN) p += min(a[i],b[i]);
	REP(i,MAXN) REP(j,MAXN) q += min(aa[i][j],bb[i][j]);
	//out
	cout << p << " " << q << endl;
    return 0;
}