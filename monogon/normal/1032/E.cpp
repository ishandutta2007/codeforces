
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

// ask for (k, m) where it can be uniquely written as a sum of identical a_i.
// for each a[i], do knapsack on the remaining weights, to see how many a[i] weights
// we can uniquely determine
// see if a sum of k, add up to k * w?

const int N = 105, A = 105;
int n;
int a[N], cnt[N];
bool ways[N * A][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    set<int> se;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
        se.insert(a[i]);
    }
    if(sz(se) <= 2) {
        cout << n << endl;
        return 0;
    }
    ways[0][0] = true;
    int mx = 1;
    for(int w = 1; w < A; w++) {
        if(cnt[w] > 0) {
            for(int x = 0; x < N * A; x++)
                fill(ways[x] + 1, ways[x] + cnt[w] + 1, false);
            for(int i = 0; i < n; i++) {
                if(a[i] != w) {
                    for(int x = N * A - 1; x >= a[i]; x--) {
                        for(int k = 1; k <= cnt[w]; k++) {
                            ways[x][k] |= ways[x - a[i]][k - 1];
                        }
                    }
                }
            }
            for(int j = 1; j <= cnt[w] && !ways[w * j][j]; j++) {
                mx = max(mx, j);
            }
        }
    }
    cout << mx << '\n';
}