//BEGIN_CUT
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <numeric>
#include <bitset>
#include <cstring>
#include <sstream>
#include <utility>
#include <queue>
#include <cassert>
using namespace std;

#define X first
#define Y second
#define FI first
#define SE second
#define ST first
#define ND second
#define MP make_pair
#define PB push_back
typedef long long LL;
typedef double D;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int,int> PII;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(VAR(i,a);i<=(b);++i)
#define FORD(i,a,b) for(VAR(i,a);i>=(b);--i)
#define FORE(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define VAR(a,b) __typeof(b) a=(b)
#define SIZE(a) ((int)((a).size()))
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,a) memset(x,a,sizeof(x))
int cond = 1;
#define db(x) {if(cond){cerr << __LINE__ << " " << #x << " " << x << endl; } }
#define dbv(x) {if(cond){cerr << __LINE__ << " " << #x << ": "; FORE(__i,x) cerr << *__i << " "; cerr << endl;} }
//END_CUT

bool e[705][705];

LL path3[705][705];

int n, m;

LL res;

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		e[a][b] = e[b][a] = true;
	}

	FOR (i, 1, n)
		FOR (k, i + 1, n) {
			if (k == i)
				continue;
			FOR (j, 1, n)
				if (e[i][j] && e[j][k])
					++path3[i][k];
			path3[k][i] = path3[i][k];
		}

	FOR (i, 1, n)
		FOR (j, i + 1, n) {
			LL p4 = 0;
			FOR (k, 1, n) {
				if (k != i && e[k][j]) {
					p4 += path3[i][k] - e[i][j];
				}
			}
			FOR (k, 1, n) {
				if (e[i][k] && e[j][k]) {
					res += p4 - path3[i][k] - path3[j][k];
					if (e[i][j])
						res += 2;
				}
			}
		}

	
	cout << res / 5 << endl;

	return 0;
}