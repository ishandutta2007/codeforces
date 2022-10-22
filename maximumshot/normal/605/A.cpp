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
typedef long double ld;
typedef unsigned long long ull;
  
const ll inf = 1000000000ll;
const ll inf64 = inf * inf;
const ll base = inf + 7;
const ld pi = acos(-1.0);

bool solve() {
  
	int n;
	cin >> n;

	vec< int > a(n + 1), is(n + 1, 0);
	vec< int > have(n + 1);

	for(int i = 1;i <= n;i++) {
		cin >> a[i];
		is[a[i]] = 1;
		if(is[a[i] - 1]) have[a[i]] = 1;
	}

	int ans = 0;

	for(int i = 1;i <= n;i++) {
		int j = i + 1;
		while(j <= n && have[j] == 1) j++; j--;
		// [i .. j]
		ans = max(ans, j - i + 1);
		i = j;
	}

	cout << n - ans << '\n';

	return true;
}
  
int main() {
      
	//while(solve());
    solve();    
  
    return 0;
}