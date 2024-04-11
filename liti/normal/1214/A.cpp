//be naame khodaa
#include <algorithm>
#include <iostream>
#include <cassert>
#include <iomanip>
#include <cstring>
#include <sstream>
#include <numeric>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
#define F first
#define S second
#define pb push_back
#define sz(x) ((int)(x).size())

const int N = -1;

int main() {
	int n, d, e;
	cin >> n >> d >> e; 
	e *= 5; 

	int ans = n; 
	for(int i = 0; i <= n/e; i++) {
		ans = min(ans, (n - i*e) % d);
	}

	cout << ans << endl;

    return 0;
}