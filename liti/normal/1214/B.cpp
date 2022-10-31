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

int main() {
	int b, g, n;
	cin >> b >> g >> n; 

	int ans = 0; 
	for(int i = 0; i <= n; i++) 
		if( i <= b && n - i <= g ) 
			ans++;

	cout << ans << endl;

    return 0;
}