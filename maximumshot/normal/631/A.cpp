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

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;

const int inf = 1000000000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);
	
bool solve() {
	
	int n;
	cin >> n;
	
	vec< int > a(n), b(n);
		
	for(int i = 0;i < n;i++) cin >> a[i];
    for(int i = 0;i < n;i++) cin >> b[i];

    ll ans = 0;

    for(int l = 0;l < n;l++) {
        ll v1 = 0, v2 = 0;
        for(int r = l;r < n;r++) {
            v1 |= a[r];
            v2 |= b[r];
            ans = max(ans, v1 + v2);
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