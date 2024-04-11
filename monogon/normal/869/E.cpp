
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

const int N = 2505, M = 1e9 + 7;
int n, m, q;
ll bit[N][N];

void add(int x, int y, ll val) {
    for(int i = x; i <= n; i += i & -i) {
        for(int j = y; j <= m; j += j & -j) {
            bit[i][j] = (bit[i][j] + val) % M;
        }
    }
}
ll getsum(int x, int y) {
    ll s = 0;
    for(int i = x; i > 0; i -= i & -i) {
        for(int j = y; j > 0; j -= j & -j) {
            s = (s + bit[i][j]) % M;
        }
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> q;
    map<pair<int, int>, int> ma;
    ll c = 1;
    while(q--) {
        int ty, r1, c1, r2, c2;
        cin >> ty >> r1 >> c1 >> r2 >> c2;
        if(ty == 1) {
            ma[{r1, c1}] = c;
            add(r1, c1, c);
            add(r1, c2 + 1, -c);
            add(r2 + 1, c1, -c);
            add(r2 + 1, c2 + 1, c);
            c = (2 * c) % M;
        }else if(ty == 2) {
            ll c = ma[{r1, c1}];
            add(r1, c1, -c);
            add(r1, c2 + 1, c);
            add(r2 + 1, c1, c);
            add(r2 + 1, c2 + 1, -c);
        }else {
            ll q1 = getsum(r1, c1);
            ll q2 = getsum(r2, c2);
            if((q1 - q2) % M == 0) {
                cout << "Yes\n";
            }else {
                cout << "No\n";
            }
        }
    }
}