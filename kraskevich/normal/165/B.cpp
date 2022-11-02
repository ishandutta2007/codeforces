#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
using namespace std;

#define pb push_back
#define F first
#define S second
typedef long long ll;

ll p(ll a, ll n) {
        ll res = 1;
        for(int i = 0; i < n; ++i)
                res *= a;
        return res;
}

int main() {
    ll n, k;
    cin >> n >> k;
    ll l = 1, r = 1e9;
    while(l < r) {
            ll m = (l + r) / 2;
            ll i = 1, sum = 0, cur = m;
            while(cur) {
                     sum += cur;
                     cur = m / p(k, i);
                     ++i;
            }
            if(sum >= n)
                   r = m;
            else
                l = m + 1;
    }
    cout << l;
    cin >> n;
    return 0;
}