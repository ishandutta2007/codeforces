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

char t[20];

int hash(int x) {
	int res = 0;
	for (int i = 0; i < 4; ++i) {
		res = 10 * res + t[(x + i) % 4];
	}
	return res;
}

bool got[10005];

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%s%s%*s", t, t + 2);
		reverse(t + 2, t + 4);
		REP (j, 4)
			t[j] -= '0';
		int h = hash(0);
		REP (j, 4)
			h = min(h, hash(j));
		got[h] = true;
	}

	int res = 0;
	for (int i = 0; i <= 10000; ++i)
		res += got[i];
	printf("%d\n", res);

    return 0;
}