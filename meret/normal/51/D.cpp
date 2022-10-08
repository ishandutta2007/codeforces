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

int t[100005];

const int BAD = 1000000;

int e = -1;

int n;

bool allZeroes() {
	for (int i = 1; i < n; ++i)
		if (i != e && t[i] != 0)
			return false;
	return true;
}

bool gotZero() {
	for (int i = 0; i < n; ++i)
		if (i != e && t[i] == 0)
			return true;
	return false;
}

bool isZero(double x) {
	return x > -1e-9 && x < 1e-9;
}

bool geometric() {
	if (allZeroes())
		return true;
	if (gotZero())
		return false;
	int prev = BAD;
	double dd = 0;
	for (int i = 0; i < n; ++i) {
		if (i == e)
			continue;
		if (prev != BAD) {
			double cd = t[i] / double(prev);
			if (!isZero(dd) && !isZero(dd - cd))
				return false;
			dd = cd;
		}
		prev = t[i];
	}
	return true;
}

int main()
{
	scanf("%d", &n);

	REP (i, n)
		scanf("%d", &t[i]);

	if (geometric()) {
		printf("0\n");
		return 0;
	}

	if (gotZero()) {
		bool triedZero = false, triedNonzero = false;
		for (int i = 0; i < n; ++i)
			if (t[i] == 0 && !triedZero) {
				e = i;
				if (geometric()) {
					printf("1\n");
					return 0;
				}
				triedZero = true;
			} else if (i != 0 && t[i] != 0 && !triedNonzero) {
				e = i;
				if (geometric()) {
					printf("1\n");
					return 0;
				}
				triedNonzero = true;
			}
		printf("2\n");
	} else {
		int prev = BAD;
		double dd = 0;
		for (int i = 0; i < n; ++i) {
			if (prev != BAD) {
				double cd = t[i] / double(prev);
				if (!isZero(dd) && !isZero(dd - cd)) {
					e = i - 2;
					if (geometric()) {
						printf("1\n");
						return 0;
					}
					e = i - 1;
					if (geometric()) {
						printf("1\n");
						return 0;
					}
					e = i;
					if (geometric()) {
						printf("1\n");
						return 0;
					}
					printf("2\n");
					return 0;
				}
				dd = cd;
			}
			prev = t[i];
		}
	}

	return 0;
}