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

vector<int> slow(int n, int m, vector<int> p) {
    vector<int> res;
    for (int k = 0; k < n; k++) {
        vector<int> used(n + 1);
        int swp = n;
        for (int i = 1; i <= n; i++) {
            if (used[i])
                continue;
            for (int j = i; !used[j]; j = p[j])
                used[j] = 1;
            swp--;
        }
        if (swp <= m)
            res.push_back(k);
        vector<int> q = p;
        for (int i = 1; i <= n; i++) {
            if (i > 1) q[i - 1] = p[i];
            else q[n] = p[1];
        }
        p = q;
    }
    return res;
}

vector<int> fast(int n, int m, vector<int> p) {
    vector<int> used;
    vector<int> p0(n), q0(n);
    for (int i = 0; i < n; i++)
        p0[i] = p[i + 1] - 1, q0[p0[i]] = i;
    auto check = [&](int k) -> bool {
        used.assign(n, 0);
        int cnt = n;
        for (int i = 0; i < n; i++) {
            if (used[i])
                continue;
            cnt--;
            for (int j = i; !used[j]; j = p0[((j + k) % n + n) % n])
                used[j] = 1;
        }
        return cnt <= m;
    };
    vector<int> f(n);
    for (int i = 0; i < n; i++) {
        int k = q0[i] - i;
        k = (k % n + n) % n;
        f[k]++;
    }
    vector<int> res;
    for (int k = 0; k < n; k++) {
        if (f[k] >= n - 2 * m && check(k))
            res.push_back(k);
    }
    return res;
}

void test() {
    mt19937 rnd(42);
    const int MAXN = 10;
    while (1) {
        int n = rnd() % MAXN + 3;
        int m = rnd() % (n / 3 + 1);
        vector<int> p(n + 1);
        for (int i = 1; i <= n; i++) p[i] = i;
        shuffle(p.begin() + 1, p.end(), rnd);
        vector<int> fs = fast(n, m, p);
        vector<int> sl = fast(n, m, p);
        if (fs == sl) {
            cout << "OK( "; for (auto k : fs) cout << k << " "; cout << ")" << endl;
        } else {
            cout << "WA\n";
            cout << "exp = " << (int) sl.size() << " "; for (auto k : sl) cout << k << " "; cout << "\n";
            cout << "fnd = " << (int) fs.size() << " "; for (auto k : fs) cout << k << " "; cout << "\n";
            cout << 1 << "\n";
            cout << n << " " << m << "\n";
            for (int i = 1; i <= n; i++)
                cout << p[i] << " ";
            cout << "\n";
            break;
        }
    }
}

void work() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> p(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> p[i];
        vector<int> res = fast(n, m, p);
        cout << (int) res.size() << " "; for (auto k : res) cout << k << " "; cout << "\n";
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