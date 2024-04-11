
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
int n;
string s[N];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

inline bool inbounds(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 0, n) cin >> s[i];
    rep(i, 0, n) rep(j, 0, n) {
        int e = 0;
        rep(d, 0, 4) {
            int xx = i + dx[d];
            int yy = j + dy[d];
            e ^= (inbounds(xx, yy) && s[xx][yy] == 'o');
        }
        if(e == 1) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
}