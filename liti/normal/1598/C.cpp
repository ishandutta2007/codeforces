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

void solve() {
    map<int,int> cnt; 

    ll sum = 0; 

    int n; cin >> n;

    for(int i = 0; i < n; i++) { 
        int x;
        cin >> x; 
        cnt[x]++; 
        sum += x; 
    }

    ll val = sum * 2;
    if( val % n != 0 ) { 
        cout << "0\n";
        return;
    }

    val = val / n;

    ll ans = 0; 

    for(auto& [a, b]: cnt) {
       ll other = val - a; 
       
       if(cnt.count(other) == 0) 
           continue; 

       if (other == a) 
           ans += b * ll(b-1) / 2;
       else if(a < other)
           ans += b * ll(cnt[other]);  
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