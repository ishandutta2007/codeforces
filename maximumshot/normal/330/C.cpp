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
	os << '\n';
	return os;
}

bool solve()
{
	int n;
	scanf("%d", &n);

	vec< string > a(n);

	for(int i(0);i < n;i++) {
		cin >> a[i];
	}

	vec< bool > str, col;
	str = col = vec<bool>(n, 0);

	vec<int> cstr, ccol;
	cstr = ccol = vec<int>(n, 0);

	for(int i(0);i < n;i++) {
		for(int j(0);j < n;j++) {
			if(a[i][j] == 'E') continue;
			col[j] = str[i] = 1;
		}
	}

	if(find(ALL(col), false) != col.end() && find(ALL(str), false) != str.end()) {
		puts("-1");
		return true;
	}

	if(find(ALL(str), false) == str.end()) {
		for(int i(0);i < n;i++) {
			for(int j(0);j < n;j++) {
				if(a[i][j] == '.') {
					printf("%d %d\n", i + 1, j + 1);
					break;
				}
			}
		}
	}else {
		for(int i(0);i < n;i++) {
			for(int j(0);j < n;j++) {
				if(a[j][i] == '.') {
					printf("%d %d\n", j + 1, i + 1);
					break;
				}
			}
		}
	}

	return true;
}   

int main() 
{
	//while(solve());
	solve();
	
	return 0;
}