
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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vi> a(n, vi(n, -1));
    rep(i, 0, n) rep(j, 0, n) {
        cin >> a[i][j];
        a[i][j]--;
    }
    string s;
    cin >> s;

    array<int, 3> rot = {0, 0, 0};
    string p = "ijk";
    for(char c : s) {
        rot[1] += (c == 'R') - (c == 'L');
        rot[0] += (c == 'D') - (c == 'U');
        if(c == 'I') {
            swap(p[1], p[2]);
            swap(rot[1], rot[2]);
        }
        if(c == 'C') {
            swap(p[0], p[2]);
            swap(rot[0], rot[2]);
        }
    }

    vector<vi> b(n, vi(n, -1));
    rep(i, 0, n) rep(j, 0, n) {
        int k = a[i][j];
        array<int, 3> hmm = {i, j, k};
        rep(l, 0, 3) {
            hmm[l] = (((p[l] == 'i' ? i : p[l] == 'j' ? j : k) + rot[l]) % n + n) % n;
        }
        b[hmm[0]][hmm[1]] = hmm[2];
    }

    rep(i, 0, n) {
        rep(j, 0, n) {
            cout << b[i][j] + 1 << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        solve();
    }
}