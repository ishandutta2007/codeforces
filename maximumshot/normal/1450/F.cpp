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

int slow(int n, vector<int> a) {
    vector<int> p(n);
    for (int i = 1; i <= n; i++)
        p[i - 1] = i;
    int res = inf;
    do {
        int tmp = 0, ok = 1;
        for (int i = 1; i < n; i++) {
            if (a[p[i]] == a[p[i - 1]]) {
                ok = 0;
                break;
            }
            tmp += abs(p[i - 1] - p[i]) > 1;
        }
        if (ok)
            res = min(res, tmp);
    } while (next_permutation(p.begin(), p.end()));
    if (res == inf)
        res = -1;
    return res;
}

int fast(int n, vector<int> a) {
    vector<int> cnt(n + 1);
    for (int i = 1; i <= n; i++)
        cnt[a[i]]++;
    for (int x = 1; x <= n; x++) {
        if (cnt[x] > (n + 1) / 2)
            return -1;
    }
    cnt.assign(n + 1, 0);
    int res = 0, k = 0;
    for (int i = 1; i <= n; ) {
        int j = i;
        while (j < n && a[j] != a[j + 1])
            j++;
        // [i, j]
        cnt[a[i]]++;
        cnt[a[j]]++;
        i = j + 1;
        k++;
    }
    k--;
    for (int i = 1; i <= n; i++)
        res = max(res, k + max(0, cnt[i] - 2 - k));
    return res;
}

void work() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        int fs = fast(n, a);

        cout << fs << "\n";
    }
}

void test() {
    const int N = 10;
    mt19937 rnd(42);
    while (1) {
        int n = rnd() % N + 1;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            a[i] = rnd() % n + 1;

        int sl = slow(n, a);
        int fs = fast(n, a);

        if (fs == sl) {
            cout << "OK(" << fs << ")" << endl;
        } else {
            cout << "WA\n";
            cout << "exp = " << sl << "\n";
            cout << "fnd = " << fs << "\n";
            cout << endl;
            cout << n << "\n";
            for (int i = 1; i <= n; i++)
                cout << a[i] << " ";
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