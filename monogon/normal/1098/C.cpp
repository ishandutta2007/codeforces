
#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

// sum of depths
// 1 + 2 + 3 + ... + n <= s for a path
// a_1 (1) + a_2 (2) + a_3 (3) + ...
// a_i * k >= a_{i+1}
// a_1 = 1
// we can check if it's possible with k = 1: n (n + 1) / 2 == s
// otherwise, we should split into two subtrees
// n1 + n2 + 1 = n
// 1 + n1 + n2 + f1 + f2 = s
// n + f1 + f2 = s
// f1 + f2 = s - n
// can we always split it up like this?
// NO.
// find minimum k so that 1 + 2 k + 3 k^2 + 4 k^3 + ... (up to n nodes) <= s
// use binary search
// now that we've fixed k, let's make the tree as wide as possible, and try to increase by 1 at a time
// 

int n;
ll s;

const int N = 1e5 + 5;
map<ll, ll> ma;
int t = 1, par[N];

void dfs(int x, int dep, int k) {
    ma[dep]--;
    for(int i = 0; i < k && ma[dep + 1] > 0; i++) {
        t++;
        par[t] = x;
        dfs(t, dep + 1, k);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s;
    if(1LL * n * (n + 1) < s) {
        cout << "No\n";
        return 0;
    }
    ll L = 1, R = s;
    while(L < R) {
        ll M = L + (R - L) / 2;
        ll p = 1, cnt = 1;
        ll sum = 0;
        int idx = 1;
        rep(i, 0, n) {
            sum += idx;
            cnt--;
            if(cnt == 0) {
                p *= M;
                cnt = p;
                idx++;
            }
        }
        if(sum <= s) {
            R = M;
        }else {
            L = M + 1;
        }
    }
    if(L == 1) {
        if(s == 1LL * n * (n + 1) / 2) {
            cout << "Yes\n";
            rep(i, 2, n + 1) {
                cout << i - 1 << ' ';
            }
            cout << '\n';
        }else {
            cout << "No\n";
        }
        return 0;
    }
    ll p = 1, cnt = 1, sum = 0;
    int idx = 1;
    rep(i, 0, n) {
        sum += idx;
        ma[idx]++;
        cnt--;
        if(cnt == 0) {
            p *= L;
            cnt = p;
            idx++;
        }
    }
    if(sum > s) {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    set<int> leaves;
    auto check = [&](int i) {
        if(ma[i] > 0 && (ma[i] - 1) * L > ma[i + 1]) {
            leaves.insert(i);
        }else {
            leaves.erase(i);
        }
    };
    rep(i, 1, idx + 1) {
        check(i);
    }
    while(sum < s) {
        if(leaves.empty()) break;
        int i = *leaves.begin(), j = *prev(leaves.end());
        if(sum + j - i + 1 > s) break;
        sum += j - i + 1;
        ma[i]--;
        ma[j + 1]++;
        check(i - 1);
        check(i);
        check(j);
        check(j + 1);
    }
    idx = prev(ma.end())->first;
    while(sum < s) {
        if(ma[idx] > 0 && (ma[idx] - 1) * L >= (1 + ma[idx + 1])) {
            ma[idx]--;
            ma[idx + 1]++;
            idx++;
            sum++;
        }else {
            idx--;
        }
    }
    dfs(1, 1, L);
    rep(i, 2, n + 1) {
        cout << par[i] << ' ';
    }
    cout << '\n';
}