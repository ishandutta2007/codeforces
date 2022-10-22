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
	scanf("%d", &n);

	vec< int > a(n);

	int v = 0;

	for(int i(0);i < n;i++) {
		scanf("%d", &a[i]);
	}

	for(int maxBit(30);maxBit >= 0;maxBit--) {
		int value = (1 << 30) - 1, cnt = 0;
		for(int i(0);i < n;i++) {
			if((1 << maxBit) & a[i]) value &= a[i], cnt++;
		} 

		if(value % (1 << maxBit) == 0) {
			printf("%d\n", cnt);
			for(int i(0);i < n;i++) {
				if((1 << maxBit) & a[i]) printf("%d ", a[i]);
			}
			puts("");
			return true;
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