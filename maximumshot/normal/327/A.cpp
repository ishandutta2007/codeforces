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

	vec<int> a(n + 1);
	int ans = 0, len = 0;
	for(int i(1);i <= n;i++) {
		scanf("%d", &a[i]);
	}

	vec<int> sum0(n + 1, 0), sum1(n + 1, 0);
	
	for(int i(1);i <= n;i++) {
		sum0[i] = sum0[i - 1] + !a[i];
		sum1[i] = sum1[i - 1] +  a[i];
	}

	vec< int > val(n + 1, 0), mn(n + 1);

	for(int i(0);i <= n;i++) {
		val[i] = sum0[i] - sum1[i];
	}

	for(int i(1);i <= n;i++) {
		mn[i] = min(mn[i - 1], val[i]);
	}

	for(int i(1);i <= n;i++) {
		int tmp = sum0[i] - mn[i - 1] + sum1[n] - sum1[i];
		ans = max(ans, tmp);
	}

	cout << ans << '\n';

	return true;
}   

int main() 
{
	//while(solve());
	solve();
	
	return 0;
}