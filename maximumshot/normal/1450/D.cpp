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

string fast(int n, vector<int> a) {
    string res(n, '0');
    vector<int> used(n + 1);
    int cnt = 0, mx = 0, ptr = 1;
    multiset<int> q;
    for (int i = 1; i <= n; i++)
        q.insert(a[i]);
    for (int l = 1, r = n; l <= r;) {
        int gap = r - l + 1;
        int m = n - gap + 1;
        int k = gap;
        if (cnt == m - 1 && mx == m - 1 && *q.begin() == m)
            res[k - 1] = '1';
        if (a[l] < a[r]) {
            if (used[a[l]] || a[l] != ptr)
                break;
            used[a[l]] = 1;
            mx = max(mx, a[l]);
            q.erase(q.lower_bound(a[l]));
            l++;
        } else {
            if (used[a[r]] || a[r] != ptr)
                break;
            used[a[r]] = 1;
            mx = max(mx, a[r]);
            q.erase(q.lower_bound(a[r]));
            r--;
        }
        ptr++;
        cnt++;
    }
    used.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
        used[a[i]] = 1;
    if (!count(used.begin() + 1, used.end(), 0))
        res[0] = '1';
    return res;
}

string slow(int n, vector<int> a) {
    string res;
    for (int k = 1; k <= n; k++) {
        int m = n - k + 1;
        vector<int> used(m + 1);
        int ok = 1;
        for (int i = 1; i + k - 1 <= n; i++) {
            int mn = inf;
            for (int j = 0; j < k; j++)
                mn = min(mn, a[i + j]);
            if (mn > m || used[mn]) {
                ok = 0;
                break;
            }
            used[mn] = 1;
        }
        res.push_back(ok + '0');
    }
    return res;
}

void work() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        string fs = fast(n, a);

        cout << fs << "\n";
    }
}

void test() {
    const int N = 100;
    mt19937 rnd(42);
    while (1) {
        int n;
        n = rnd() % N + 1;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            a[i] = rnd() % n + 1;
        }

        string fs = fast(n, a);
        string sl = slow(n, a);

        if (fs == sl) {
            cout << "OK(" << fs << ")" << endl;
        } else {
            cout << "WA\n";
            cout << "exp = " << sl << "\n";
            cout << "fnd = " << fs << "\n";
            cout << endl;
            cout << n << endl;
            for (int i = 1; i <= n; i++)
                cout << a[i] << " ";
            cout << endl;
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