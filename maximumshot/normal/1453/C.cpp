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

void read(int& n, vector<vector<int>>& a) {
    cin >> n;
    a.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
            a[i][j] = s[j] - '0';
    }
}

vector<vector<int>> flip(const vector<vector<int>>& a, int n) {
    vector<vector<int>> b = a;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            b[i][j] = a[i][n - 1 - j];
    return b;
}

vector<vector<int>> rotate(const vector<vector<int>>& a, int n) {
    vector<vector<int>> b = a;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            b[i][j] = a[j][n - 1 - i];
    return b;
}

vector<int> fast(int n, vector<vector<int>> a) {
    vector<int> res(10);
    for (int flip_it = 0; flip_it < 2; flip_it++, a = flip(a, n)) {
        for (int rotate_it = 0; rotate_it < 4; rotate_it++, a = rotate(a, n)) {
            vector<int> mn(10, inf);
            for (int i = 0; i < n; i++) {
                vector<int> le(10, inf), ri(10, -inf);
                for (int j = 0; j < n; j++) {
                    int x = a[i][j];
                    le[x] = min(le[x], j);
                    ri[x] = max(ri[x], j);
                    mn[x] = min(mn[x], i);
                }
                for (int x = 0; x < 10; x++) {
                    if (le[x] <= ri[x]) {
                        res[x] = max(res[x], (ri[x] - le[x]) * i);
                        res[x] = max(res[x], (n - 1 - le[x]) * (i - mn[x]));
                        res[x] = max(res[x], ri[x] * (i - mn[x]));
                    }
                }
            }
        }
    }
    return res;
}

void work() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        vector<vector<int>> a;
        read(n, a);
        vector<int> fs = fast(n, a);
        for (int x : fs)
            cout << x << " ";
        cout << "\n";
    }
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();

    return 0;
}