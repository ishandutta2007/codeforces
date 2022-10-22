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

bool check(const string& s, int n, vector<int>& res) {
    res.clear();
    vector<int> b(n), a(n);
    for (int i = 0; i < n; i++) a[i] = i;
    int ptr = 0;
    int ok = 1;
    function<bool(int, int)> rec = [&](int l, int r) {
        if (r - l <= 1)
            return true;
        int m = (l + r) >> 1;
        if (!rec(l, m)) return false;
        if (!rec(m, r)) return false;
        int i = l;
        int j = m;
        int cur = 0;
        while (i < m && j < r) {
            if (ptr >= (int) s.size()) return false;
            if (s[ptr] == '0') {
                b[cur++] = a[i++];
            } else {
                b[cur++] = a[j++];
            }
            ptr++;
        }
        while (i < m) b[cur++] = a[i++];
        while (j < r) b[cur++] = a[j++];
        for (int i = l; i < r; i++)
            a[i] = b[i - l];
        return true;
    };
    if (!rec(0, n)) return false;
    if (ptr != (int) s.size()) return false;
    res.resize(n);
    for (int i = 0; i < n; i++)
        res[a[i]] = i + 1;
    return true;
}

vector<int> fast(string s) {
    int n = 1;
    vector<int> res;
    while (!check(s, n, res)) n++;
    return res;
}

void work() {
    string s;
    cin >> s;

    vector<int> res = fast(s);

    cout << (int) res.size() << "\n";
    for (auto x : res)
        cout << x << " ";
    cout << "\n";
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