
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

const int N = 105;
int n, m;
string s[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    rep(i, 0, n) cin >> s[i];
    rep(i, 0, n) rep(j, 0, m) {
        cout << (s[i][j] == '-' ? '-' : (i + j) % 2 ? 'B' : 'W');
        if(j == m - 1) cout << '\n';
    }
}