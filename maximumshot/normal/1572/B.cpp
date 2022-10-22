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

pair<bool, vector<int>> fast(int n, vector<int> a) {
    {
        int xr = 0;
        for (auto x : a)
            xr ^= x;
        if (xr)
            return {false, {}};
    }
    if (*max_element(a.begin(), a.end()) == 0)
        return {true, {}};
    int pos = -1;
    vector<int> seq;
    auto do_op = [&](int i) {
        int x = a[i] ^ a[i + 1] ^ a[i + 2];
        a[i] = a[i + 1] = a[i + 2] = x;
        seq.push_back(i + 1);
    };
    for (int pr = 0, i = 0; i < n; i++) {
        if (a[i]) {
            pr ^= 1;
        } else {
            if (pr == 0) {
                pos = i;
                break;
            } else if (a[i - 1] && a[i + 1]) {
                do_op(i - 1);
                pos = i;
                break;
            }
        }
    }
    if (pos == -1) {
        vector<int> prv(n, -1), nxt(n, n);
        for (int i = 0; i < n; i++) {
            if (a[i]) prv[i] = i;
            else prv[i] = prv[i - 1];
        }
        for (int i = n - 1; i >= 0; i--) {
            if (a[i]) nxt[i] = i;
            else nxt[i] = nxt[i + 1];
        }
        for (int i = 0; i < n; i++) {
            if (!a[i]) {
                int l = prv[i];
                int r = nxt[i];
                int len = r - l - 1;
                if (len % 2) {
                    pos = i;
                    while (l < r - 2) {
                        do_op(l);
                        l += 2;
                    }
                    do_op(l);
                    r = l - 1;
                    l = prv[i];
                    while (l < r) {
                        do_op(r - 1);
                        r -= 2;
                    }
                    break;
                }
            }
        }
    }
    if (pos == -1)
        return {false, {}};
    vector<int> le, ri;
    for (int i = 0; i < n; i++) {
        if (a[i]) {
            if (i < pos) le.push_back(i);
            else ri.push_back(i);
        }
    }
    assert((int) le.size() % 2 == 0);
    assert((int) ri.size() % 2 == 0);
    for (int i = (int) le.size() - 1; i > 0; i -= 2) {
        int x = le[i - 1];
        int y = le[i];
        while (y > x + 2) {
            do_op(y - 2);
            do_op(y - 1);
            y -= 2;
        }
        do_op(x);
    }
    for (int i = 0; i < (int) ri.size(); i += 2) {
        int x = ri[i];
        int y = ri[i + 1];
        while (x < y - 2) {
            do_op(x);
            do_op(x - 1);
            x += 2;
        }
        if (x + 1 == y) do_op(x - 1);
        else do_op(x);
    }
    assert(*max_element(a.begin(), a.end()) == 0);
    return {true, seq};
}

pair<bool, vector<int>> slow(int n, vector<int> a) {
    vector<int> dp(1 << n, inf);
    int mask = 0;
    for (int i = 0; i < n; i++) {
        if (a[i])
            mask |= 1 << i;
    }
    dp[mask] = 0;
    queue<int> q;
    q.push(mask);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i + 2 < n; i++) {
            int to = v;
            int x = (to >> i) & 1;
            int y = (to >> (i + 1)) & 1;
            int z = (to >> (i + 2)) & 1;
            int value = x ^ y ^ z;
            to &= ~(1 << i);
            to &= ~(1 << (i + 1));
            to &= ~(1 << (i + 2));
            to |= value << i;
            to |= value << (i + 1);
            to |= value << (i + 2);
            if (dp[to] > dp[v] + 1) {
                dp[to] = dp[v] + 1;
                q.push(to);
            }
        }
    }
    return {dp[0] < inf, {}};
}

void work() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        auto [fl, seq] = fast(n, a);
        if (fl) {
            cout << "YES\n";
            cout << (int) seq.size() << "\n";
            for (auto x : seq)
                cout << x << " ";
            cout << "\n";
        } else {
            cout << "NO\n";
        }
    }
}

void test() {
    mt19937 rnd(42);
    const int MAXN = 20;
    while (1) {
        int n = rnd() % MAXN + 3;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            a[i] = rnd() % 2;
        auto fs = fast(n, a);
        assert((int) fs.second.size() <= n);
        auto sl = slow(n, a);
        if (fs.first == sl.first) {
            cout << "OK(" << fs.first << ")" << endl;
        } else {
            cout << "WA\n";
            cout << "exp = " << sl.first << "\n";
            cout << "fnd = " << fs.first << "\n";
            cout << n << "\n";
            for (int i = 0; i < n; i++) {
                cout << a[i] << " ";
            }
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