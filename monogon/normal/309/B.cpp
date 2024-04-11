
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

// solve for c = 1 using two-pointers.
// get c = 2 by combining c = 1 answers, and so on.
// similar to repeated squaring to compute a^b mod m
// Then we can get answer by bitmasks
// O(n log c)

const int N = 1e6 + 5;
int n, r, c, len[N], ans[N][20], opt[N];
string s[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> r >> c;
    rep(i, 0, n) {
        cin >> s[i];
        len[i] = s[i].length();
    }
    int j = 0, L = -1;
    ans[n][0] = n;
    rep(i, 0, n) {
        while(j < n && L + len[j] + 1 <= c) {
            L += len[j] + 1;
            j++;
        }
        ans[i][0] = j;
        if(r & 1) {
            opt[i] = j;
        }else {
            opt[i] = i;
        }
        L -= len[i] + 1;
    }
    rep(l, 1, 20) {
        rep(i, 0, n) {
            ans[i][l] = ans[ans[i][l - 1]][l - 1];
        }
        ans[n][l] = n;
        if((r >> l) & 1) {
            rep(i, 0, n) {
                opt[i] = ans[opt[i]][l];
            }
        }
    }
    int mx = -1, idx = 0;
    rep(i, 0, n) {
        if(opt[i] - i > mx) {
            mx = opt[i] - i;
            idx = i;
        }
    }
    rep(i, 0, r) {
        rep(j, idx, ans[idx][0]) {
            cout << s[j];
            if(j < ans[idx][0] - 1) cout << ' ';
        }
        cout << '\n';
        idx = ans[idx][0];
        if(ans[idx][0] == idx) break;
    }
}