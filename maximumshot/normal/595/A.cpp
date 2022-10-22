#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple 

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;
const ll base = inf + 7;

bool solve()
{
	int n, m, ans = 0;

	cin >> n >> m;

	vec< vec< int > > a(n + 1, vec< int >(2 * m + 1));

	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= 2 * m;j++) {
			cin >> a[i][j];
		}
	}

	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++) {
			if(a[i][2 * j - 1] == 1 || a[i][2 * j] == 1) ans++;
		}
	}

	cout << ans << '\n';

	return true;
} 

int main() {
	
	//while(solve());
	solve();	

	return 0;
}