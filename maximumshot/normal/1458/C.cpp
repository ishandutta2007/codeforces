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

void read(int& n, int& m, vector<vector<int>>& a, string& s) {
    cin >> n >> m;
    a.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    cin >> s;
}

vector<int> inv(const vector<int>& p) {
    vector<int> q(p.size());
    for (int i = 0; i < (int) p.size(); i++)
        q[p[i]] = i;
    return q;
}

vector<int> mul(const vector<int>& p, const vector<int>& q) {
    vector<int> res(p.size());
    for (int x = 0; x < (int) p.size(); x++)
        res[x] = p[q[x]];
    return res;
}

vector<vector<int>> transpose(const vector<vector<int>>& a) {
    vector<vector<int>> b = a;
    int n = (int) a.size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            b[j][i] = a[i][j];
    return b;
}

vector<vector<int>> fast(int n, int m, vector<vector<int>> a, string s) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j]--;
    vector<int> d(3), p = {0, 1, 2};
    for (char c : s) {
        if (c == 'L')
            d[p[1]]--;
        else if (c == 'R')
            d[p[1]]++;
        else if (c == 'U')
            d[p[0]]--;
        else if (c == 'D')
            d[p[0]]++;
        else if (c == 'I')
            swap(p[1], p[2]);
        else if (c == 'C')
            swap(p[0], p[2]);
    }
    auto b = a;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            vector<int> v = {i, j, a[i][j]}, u = v;
            for (int q = 0; q < 3; q++)
                u[q] = (v[p[q]] + d[p[q]] % n + n) % n;
            b[u[0]][u[1]] = u[2] + 1;
        }
    }
    return b;
}

void work() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        vector<vector<int>> a;
        string s;
        read(n, m, a, s);
        vector<vector<int>> fs = fast(n, m, a, s);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << fs[i][j] << " ";
            cout << "\n";
        }
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