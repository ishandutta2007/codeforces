//be naame khodaa
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <cstdio>
#include <algorithm>
#include <set>
#include <cassert>
#include <iomanip>
#include <cstring>
#include <sstream>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
#define F first
#define S second
#define pb push_back
#define sz(x) ((int)(x).size())

inline int in(){ int x, y; y = scanf("%d", &x); return x; }

const int N = 1000*100 + 100;

ll gcd(ll a, ll b) { 
	return b == 0 ? a : gcd( b , a % b ); 
}

int main(){
	int n, k; 
	cin >> n >> k; 
	ll tot = 1ll*n*k;

	int a, b; 
	cin >> a >> b; 

	ll mn = 1ll*n*k + 1, mx = 0; 
	for(int t = 0; t < 2; t++) { 
		for(int i = 0; i < n; i++) { 
			ll dis;
			if( a <= b ) 
				dis = b - a; 
			else
				dis = k - a + b; 
			dis += 1ll*i*k;
			//cout << dis << endl;
			ll v = tot/gcd(tot, dis);
			mn = min(mn, v); 
			mx = max(mx, v);
		}
		b = k - b; 
	}

	cout << mn << ' ' << mx << endl;
    return 0;
}