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
	LL x, y;

	cin >> x >> y;

	if(x > 0) {
		if(y > 0) cout << 0 << ' ' << x + y << ' ' << x + y << ' ' << 0 << '\n';
		else cout << 0 << ' ' << y - x << ' ' << x - y << ' ' << 0 << '\n';
	}else {
		if(y > 0) cout << x - y << ' ' << 0 << ' ' << 0 << ' ' << y - x << '\n';
		else cout << x + y << ' ' << 0 << ' ' << 0 << ' ' << x + y << '\n'; 
	}

	return true;
}   

int main() 
{
	//while(solve());
	solve();

	return 0;
}