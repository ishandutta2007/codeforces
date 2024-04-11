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
#include <unordered_map>

//#include <conio.h>

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
	os << "{";
	os << a.first;
	os << ' ';
	os << a.second;
	os << "} "; 
	return os;
}

bool solve() {

	int n, m, k;

	scanf("%d %d %d", &n, &m, &k);

	vec< LL > a(n + 1);

	for(int i(1);i <= n;i++) {
		int x;
		scanf("%d", &x);
		a[i] = x;
	}

	vec< pair< pair<int, int>, LL> > q(m + 1);

	for(int i(1);i <= m;i++) {
		int l, r, d;
		scanf("%d %d %d", &l, &r, &d);
		q[i] = mp(mp(l, r), d);
	}
	
	vec< LL > delt(m + 1);

	for(int i(0);i < k;i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		delt[r]++;
		delt[l - 1]--;
	}

	for(int i(m);i >= 1;i--) {
		delt[i - 1] += delt[i];
	}

	vec< LL > delt2(n + 1);

	for(int i(1);i <= m;i++) {
		int l, r;
		l = q[i].first.first;
		r = q[i].first.second;
		LL value = q[i].second;
		value *= (LL)delt[i];
		// [l .. r] : value
		delt2[r] += value;
		delt2[l - 1] -= value;
	}

	for(int i(n);i >= 1;i--) {
		delt2[i - 1] += delt2[i]; 
	}

	for(int i(1);i <= n;i++) {
		cout << a[i] + delt2[i] << ' ';
	}
	
	cout << '\n';

	return true;
}

int main() 
{
	//while(solve());
	solve();

	return 0;
}