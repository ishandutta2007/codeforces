#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <cmath>
using namespace std;

typedef long long ll;
#define F first
#define S second
#define pb push_back

int main() {
    ios_base::sync_with_stdio(0);
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    int res = 0;
    for(int i = 0; i < n; ++i)
            cin >> a[i];
    bool ok = false;
    for(int i = 0; i < n; ++i) 
            if(a[i] == x)
                     ok = true;
    if(!ok) {
            ++res;
            a.pb(x);
    } 
    sort(a.begin(), a.end());
    int l =  1000, r = -1;
    for(int i = 0; i < a.size(); ++i)
            if(a[i] == x) {
                    l = min(l, i);
                    r = max(r, i);
            }
    n = a.size();
    ++l;
    ++r;
    int m = (n + 1) / 2;
    if(l <= m && r >= m) {
         cout << res;
         cin >> n;
         return 0;
    }
    int cur1 = 0, cur2 = 0, sz = n;
    int ans = 1000 * 1000;
    if(l > m) {
         while(l > m) {
            sz++;
            m = (sz + 1) / 2;
            ++cur1;
         }
         ans = cur1;
    }
    sz = n;
    if(r < m) {
         while(r < m) {
                 sz++;
                 m = (sz + 1) / 2;
                 ++r;
                 ++cur2;
         }
         ans = cur2;
    }    
    cout << res + ans; 
    cin >> n;
    return 0;
}