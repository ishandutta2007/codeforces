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

const int MX = 2000000000;

int pos[3];
int z;

void printHalf(int x) {
	printf("%d.%d00000", x / 2, 5 * (x % 2));
}

int x[200005];

int n;

bool go(int d) {
	z = 0;
	for (int i = 0; i < n; ++i) {
		if (z == 3)
			return false;
		pos[z++] = min(LL(MX), LL(x[i]) + d);
		int r = i;
		while (r < n && (x[r] - x[i]) <= 2LL * d)
			++r;
		i = r - 1;
	}
	while (z < 3)
		pos[z++] = MX;
	return true;
}


int main()
{
	scanf("%d", &n);

	REP (i, n) {
		scanf("%d", &x[i]);
		x[i] *= 2;
	}

	sort(x, x + n);

	int l = 0, r = MX;

	while (l < r) {
		int c = (l + LL(r)) / 2;
		if (go(c))
			r = c;
		else
			l = c + 1;
	}

	go(l);

	printHalf(l);
	printf("\n");
	for (int i = 0; i < 3; ++i) {
		printHalf(pos[i]);
		printf(" ");
	}
	printf("\n");


    return 0;
}