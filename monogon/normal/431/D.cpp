
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

// mth number with (k - 1) digits, plus 1
// choose[N][K]
// choose enough digits D so that (D choose (k - 1)) >= m
// if((D - 1) choose (k - 1) < m) set digit D to 1, m -= (D - 1) choose (k - 1), D--, k--.
// else, set digit D to 0, D--.

const int K = 65;
ll m;
int k;
ll choose[K][K];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> k;
    choose[0][0] = 1;
    for(int i = 1; i < K; i++) {
        choose[i][0] = 1;
        for(int j = 1; j < K; j++) {
            choose[i][j] = choose[i - 1][j] + choose[i - 1][j - 1];
            choose[i][j] = min(choose[i][j], ((ll) 1e18) + 5);
        }
    }
    int d = k - 1;
    ll ans = 0;
    while(choose[d][k - 1] < m) d++;
    while(d > 0 && k > 0) {
        if(choose[d - 1][k - 1] < m) {
            ans += (1LL << (d - 1));
            m -= choose[d - 1][k - 1];
            k--;
        }
        d--;
    }
    cout << ans + 1 << endl;
}