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

ll fast(vector<int> a) {
    int n = (int) a.size();

    vector<int> cnt(20);

    for (int x : a)
        for (int j = 0; j < 20; j++)
            if ((1 << j) & x)
                cnt[j]++;

    vector<int> A(n);
    for (int j = 0; j < 20; j++)
        for (int i = 0; i < cnt[j]; i++)
            A[n - 1 - i] |= (1 << j);

    ll res = 0;
    for (int i = 0; i < n; i++)
        res += 1ll * A[i] * A[i];

    return res;
}

ll slow(vector<int> a) {
    int n = (int) a.size();
    ll mx = 0;

    sort(a.begin(), a.end());

    do {
        vector<int> A(n), B(n);
        for (int cur = 0, i = 0; i < n; i++) {
            cur |= a[i];
            A[i] = cur;
        }

        for (int cur = (1 << 20) - 1, i = n - 1; i >= 0; i--) {
            B[i] = cur;
            cur &= a[i];
        }

        ll res = 0;
        for (int i = 0; i < n; i++) {
            int x = A[i] & B[i];
            res += 1ll * x * x;
        }

        mx = max(mx, res);

    } while (next_permutation(a.begin(), a.end()));

    return mx;
}

vector<int> read() {
    int n;

    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    return a;
}

mt19937 rnd(42);

vector<int> gen(int n, int mx) {
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = rnd() % mx;
    }
    return a;
}

void test() {
    int n = 10;
    int mx = 16;
    while (1) {
        vector<int> a = gen(n, mx);
        ll fs = fast(a);
        ll sl = slow(a);
        if (fs == sl) {
            cout << "OK(" << fs << " == " << sl << ")\n";
            continue;
        }
        cout << "WA\n";
        cout << "exp = " << sl << "\n";
        cout << "fnd = " << fs << "\n";
        cout << "\n";
        cout << (int) a.size() << "\n";
        for (int x : a)
            cout << x << " ";
        cout << "\n";
        break;
    }
}

void work() {
    cout << fast(read()) << "\n";
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

//    test();
    work();

    return 0;
}