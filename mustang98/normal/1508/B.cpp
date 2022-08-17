#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111, inf = 1000111222;

vector<int> solve(ll n, ll k) {
    vector<int> ans;
    if (n == 1) {
        if (k == 1) {
            ans.PB(1);
            return ans;
        } else {
            return ans;
        }
    }

    if (n < 63 && k > (1LL << (n - 1))) {
        return vector<int>();
    }
    vector<int> v;
    for (int i = 1; i <= n; ++i) {
        v.PB(i);
    }
    reverse(v.begin(), v.end());
    while (v.size() > 62) {
        ans.PB(v.back());
        v.pop_back();
    }
    while (v.size() > 0) {
        int cur = v.back();
        for (int x = cur; x <= n; ++x) {
            int sz = max(0LL, n - x - 1);
            ll cnt = (1LL << sz);
           // cout << x << ' ' << k << ' ' << cnt << endl;
            if (k <= cnt) {
                cur = x;
                break;
            }
            k -= cnt;
        }
        //cout << "$$ " << cur << ' ' << k << endl;
        for (int i = cur; i >= v.back(); --i) {
            ans.push_back(i);
        }
        while (!v.empty() && v.back() <= cur) {
            v.pop_back();
        }
    }
    return ans;
}

int main()
{
   // freopen("input.txt", "r", stdin);
//    precalc();
    int T;
    cin >> T;
    while (T--) {
        ll n, k;
        cin >> n >> k;
        vector<int> res = solve(n, k);
        if (res.empty()) {
            puts("-1");
            continue;
        }
        for (int a : res) {
            cout << a << ' ';
        }
        cout << "\n";
    }

    return 0;
}