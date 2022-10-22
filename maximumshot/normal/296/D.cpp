#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <time.h>

#include <conio.h>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector
#define deb(x) cerr << #x << " = " << x << '\n';

typedef unsigned long long ull;
typedef long double LD;
typedef long long LL;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = inf + 7;
const LL MOD = inf + 9;
const double pi = acos(-1.0);

using namespace std;

template<typename T, typename P>
const ostream & operator << (ostream & os, const pair<T, P> & a) {
    os.precision(10);
    os << fixed;
    os << a.first;
    os << ' ';
    os << a.second;
    os << '\n';
    return os;
}

bool solve()
{
	int n;
	scanf("%d", &n);

	vec< vec<LL> > g(n + 1, vec< LL >(n + 1));
	vec< LL > ans(n);
	
	for(int i(1);i <= n;i++) {
		for(int j(1);j <= n;j++) {
			int x;
			scanf("%d", &x);
			g[i][j] = x;
		}
	}

	vec< bool > u(n + 1);
	vec< int > q(n);

	for(int i(0);i < n;i++) scanf("%d", &q[i]);

	for(int Q(n - 1);Q >= 0;Q--) {
		int x = q[Q];
		u[x] = 1;
		for(int i(1);i <= n;i++) {
			for(int j(1);j <= n;j++) {
				g[i][j] = min(g[i][j], g[i][x] + g[x][j]);
			}
		}
		for(int i(1);i <= n;i++) {
			for(int j(1);j <= n;j++) {
				if(u[i] && u[j]) ans[Q] += g[i][j];
			}
		}
	}

	for(int i(0);i < n;i++) printf("%I64d ", ans[i]);
	puts("");

	return true;
}   

int main() 
{
	//while(solve());
    solve();

    return 0;
}