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

	
const LD minProbability = 31.4159265352718281828459045l;

int t[4];
int p[4];

int main()
{
	for (int i = 0; i < 4; ++i) {
		cin >> p[i];
		t[i] = i;
	}
	int a, b;
	cin >> a >> b;

	int res = 0;

	for (int i = a; i <= b; ++i) {
		int good = 0;
		do {
			int c = i;
			for (int j = 0; j < 4; ++j)
				c %= p[t[j]];
			if (c == i)
				++good;
		} while (next_permutation(t, t + 4));
		if (100 * LD(good) / 24.0 + 1e-12 >= minProbability)
			++res;
	}

	cout << res << endl;

    return 0;
}