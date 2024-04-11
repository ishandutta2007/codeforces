
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vi> p(n + 1, vi(n + 1, 0));
    rep(i, 1, n + 1) {
        cin >> p[i][i];
    }
    rep(d, 0, n) {
        int besti = 1;
        rep(i, 1, n - d + 1) {
            if(p[i + d][i] < p[besti + d][besti]) besti = i;
        }
        rep(i, 1, besti) p[i + d + 1][i] = p[i + d][i];
        rep(i, besti + 1, n - d + 1) p[i + d][i - 1] = p[i + d][i];
    }

    rep(i, 1, n + 1) {
        rep(j, 1, i + 1) {
            cout << p[i][j] << ' ';
        }
        cout << '\n';
    }
}