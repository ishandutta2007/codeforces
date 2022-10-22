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
	os << ' ';
	return os;
}

bool solve()
{
	LL a, b;
	string s;

	cin >> a >> b >> s;

	if(a == 0 && b == 0) {
		puts("Yes");
		return true;
	}

	vec< vec<bool> > used(201, vec<bool>(201, false));

	int x, y;
	x = 0, y= 0;

	const int delt = 100;

	used[x + delt][y + delt] = 1;

	for(int i(0);i < (int)s.size();i++) {
		if(s[i] == 'U') y++;
		else if(s[i] == 'D') y--;
		else if(s[i] == 'L') x--;
		else x++;
		used[x + delt][y + delt] = 1;
	}

	if(x == 0 && y == 0) {
		for(int tx(-100);tx <= 100;tx++) {
			for(int ty(-100);ty <= 100;ty++) {
				if(!used[tx + delt][ty + delt]) continue;
				if(tx == a && ty == b) {
					puts("Yes");
					return true;
				}
			}
		}
		puts("No");
		return true;
	}

	if(x == 0) {
		for(int tx(-100);tx <= 100;tx++) {
			for(int ty(-100);ty <= 100;ty++) {
				if(!used[tx + delt][ty + delt]) continue;
				if(a != tx) continue;
				if((b - ty) % y) continue;
				if((b - ty) / y < 0) continue;
				puts("Yes");
				return true;
			}
		}
		
		puts("No");
		return true;
	}

	if(y == 0) {
		for(int tx(-100);tx <= 100;tx++) {
			for(int ty(-100);ty <= 100;ty++) {
				if(!used[tx + delt][ty + delt]) continue;
				if(b != ty) continue;
				if((a - tx) % x) continue;
				if((a - tx) / x < 0) continue;
				puts("Yes");
				return true;
			}
		}
		
		puts("No");
		return true;
	}

	for(int i(0);i < 201;i++) {
		for(int j(0);j < 201;j++) {
			if(!used[i][j]) continue;
			//cout << i << ' ' << j << '\n';
			LL tx, ty;
			tx = i - delt;
			ty = j - delt;

			// (Xk, Yk) = (tx + (k - 1) * x, ty + (k - 1) * y)

			LL ta = a, tb = b, k1, k2;

			ta -= tx;
			if(ta % x) continue;
			k1 = ta / x;

			tb -= ty;
			if(tb % y) continue;
			k2 = tb / y;

			if(k1 >= 0 && k2 >= 0 && k1 == k2) {
				puts("Yes");
				return true;
			}
		}
	}

	puts("No");

	return true;
}   

int main() 
{
	//while(solve());
	solve();
	
	return 0;
}