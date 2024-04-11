#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <set>
#include <string>
#include <tuple>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <map>
#include <queue>
#include <bitset>
#include <list>
#include <stack>
#include <math.h>
#include <unordered_map>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;
typedef pair< double, double > pdd;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1ll * inf * inf;

bool solve() {
	
	cout.precision(10);
	cout << fixed;

	int n;
	cin >> n;

	vec< double > mx(n + 1), mn(n + 1), a(n + 1), b(n + 1);

	for(int i = 1;i <= n;i++) cin >> mx[i];
	for(int i = 1;i <= n;i++) cin >> mn[i];

	double s1, s2;
	s1 = s2 = 0.0;

	for(int i = 1;i <= n;i++) {
		double cur = mn[i] + mx[i];
		double P = s1 - s2 + cur;
		double Q = mx[i] - cur * s2;
		double D = P * P - 4 * Q;
		if(D < 0) D = 0.0;
		else D = sqrt(D);
		b[i] = (P - D) / 2.0;
		a[i] = cur - b[i];
		s1 += a[i];
		s2 += b[i];
	}

	for(int i = 1;i <= n;i++) cout << a[i] << ' ';
	cout << '\n';
	for(int i = 1;i <= n;i++) cout << b[i] << ' ';
	cout << '\n';

	return true;
}

int main() {
		
	//while(solve());
	solve();

	return 0;
}