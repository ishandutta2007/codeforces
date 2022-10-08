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

const int N = 100005;

int n, k;

char digits[N];

int main() {
	scanf("%d %d", &n, &k);
	int l = 0;
	scanf("%s", digits);

	while (k--) {
		while (l < n - 1 && (digits[l] != '4' || digits[l + 1] != '7')) {
			++l;
		}
		if (l == n - 1) {
			break;
		}
		if (l % 2 == 0) {
			if (l < n - 2 && digits[l + 2] == '7') {
				k %= 2;
			}
			digits[l] = digits[l + 1] = '4';
		} else {
			digits[l] = digits[l + 1] = '7';
		}
		if (l > 0) {
			--l;
		}
	}

	printf("%s\n", digits);

    return 0;
}