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

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;

bool solve() 
{
	vec< int > a(4);
	int n;

	for(int i = 0;i < 4;i++) cin >> a[i];

	cin >> n;

	vec< char > used(n + 1, 0);

	for(int i = 0;i < 4;i++) {
		for(int j = 0;j <= n;j += a[i]) used[j] = 1;
	}

	cout << count(used.begin() + 1, used.end(), 1) << '\n';

	return true;
}

int main() {

	//while(solve());
	solve();    

	return 0;
}