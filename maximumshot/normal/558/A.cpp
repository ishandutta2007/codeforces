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
#include <list>

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

	vec< pair<int, int> > a(n);

	for(int x, y, i(0);i < n;i++) {
		scanf("%d %d", &x, &y);
		a[i] = mp(x, y);
	}

	sort(ALL(a));

	int c1 = 0, c2 = 0;

	for(int i(0);i < n;i++) {
		if(a[i].first < 0) c1++;
		else c2++;
	}

	int ans = 0;

	if(c1 < c2) {
		int i = 0;
		for(;i < n;i++) {
			if(a[i].first < 0) ans += a[i].second;
			else break;
		}
		c2 = c1 + 1;
		for(;i < n && c2;i++, c2--) ans += a[i].second;
	}else if(c1 > c2) {
		int i = n - 1;
		for(;i >= 0;i--) {
			if(a[i].first > 0) ans += a[i].second;
			else break;
		}
		c1 = c2 + 1;
		for(;i >= 0 && c1;i--, c1--) ans += a[i].second;
	}else {
		for(int i(0);i < n;i++) {
			ans += a[i].second;
		}
	}

	printf("%d\n", ans);

	return true;
}   

int main() 
{
	//while(solve());
	solve();

	return 0;
}