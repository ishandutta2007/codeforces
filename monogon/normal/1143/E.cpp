
#include <bits/stdc++.h>

#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORK(i, k, n) for(int i = k; i < n; i++)
#define FORr(i, n) for(int i = n - 1; i >= 0; i--)
#define FORKr(i, k, n) for(int i = n - 1; i >= k; i--)
#define PRINT(a, b) copy((a), (b), ostream_iterator<int>(cout, " "))
#define all(a) a.begin(), a.end()
#define in(a, b) ((b).find(a) != (b).end())
#define sz(a) ((int) (a).size())
#define Mp make_pair
#define PII pair<int, int>
#define LL long long
#define VI vector<int>

using namespace std;

// assume permutation is (1 2 3 ... n)
// ignoring cyclic shifts, how would we do this?
// for each index i, store first index j such that [i, j] contains p.
// for each i, store the first j such that a[j] = a[i] + 1
// store the first j such that [i, j] contains the permutation from i to 2^k in the permutation

// let b[i][k] be this value.
// e.g. 1 1 1 1 2 2 2 2
// iterate through the array, keeping track of all the "unmatched" values

const int MAX_N = 2e5 + 5;

int n, m, q, l, r;
int a[MAX_N], p[MAX_N], invp[MAX_N];
int b[MAX_N][20];
int f[MAX_N];

int main() {
    std::ios_base::sync_with_stdio(false);
    cin >> n >> m >> q;
    FOR(i, n) {
        cin >> p[i];
        p[i]--;
        invp[p[i]] = i;
    }
    vector<int> v[n];
    FOR(i, m) {
        cin >> a[i];
        a[i]--;
        a[i] = invp[a[i]];
        for(int j : v[(a[i] + n - 1) % n]) {
            b[j][0] = i;
        }
        v[(a[i] + n - 1) % n].clear();
        v[a[i]].push_back(i);
    }
    FOR(i, n) {
        for(int j : v[i]) {
            b[j][0] = -1;
        }
    }
    int mul = 2;
    for(int k = 1; mul < n; k++) {
        for(int i = 0; i < m; i++) {
            if(b[i][k - 1] == -1) {
                b[i][k] = -1;
            }else {
                b[i][k] = b[b[i][k - 1]][k - 1];
            }
        }
        mul *= 2;
    }
    for(int i = 0; i < m; i++) {
        f[i] = i;
    }
    mul = 1;
    for(int k = 0; mul < n; k++) {
        for(int i = 0; i < m && ((n - 1) & mul); i++) {
            if(f[i] != -1) {
                f[i] = b[f[i]][k];
            }
        }
        mul *= 2;
    }
    for(int i = m - 2; i >= 0; i--) {
        if(f[i] == -1) {
            f[i] = f[i + 1];
        }else if(f[i + 1] != -1) {
            f[i] = min(f[i], f[i + 1]);
        }
    }
    while(q--) {
        cin >> l >> r;
        l--; r--;
        cout << (f[l] != -1 && f[l] <= r ? 1 : 0);
    }
    cout << endl;
}