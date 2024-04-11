#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long
#define F first
#define S second


struct animal {
       ll val, n;
};

bool cmp(animal a, animal b) {
     return a.val < b.val || a.val == b.val && a.n < b.n;
}

int main() {
    ios_base::sync_with_stdio(0);
    ll n, k;
    cin >> n >> k;
    animal a[n];
    ll all = 0;
    for(int i = 0; i < n; ++i) {
            cin >> a[i].val;
            a[i].n = i + 1;
            all += a[i].val;
    }
    if(all < k) {
           cout << -1;
           cin >> n;
           return 0;
    }
    if(!k) {
           for(int i = 1; i <= n; ++i)
                   cout << i << " ";
           return 0;
    }
    sort(a, a + n, cmp);
    ll cur = 0, prev = 0;
    ll res = 0;
    for(;;) { 
            if(k >= res + (a[cur].val - prev) * (n - cur)) {
                 res += (a[cur].val - prev) * (n - cur);
                 prev = a[cur].val;
                 ++cur;
            }
            else {
                 ll faze = (k - res) % (n - cur), go = (k - res) / (n - cur);
                 go += prev;
                 for(int i = cur; i < n; ++i)
                         a[i].val -= go;
                 vector<pair<ll, ll> > res;
                 for(int i = cur; i < n; ++i)
                                     res.push_back(make_pair(a[i].n, i));
                 sort(res.begin(), res.end());
                 for(int i = 0; i < faze; ++i)
                         a[res[i].S].val--;
                 for(int i = 0; i < res.size(); ++i)
                         if(a[res[(i + faze) % res.size()].S].val > 0)
                                        cout << res[(i + faze) % res.size()].F << " ";
                 break;
            }
    }
    cin >> n;
    return 0;
}