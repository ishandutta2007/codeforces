
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

bool ask1(int a, int b) {
    cout << 1 << ' ' << a-1 << ' ' << b-1 << endl;
    int v;
    cin >> v;
    if(v == -1) exit(0);
    return v;
}
bool ask2(int a, vi &v) {
    cout << 2 << ' ' << a-1 << ' ' << sz(v);
    for(int x : v) cout << ' ' << x-1;
    cout << endl;
    int ans;
    cin >> ans;
    if(ans == -1) exit(0);
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vi ve;
    rep(i, 1, n + 1) {
        int L = 0, R = sz(ve);
        while(L < R) {
            int m = (L + R) / 2;
            if(ask1(ve[m], i)) { // :clown:
                L = m + 1;
            }else {
                R = m;
            }
        }
        ve.insert(ve.begin() + L, i);
    }
    vector<vi> st;
    vi Q;
    vi M;
    for(int i : ve) {
        M.clear();
        M.push_back(i);
        while(!st.empty()) {
            Q.clear();
            for(vi &ve : st) Q.insert(Q.end(), all(ve));
            if(ask2(i, Q)) {
                M.insert(M.end(), all(st.back()));
                st.pop_back();
            }else break;
        }
        st.push_back(M);
    }
    vi comp(n + 1);
    rep(i, 0, sz(st)) {
        for(int j : st[i]) {
            comp[j] = i;
        }
    }
    cout << 3 << '\n';
    rep(i, 1, n + 1) {
        rep(j, 1, n + 1) {
            cout << (comp[i] <= comp[j] ? 1 : 0);
        }
        cout << endl;
    }
    int kys;
    cin >> kys;
    if(kys == -1) exit(0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}