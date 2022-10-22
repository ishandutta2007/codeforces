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

int n, m;
vec< LL > a;

bool check(LL x) {
	vec< LL > b = a;
	int p = 0;
	for(int i(0);i < m;i++) {
		LL t = 0, last = 0;
		for(;p < n && t <= x;p++) {
			if(b[p] > 0) {
				t += p - last + 1;
				if(t + b[p] <= x) t += b[p], b[p] = 0, last = p + 1;
				else {
					if(t <= x) b[p] -= (x - t);
					break;
				}
			}
		}
	}
	for(int i(0);i < n;i++) {
		if(b[i] > 0) return 0;
	}
	return 1;
}

bool solve()
{	
	scanf("%d %d", &n, &m);

	a.resize(n);

	for(int i(0);i < n;i++) cin >> a[i];

	LL l = 0, r = inf64 / 100, mid;

	while(r - l > 1) {
		mid = (l + r) >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}


	cout << (check(l)?l : r) << '\n';

	return true;
}   

int main() 
{
	//while(solve());
	solve();

	return 0;
}