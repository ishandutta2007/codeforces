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
    res.resize(n);
    if (ptr == (int) s.size()) {
        for (int i = 0; i < n; i++)
            res[a[i]] = i + 1;
    }
    return true;
}

string gen(int n, mt19937& rnd) {
    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = i;
    shuffle(a.begin(), a.end(), rnd);
    vector<int> b(n + 10);
    string res;
    function<void(int, int)> rec = [&](int l, int r) {
        if (r - l <= 1)
            return;
        int m = (l + r) >> 1;
        rec(l, m);
        rec(m, r);
        int i = l, j = m;
        int ptr = 0;
        while (i < m && j < r) {
            if (a[i] < a[j]) {
                res.push_back('0');
                b[ptr++] = a[i++];
            } else {
                res.push_back('1');
                b[ptr++] = a[j++];
            }
        }
        while (i < m) b[ptr++] = a[i++];
        while (j < r) b[ptr++] = a[j++];
        for (int i = l; i < r; i++)
            a[i] = b[i - l];
    };
    rec(0, n);
    return res;
}

vector<int> fast(string s) {
    vector<int> res;
    int bl = 1, br = (int) s.size() + 10, bm;
    while (br - bl > 1) {
        bm = (bl + br) >> 1;
        if (check(s, bm, res)) bl = bm;
        else br = bm;
    }
    check(s, bl, res);
    return res;
}

void test() {
    mt19937 rnd(42);

    int n = 100000;

    string s = gen(n, rnd);

    cout << s << "\n";

    vector<int> res = fast(s);

    cout << "\n";
    cout << (int) res.size() << "\n";
    for (auto x : res)
        cout << x << " ";
    cout << "\n";
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
    // test();
    
    return 0;
}