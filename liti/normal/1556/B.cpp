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

const int N = 100*1000 + 100;
int a[N];

void solve() { 
    int n;
    cin >> n; 

    int cnt[2] = {0, 0};
    for(int i = 0; i < n; i++) {
        cin >> a[i]; 
        a[i] %= 2; 
        cnt[a[i]]++; 
    }

    if(max(cnt[0], cnt[1]) - min(cnt[0], cnt[1]) > 1) {
        cout << "-1\n";
        return;
    }
    int z = 0;
    if(cnt[1] >= cnt[0]) 
        z = 1;

    int ptr[2] = {z, z^1}; 

    ll ans = 0; 
    for(int i = 0; i < n; i++) { 
        ans += abs(i - ptr[a[i]]);
        ptr[a[i]] += 2; 
    }

    if(cnt[0] == cnt[1]) { 
        z = 0;

        int ptr[2] = {z, z^1}; 

        ll ans2 = 0; 
        for(int i = 0; i < n; i++) { 
            ans2 += abs(i - ptr[a[i]]);
            ptr[a[i]] += 2; 
        }
        ans = min(ans, ans2);
    }

    cout << ans/2 << "\n"; 
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 

    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}