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

const int N = 5005;

char e[N][N];

int n;

int t[N];

int st;

int main() {
	scanf("%d\n", &n);

	for (int i = 1; i <= n; ++i) {
		gets(e[i] + 1);
		for (int j = 1; j <= n; ++j) {
			e[i][j] -= '0';
		}
	}

	t[1] = 1;
	st = 1;

	for (int i = 2; i <= n; ++i) {
		++st;
		int p = st;
		while (p > 1 && e[i][t[p - 1]]) {
			swap(t[p], t[p - 1]);
			--p;
		}
		t[p] = i;
		for (int j = 1; j < p; ++j) {
			if (e[t[p]][t[j]]) {
				printf("%d %d %d\n", t[j], t[p - 1], t[p]);
				return 0;
			}
		}
	}
	
	printf("-1\n");




    return 0;
}