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

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector
#define deb(x) cerr << #x << " = " << x << '\n';

typedef unsigned long long ull;
typedef long double LD;
typedef long long LL;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = inf * 1000ll + 17;
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
	int n, m, q;	

	cin >> n >> m >> q;

	vec< vec<int> > mat(n + 1, vec<int>(m + 1));
	vec<int> a(n + 1);

	for(int i(1);i <= n;i++) {
		for(int j(1);j <= m;j++) {
			cin >> mat[i][j];
		}
		
		for(int j(1);j <= m;j++) {
			if(!mat[i][j]) continue;
			int k = j;
			while(k <= m && mat[i][k]) k++; k--;
			a[i] = max(a[i], k - j + 1);
			j = k;
		}
	}

	for(int H(0);H < q;H++) {
		int x, y;
		cin >> x >> y;
		mat[x][y] ^= 1;
		a[x] = 0;
		for(int j(1);j <= m;j++) {
			if(!mat[x][j]) continue;
			int k = j;
			while(k <= m && mat[x][k]) k++; k--;
			a[x] = max(a[x], k - j + 1);
			j = k;
		}
		cout << *max_element(ALL(a)) << '\n';
	}

	return true;
}   

int main() 
{
	//while(solve());
	solve();

	return 0;
}