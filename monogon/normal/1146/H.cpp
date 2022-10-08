
#include <bits/stdc++.h>

#define ll long long
using namespace std;

#define pt complex<ll>
#define x real()
#define y imag()
#define dot(u, v) ((conj(u) * (v)).x)
#define cross(u, v) ((conj(u) * (v)).y)

istream &operator>>(istream &is, pt &p) {
    int X, Y;
    is >> X >> Y;
    p = {X, Y};
    return is;
}

const int N = 305;
ll n;
pt p[N];
ll dp[N][N][5];

struct seg {
    int i, j;
    seg(int i, int j): i(i), j(j) {}
};
bool upper(const pt p) {
    return p.y > 0 || (p.y == 0 && p.x > 0);
}
bool cmp(const seg *a, const seg *b) {
    if(upper(p[a->j] - p[a->i]) != upper(p[b->j] - p[b->i])) return upper(p[a->j] - p[a->i]);
    return cross(p[a->j] - p[a->i], p[b->j] - p[b->i]) > 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }
    vector<seg*> v;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            v.push_back(new seg(i, j));
            v.push_back(new seg(j, i));
        }
    }
    sort(v.begin(), v.end(), cmp);
    for(int t = 0; t < (int) v.size(); t++) {
        int i = v[t]->i, j = v[t]->j;
        for(int k = 0; k < n; k++) {
            for(int l = 1; l < 5; l++) {
                dp[i][k][l + 1] += dp[j][k][l];
            }
        }
        dp[i][j][1] = 1;
    }

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ans += dp[i][i][5];
    }
    cout << ans << endl;
}