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
	LL l, r, d, u;
	l = d = +inf64;
	r = u = -inf64;

	int n;

	scanf("%d", &n);

	LL s = 0;

	for(int i(0);i < n;i++) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		l = min(l, (LL)x1); r = max(r, (LL)x2);
		d = min(d, (LL)y1); u = max(u, (LL)y2);
		s += LL(x2 - x1) * LL(y2 - y1);
	}

	puts(s == LL(u - d) * LL(r - l) && (r - l) == (u - d)?"YES" : "NO");

	return true;
}   

int main() 
{
	//while(solve());
	solve();
	
	return 0;
}