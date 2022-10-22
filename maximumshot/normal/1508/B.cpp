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

ll pw2(int x) {
    return x > 61 ? 2 * inf64 : 1ll << x;
}

vector<int> slow(int n, ll k) {
    vector<int> perm(n);
    for (int i = 0; i < n; i++)
        perm[i] = i + 1;
    while (k > 1) {
        if (!next_permutation(perm.begin(), perm.end()))
            return {-1};
        int ok = 1;
        for (int i = 1; i < n; i++) {
            if (perm[i] < perm[i - 1] - 1) {
                ok = 0;
                break;
            }
        }
        if (ok)
            k--;
    }
    return perm;
}

vector<int> fast(int n, ll k) {
    if (pw2(n - 1) < k)
        return {-1};
    vector<int> p;
    for (int last = 0; last < n;) {
        int x = last + 1;
        while (x < n && pw2(n - x - 1) < k) {
            k -= pw2(n - x - 1);
            x++;
        }
        for (int q = x; q > last; q--)
            p.push_back(q);
        last = x;
    }
    return p;
}

void work() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        ll k;
        cin >> n >> k;
        vector<int> p = fast(n, k);
        for (auto x : p)
            cout << x << " ";
        cout << "\n";
    }
}

void test() {
    mt19937 rnd(42);
    const int MAXN = 5;
    const int MAXK = 40;
    while (1) {
        int n = rnd() % MAXN + 1;
        ll k = rnd() % MAXK + 1;
        auto fs = fast(n, k);
        auto sl = slow(n, k);
        if (fs == sl) {
            cout << "OK(" ; for (auto x : fs) cout << x << " "; cout << ")" << endl;
        } else {
            cout << "WA\n";
            cout << "exp = "; for (auto x : sl) cout << x << " "; cout << "\n";
            cout << "fnd = "; for (auto x : fs) cout << x << " "; cout << "\n";
            cout << n << " " << k << "\n";
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