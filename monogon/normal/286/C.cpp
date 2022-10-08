
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;

// read the sequence backwards.
// some of them we are certain they are open brackets.
// otherwise, greedily make it close bracket if it can be made one

const int N = 1e6 + 5;
int n, t, p[N], q;
bool b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 1, n + 1) cin >> p[i];
    cin >> t;
    rep(i, 1, t + 1) {
        cin >> q;
        b[q] = true;
    }
    stack<int> st;
    for(int i = n; i >= 1; i--) {
        if(b[i]) {
            st.push(p[i]);
        }else if(!st.empty() && st.top() == p[i]) {
            st.pop();
        }else {
            b[i] = true;
            st.push(p[i]);
        }
    }
    if(st.empty()) {
        cout << "YES\n";
        rep(i, 1, n + 1) {
            cout << (b[i] ? -p[i] : p[i]) << ' ';
        }
        cout << '\n';
    }else {
        cout << "NO\n";
    }
}