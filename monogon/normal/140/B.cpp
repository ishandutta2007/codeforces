
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

const int N = 305;
int n, a[N][N], p[N], t[N], pref[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    fill(pref, pref + n, n);
    rep(i, 0, n) rep(j, 0, n) {
        cin >> a[i][j];
        a[i][j]--;
    }
    rep(i, 0, n) {
        cin >> p[i];
        p[i]--;
    }
    rep(i, 0, n) {
        rep(j, 0, n) {
            if(a[i][j] != i) {
                int mn = n;
                rep(k, 0, n) {
                    if(p[k] == a[i][j] && a[i][j] < mn) {
                        t[i] = p[k];
                        goto endloop;
                    }
                    if(p[k] != i) mn = min(mn, p[k]);
                }
            }
        }
        endloop:;
        cout << t[i] + 1 << ' ';
    }
    cout << '\n';
}