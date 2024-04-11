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
#include <time.h>
#include <random>

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
	scanf("%d", &n);

	vec< int > a(n + 1); 
	vec< int > left(1e6 + 10, inf), right(1e6 + 10, -inf);
	vec< int > c(1e6 + 10, 0);

	for(int i(1);i <= n;i++) {
		scanf("%d", &a[i]);
		left[a[i]] = min(left[a[i]], i);
		right[a[i]] = max(right[a[i]], i);
		c[a[i]]++;
	}

	int mx = 0;
	for(int i(1);i <= 1e6;i++) {
		mx = max(mx, c[i]);
	}

	int ansL, ansR, ans = inf;

	for(int i(1);i <= 1e6;i++) {
		if(c[i] != mx) continue;
		int len = right[i] - left[i] + 1;
		if(len < ans) {
			ans = len;
			ansL = left[i];
			ansR = right[i];
		}
	}

	cout << ansL << ' ' << ansR << '\n';

	return true;
}   

int main() 
{
	//while(solve());
	solve();

	return 0;
}