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

bool solve()
{		
	int n;
	scanf("%d", &n);

	vec< int > a(n);

	for(int i(0);i < n;i++) scanf("%d", &a[i]);

	for(int i(0);i < n + 1;i++) {
		for(int j(0);j < n;j++) {
			if(j % 2) {
				a[j]--;
				a[j] = (a[j] % n + n) % n;
			}else {
				a[j] = (a[j] + 1) % n;	
			}
		}
		bool ok = 1;
		for(int j(0);j < n;j++) {
			if(j != a[j]) ok = 0;
		}

		if(ok) {
			puts("Yes");
			return true;
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