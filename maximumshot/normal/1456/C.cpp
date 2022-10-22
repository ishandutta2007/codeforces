#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

ll dp(int n, int k, vector<int> c) {
    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, -inf64));
    dp[0][0] = 0;
    for (int u = 0; u < k; u++) {
        for (int i = 0; i < n; i++) {
            ll cur_score = 0;
            ll total_score = 0;
            for (int j = i + 1; j <= n; j++) {
                total_score += cur_score;
                cur_score += c[j];
                dp[j][u + 1] = max(dp[j][u + 1], dp[i][u] + total_score);
            }
        }
    }
    ll res = -inf64;
    for (int u = 0; u <= k; u++) {
        res = max(res, dp[n][u]);
    }
    return res;
}

ll fast(int n, int k, vector<int> c) {
    k++;
    sort(c.begin() + 1, c.end());
    vector<ll> S(k);
    vector<vector<int>> a(k);
    set<pair<ll, int>> q;
    for (int j = 0; j < k; j++)
        q.insert({S[j], j});
    for (int i = n; i >= 1; i--) {
        int x = c[i];
        int bj = (--q.end())->second;
        q.erase(--q.end());
        a[bj].push_back(x);
        S[bj] += x;
        q.insert({S[bj], bj});
    }
    ll res = 0;
    for (int j = 0; j < k; j++) {
        ll cur = 0;
        for (int x : a[j]) {
            res += cur;
            cur += x;
        }
    }
    return res;
}

ll slow(int n, int k, vector<int> c) {
    k++;
    vector<int> p(n), cc = c;
    for (int i = 0; i < n; i++)
        p[i] = i;
    ll res = -inf64;
    do {
        for (int i = 0; i < n; i++)
            cc[p[i] + 1] = c[i + 1];
        for (int i = 1; i <= n; i++)
            cout << cc[i] << " ";
        ll tmp = dp(n, k, cc);
        cout << " : " << tmp << "\n";
        res = max(res, tmp);
    } while (next_permutation(p.begin(), p.end()));
    return res;
}

void work() {
    int n, k;
    cin >> n >> k;
    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    ll fs = fast(n, k, c);
    cout << fs << "\n";
}

void test() {
    mt19937 rnd(42);
    const int N = 8;
    const int X = inf;
    while (1) {
        int n, k;
        n = rnd() % N + 1;
//        k = rnd() % N;
        k = 1;
        vector<int> c(n + 1);
        for (int i = 1; i <= n; i++)
            c[i] = rnd() % (2 * X + 1) - X;
        ll sl = slow(n, k, c);
        ll fs = fast(n, k, c);
        if (sl == fs) {
            cout << "OK(" << fs << ")" << endl;
        } else {
            cout << "WA\n";
            cout << "exp = " << sl << "\n";
            cout << "fnd = " << fs << "\n\n";
            cout << n << " " << k << "\n";
            for (int i = 1; i <= n; i++)
                cout << c[i] << " ";
            cout << "\n";
            break;
        }
    }
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();
//    test();

    return 0;
}