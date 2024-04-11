
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 85, K = 15;
int n, k;
ll a[N][N], dist[N][K];
bool col[N];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rand(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    ll ans = LLONG_MAX;
    for(int t = 0; t < 512 * 20; t++) {
        for(int i = 0; i < n; i++) {
            col[i] = rand(0, 1);
            for(int kk = 0; kk <= k; kk++) {
                dist[i][kk] = LLONG_MAX;
            }
        }
        dist[0][0] = 0;
        for(int kk = 1; kk <= k; kk++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(i != j && col[i] != col[j] &&
                            dist[i][kk - 1] != LLONG_MAX && dist[i][kk - 1] + a[i][j] < dist[j][kk]) {
                        dist[j][kk] = dist[i][kk - 1] + a[i][j];
                    }
                }
            }
        }
        ans = min(ans, dist[0][k]);
    }
    cout << ans << endl;
}