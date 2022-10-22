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

//#include <conio.h>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector
#define deb(x) cerr << #x << " = " << x << '\n';

typedef unsigned long long ull;
typedef long double LD;
typedef long long LL;

const int inf = 1000000000ll;
const LL inf64 = 1ll * inf * inf;
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
	int n, w;

	scanf("%d %d", &n, &w);

	vec< int > a(2 * n);

	for(int i(0);i < 2 * n;i++) scanf("%d", &a[i]);
	sort(ALL(a));

	LD l, r, m;

	l = 0, r = a[0];

	for(int i(0);i < 100;i++) {
		m = (l + r) / 2.0;

		if((LD)a[n] < m * 2.0) r = m;
		else {
			LD sum = n * 3.0 * m;
			if(sum > (LD)w) r = m;
			else l = m;
		}
	}

	cout.precision(10);
	cout << fixed;

	cout << LD(r * 3.0 * n) << '\n';

    return true;
}   

int main() 
{
    //while(solve());
    solve();

    return 0;
}