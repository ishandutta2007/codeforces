#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 1e6 + 5;

map <pii, int> mp;
int n, m;

int query(int x, int y) {
    if (mp.count(make_pair(x, y))) return mp[make_pair(x, y)];
    cout << "? " << x << " " << y << endl;
    int ans; cin >> ans; mp[make_pair(x, y)] = ans; return ans;
}

vector <pii> solve(vector <int> a, vector <int> b) {
    // cout << "!!!" << endl;
    // for (auto i : a) fprintf(stderr, "%d ", i);
    // fprintf(stderr, "\n");
    // for (auto i : b) fprintf(stderr, "%d ", i);
    // fprintf(stderr, "\n");
    if (a.size() == 1) {
        int minn = 2e9, pos = -1;
        for (int i = 0; i < (int)b.size(); i++) {
            int val = query(a[0], b[i]);
            if (val < minn) {
                minn = val;
                pos = i;
            }
        }
        vector <pii> ans(1, make_pair(pos, minn));
        return ans;
    }
    if (a.size() >= b.size()) {
        vector <int> tmp;
        for (int i = 0; i < (int)a.size(); i += 2) tmp.push_back(a[i]);
        vector <pii> res = solve(tmp, b), ans;
        for (int i = 0; i < (int)a.size(); i++) {
            if (i % 2 == 0) ans.push_back(res[i / 2]);
            else {
                int l = res[i / 2].first, r = (int)b.size() - 1;
                if (i != (int)a.size() - 1) r = res[i / 2 + 1].first;
                int minn = 2e9, pos = -1;
                for (int j = l; j <= r; j++) {
                    int val = query(a[i], b[j]);
                    if (val < minn) {
                        minn = val;
                        pos = j;
                    }
                }
                ans.push_back(make_pair(pos, minn));
            }
        }
        return ans;
    } else {
        vector <int> st(1, b[0]);
        int top = 0;
        for (int i = 1; i < (int)b.size(); i++) {
            int cando = 1;
            while (st.size()) {
                int vl = query(a[top], st[top]);
                int vr = query(a[top], b[i]);
                if (vl <= vr) {
                    if (top == (int)a.size() - 1) cando = 0;
                    break;
                }
                st.pop_back(); --top;
            }
            if (cando) {
                st.push_back(b[i]);
                ++top;
            }
        }
        vector <pii> ans = solve(a, st);
        int pos = 0;
        for (int i = 0; i < (int)ans.size(); i++) {
            while (st[ans[i].first] > b[pos]) ++pos;
            ans[i].first = pos;
        }
        return ans;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    vector <int> a(n), b(m);
    for (int i = 0; i < n; i++) a[i] = i + 1;
    for (int i = 0; i < m; i++) b[i] = i + 1;
    vector <pii> ans = solve(a, b);
    int minn = 2e9;
    for (int i = 0; i < n; i++) minn = min(minn, ans[i].second);
    cout << "! " << minn << endl;
    return 0;
}