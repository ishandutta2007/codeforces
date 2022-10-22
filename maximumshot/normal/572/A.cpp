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
typedef long double ld;
typedef unsigned long long ull;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;
const ll base = inf + 7;

bool solve() 
{
	int n1, n2;

	cin >> n1 >> n2;

	int k, m;

	cin >> k >> m;

	vec< int > a(n1), b(n2);
	for(int i = 0;i < n1;i++) cin >> a[i];
	for(int i = 0;i < n2;i++) cin >> b[i];

	reverse(ALL(b));

	puts(a[k - 1] < b[m - 1]?"YES" : "NO");

	return true;
}

int main() {

	//while(solve());
	solve();    

	return 0;
}