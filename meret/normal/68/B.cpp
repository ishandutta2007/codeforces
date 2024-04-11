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

int n, k;

int energy[10005];

bool check(double c) {
	double surplus = 0, needed = 0;
	for (int i = 1; i <= n; ++i) {
		if (energy[i] >= c)
			surplus += energy[i] - c;
		else
			needed += c - energy[i];
	}
	return surplus * (100 - k) / 100.0 >= needed;
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &energy[i]);
	double l = 0, r = 1000;
	for (int i = 0; i < 100; ++i) {
		double c = (l + r) / 2;
		if (check(c))
			l = c;
		else
			r = c;
	}

	printf("%.9lf\n", l);

    return 0;
}