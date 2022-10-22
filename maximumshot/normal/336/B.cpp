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
	os << a.first;
	os << ' ';
	os << a.second;
	os << '\n';
	return os;
}

bool solve()
{	
	LD m, r;

	cin >> m >> r;

	LD sum = 0.0;

	for(int i(1);i <= m;i++) {
		sum += 2 * r;
	
		LD c1, c2;
		c1 = i - 1;
		c2 = m - i;

		if(c1 > 0) {
			sum += r + sqrt(2) * r + r;
			sum += (c1 - 1) * (r + sqrt(2) * 2 * r);
			c1--;
			sum += r * (c1 * c1);
		}

		c1 = c2;

		if(c1 > 0) {
			sum += r + sqrt(2) * r + r;
			sum += (c1 - 1) * (r + sqrt(2) * 2 * r);
			c1--;
			sum += r * (c1 * c1);
		}
	}

	cout.precision(10);
	cout << fixed;

	sum /= LD(m * m);

	cout << sum << '\n';

	return true;
}   

int main() 
{
	//while(solve());
	solve();

	return 0;
}