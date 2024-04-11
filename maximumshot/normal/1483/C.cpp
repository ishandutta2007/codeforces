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

struct DSU {
    int n = 0;
    vector<pii> mn;
    vector<int> p;

    DSU(vector<int> h, vector<int> b) {
        n = (int) h.size();
        p.resize(n);
        mn.resize(n);
        for (int i = 0; i < n; i++) {
            p[i] = i;
            mn[i] = {h[i], b[i]};
        }
    }

    int find(int x) {
        return x == p[x] ? x : p[x] = find(p[x]);
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        p[y] = x;
        mn[x] = min(mn[x], mn[y]);
    }

    ll delta(int i, int j) {
        i = find(i);
        j = find(j);
        return -mn[i].second - mn[j].second + min(mn[i], mn[j]).second;
    }
};

ll fast(int n, vector<int> h, vector<int> b) {
    vector<int> st;
    vector<ll> dp(n + 1, -inf64), mem(n + 1, -inf64);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        mem[i + 1] = dp[i];
        while (!st.empty() && h[st.back()] > h[i]) {
            mem[i + 1] = max(mem[i + 1], mem[st.back() + 1]);
            st.pop_back();
        }
        dp[i + 1] = mem[i + 1] + b[i];
        if (!st.empty()) {
            int j = st.back();
            dp[i + 1] = max(dp[i + 1], dp[j + 1]);
        }
        st.push_back(i);
    }
    return dp[n];
}

ll slow(int n, vector<int> h, vector<int> b) {
    vector<ll> dp(n + 1, -inf64);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int mn = -1;
        for (int j = i; j >= 1; j--) {
            if (mn == -1 || h[mn] > h[j - 1])
                mn = j - 1;
            dp[i] = max(dp[i], dp[j - 1] + b[mn]);
        }
    }
    return dp[n];
}

void work() {
    int n;
    cin >> n;
    vector<int> h(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    ll fs = fast(n, h, b);
    cout << fs << "\n";
}

void test() {
    mt19937 rnd(42);
    const int N = 30;
    while (1) {
        int n = rnd() % N + 1;
        vector<int> h(n), b(n);
        for (int i = 0; i < n; i++)
            h[i] = i + 1;
        shuffle(h.begin(), h.end(), rnd);
        for (int i = 0; i < n; i++)
            b[i] = rnd() % (2 * N + 1) - N;
        ll fs = fast(n, h, b);
        ll sl = slow(n, h, b);
        if (fs == sl) {
            cout << "OK(" << fs << ")" << endl;
        } else {
            cout << "WA\n";
            cout << "exp = " << sl << "\n";
            cout << "fnd = " << fs << "\n";
            cout << n << "\n";
            for (auto x : h)
                cout << x << " ";
            cout << "\n";
            for (auto x : b)
                cout << x << " ";
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