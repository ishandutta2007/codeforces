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
	os << "{";
	os << a.first;
	os << ' ';
	os << a.second;
	os << "} "; 
	return os;
}

bool solve()
{	
	int n;

	cin >> n;

	int mx1, mx2, mx3;
	int mn1, mn2, mn3;

	cin >> mn1 >> mx1;
	cin >> mn2 >> mx2;
	cin >> mn3 >> mx3;

	int a1, a2, a3;

	a1 = mn1;
	a2 = mn2;
	a3 = mn3;

	if(a2 + a3 + mx1 >= n) {
		cout << n - a2 - a3 << ' ' << a2 << ' ' << a3 << '\n';
		return true;
	}

	a1 = mx1;

	if(a1 + mx2 + a3 >= n) {
		cout << a1 << ' ' << n - a1 - a3 << ' ' << a3 << '\n';
		return true;
	}

	a2 = mx2;

	cout << a1 << ' ' << a2 << ' ' << n - a1 - a2 << '\n';

	return true;
}   

int main() 
{
	//while(solve());
	solve();

	return 0;
}