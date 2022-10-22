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

int main() 
{
	LL n;

	cin >> n;

	if(n % 3) {
		puts("0");
		return 0;
	}

	n /= 3;

	vec< LL > s;

	s.push_back(1);
	s.push_back(n);
	for(LL i(1);i * i <= n;i++) {
		if(n % i) continue;
		s.push_back(i);
	}

	int ans = 0;
	LL x, y, a, b, c;

	for(int i(0);i < (int)s.size();i++) {
		x = s[i];
		LL value = n / x;
		for(int j(0);j < (int)s.size();j++) {
			y = s[j];
			if(value % y == 0) {
				if((x + y - value / y) % 2 == 0) {
					a = (x + y - value / y) / 2;
					b = x - a;
					c = y - a;
					if(a > 0 && b > 0 && c > 0) ans++;
				}
			}
		}
	}	

	cout << ans << '\n';

	return 0;
}