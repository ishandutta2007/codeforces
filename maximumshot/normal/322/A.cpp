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

#include <conio.h>

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
	int n, m;

	scanf("%d %d", &n, &m);
	
	printf("%d\n", m + n - 1);

	for(int i(1);i <= m;i++) {
		printf("1 %d\n", i);
	}
	
	for(int i(2);i <= n;i++) {
		printf("%d 1\n", i);
	}

	puts("");

	return true;
}   

int main() 
{
	//while(solve());
	solve();
	
	return 0;
}