#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

ll slow(int n, vector<ll> S) {
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        while (S[i] > 1) {
            res++;
            for (ll k, j = i; j <= n; k = j + S[j], S[j] = max(1ll, S[j] - 1), j = k);
        }
    }
    return res;
}

ll fast(int n, vector<ll> S) {
    vector<ll> pu(n + 1);
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        // 0 <= k <= S[i] - 2
        if (S[i] - 2 >= 0) {
            // 0 <= k + 1 <= pu[i]
            res += max(0ll, S[i] - 2 - pu[i] + 1);
            for (ll k = S[i] - 2; k >= 0; k--) {
                ll j = i + S[i] - k;
                if (j > n)
                    break;
                pu[j]++;
            }
            ll tmp = max(0ll, min(S[i] - 2, pu[i] - 1) + 1);
            pu[i] = max(0ll, pu[i] - tmp);
        }
        if (pu[i] > 0 && i < n)
            pu[i + 1] += pu[i];
    }
    return res;
}

void work() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<ll> S(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> S[i];
        ll fs = fast(n, S);
        cout << fs << "\n";
    }
}

void test() {
    mt19937 rnd(42);
    const int N = 100;
    const int X = 1e4;
    while (1) {
        int n = rnd() % N + 1;
        vector<ll> S(n + 1);
        for (int i = 1; i <= n; i++)
            S[i] = rnd() % X + 1;
        ll fs = fast(n, S);
        ll sl = slow(n, S);
        if (fs == sl) {
            cout << "OK(" << fs << ")" << endl;
        } else {
            cout << "WA\n";
            cout << "exp = " << sl << "\n";
            cout << "fnd = " << fs << "\n";
            cout << n << "\n";
            for (int i = 1; i <= n; i++)
                cout << S[i] << " ";
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