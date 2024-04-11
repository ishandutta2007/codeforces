
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
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

const int N = 1005;
int t, n, k, c[N], pass[N];
vi s[N];
bool covid[N];

int query2(vi &ve) {
    cout << "? " << sz(ve);
    for(int x : ve) {
        cout << ' ' << x;
    }
    cout << endl;
    int mx;
    cin >> mx;
    if(mx == -1) exit(0);
    return mx;
}

// query range of subsets
int query(int l, int r) {
    vi ve;
    rep(i, l, r + 1) {
        for(int x : s[i]) {
            ve.push_back(x);
        }
    }
    return query2(ve);
}
void solve() {
    cout << "!";
    rep(i, 0, k) {
        cout << ' ' << pass[i];
    }
    cout << endl;
    string str;
    cin >> str;
    if(str == "Incorrect") exit(0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> k;
        fill(pass, pass + k + 1, 0);
        fill(covid + 1, covid + n + 1, false);
        rep(i, 0, k) {
            cin >> c[i];
            s[i].assign(c[i], 0);
            rep(j, 0, c[i]) {
                cin >> s[i][j];
                covid[s[i][j]] = true;
            }
        }
        s[k].clear();
        rep(i, 1, n + 1) {
            if(!covid[i]) {
                s[k].push_back(i);
            }
        }
        int L = 0, R = k;
        int mx = query(L, R);
        while(L < R) {
            int M = (L + R) / 2;
            int q = query(L, M);
            if(q < mx) {
                fill(pass + L, pass + M + 1, mx);
                L = M + 1;
            }else {
                fill(pass + M + 1, pass + R + 1, mx);
                R = M;
            }
        }
        // query everything but L
        vi ve;
        rep(i, 0, k + 1) {
            if(i != L) {
                for(int x : s[i]) {
                    ve.push_back(x);
                }
            }
        }
        pass[L] = query2(ve);
        solve();
    }
}