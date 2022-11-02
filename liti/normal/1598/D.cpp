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

const int N = 2*100*1000 + 100; 

pii a[N]; 

void solve() {
    map<int, int> rows, cols; 

    int n;
    cin >> n; 
    for(int i = 0; i < n; i++) {
        cin >> a[i].F >> a[i].S; 

        rows[a[i].F]++; 
        cols[a[i].S]++; 
    }
    
    ll ans = ll(n) * ll(n-1) * ll(n-2) / 6; 

    for(int i = 0; i < n; i++) { 
        int cr = rows[a[i].F], cc = cols[a[i].S];

        ans -= 1ll * (cr-1) * (cc-1);
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    int t;
    cin >> t;
    while(t--) 
        solve();
    return 0;
}