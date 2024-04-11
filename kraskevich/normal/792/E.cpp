#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const ll B = 50000;

ll res;
vector<ll> a;

bool check(ll x) {
    if (x < 1)
        return false;
    ll cur = 0;
    bool ok = true;
    for (ll b : a) {
        if (b % x > b / x) {
            ok = false;
            break;
        }
        cur += (b + x) / (x + 1);
    }
    if (ok) 
        res = min(res, cur);
    return ok;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) { 
        cin >> a[i];
        res += a[i];
    }
    sort(a.begin(), a.end());
    vector<int> f;
    for (int x = 1; x <= B; x++) 
        f.push_back(x);
    for (int x = 1; x <= B; x++)
        for (int d = -1; d <= 1; d++)
            f.push_back(a[0] / x + d);
    sort(f.rbegin(), f.rend());
    f.resize(unique(f.begin(), f.end()) - f.begin());
    random_shuffle(a.begin(), a.end());
    for (int x : f)
        if (check(x))
            break;
    cout << res << endl;
}