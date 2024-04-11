
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

const int N = 2e5 + 5;
int t, n, m;
vi a[N];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool inside(int i, int j) {
    return 0 <= i && i < n && 0 <= j && j < m;
}

int neighbors(int i, int j) {
    int ans = 0;
    rep(d, 0, 4) {
        ans += inside(i + dx[d], j + dy[d]);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> m;
        bool flag = true;
        rep(i, 0, n) {
            a[i].assign(m, 0);
            rep(j, 0, m) {
                cin >> a[i][j];
                int x = neighbors(i, j);
                if(a[i][j] > x) flag = false;
                a[i][j] = x;
            }
        }
        if(flag) {
            cout << "YES\n";
            rep(i, 0, n) rep(j, 0, m) {
                cout << a[i][j] << ' ';
                if(j == m - 1) cout << '\n';
            }
        }else {
            cout << "NO\n";
        }
    }
}