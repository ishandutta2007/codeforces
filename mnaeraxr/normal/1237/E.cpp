#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;
const int mod = 998244353;

const int maxn = 1000010;

pair<int64,pii> memo[maxn];

void add(int64 &a, int64 b){
    a += b;
    if (a >= mod)
        a -= mod;
}

pair<int64,pii> solve(int n){
    if (memo[n].first != -1)
        return memo[n];

    int l = (n - 1) / 2;
    int64 expected = -1;

    int64 odd = 0;
    int64 even = 0;

    for (int a = l; a >= 0; --a){
        int b = n - a - 1;

        auto cur_a = solve(a);
        auto cur_b = solve(b);

        int64 t = cur_a.first + cur_b.first + n - 1;

        if (expected == -1) expected = t;
        if (expected != t) break;

        // cout << n << " " << a << " " << b << " " << t << endl;

        if (a % 2 == 0) { // odd case
            add(odd, cur_a.second.second * cur_b.second.second % mod);
        } else {
            add(even, cur_a.second.first * cur_b.second.second % mod);
        }

        if (a == b) continue;

        if (b % 2 == 0){
            add(odd, cur_b.second.second * cur_a.second.second % mod);
        } else {
            add(even, cur_b.second.first * cur_a.second.second % mod);
        }
    }

    memo[n] = {expected, {odd, even}};
    return memo[n];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    vector<int> pattern;

    pattern.push_back(1);
    pattern.push_back(2);

    while (pattern.back() < 1000000) {
        int s = (int)pattern.size();
        int nxt;

        if (s % 4 == 2){
            nxt = pattern.back() * 2;
        } else if (s % 4 == 0) {
            nxt = pattern.back() * 2 - 1;
        } else {
            nxt = pattern.back() + 1;
        }

        // cout << nxt << endl;
        pattern.push_back(nxt);
    }

    int n; cin >> n;

    for (auto x : pattern){
        if (x == n){
            cout << 1 << endl;
            return 0;
        }
    }

    cout << 0 << endl;

    // for (int i = 0; i < maxn; ++i)
    //     memo[i].first = -1;

    // memo[0] = {0, {1, 1}};

    // for (int n = 1; n <= 10000; ++n){
    //     auto ans = solve(n);

    //     int cur = ans.second.first + ans.second.second;

    //     if (cur){
    //         cout << n << " " << cur << endl;
    //     }
    //     // cout << ans.second.first << " " << ans.second.second << endl;
    // }
    // exit(0);

    // int n; cin >> n;
    // auto ans = solve(n);

    // int64 cur = 0;

    // add(cur, ans.second.first);
    // add(cur, ans.second.second);
    // cout << cur << endl;

    return 0;
}