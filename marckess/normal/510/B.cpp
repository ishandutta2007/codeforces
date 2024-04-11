#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int n, m;
char c[55][55];
bitset<55> bs[55];
int mv[] = {1, 0, -1, 0, 0, 1, 0, -1};

bool dfs (int i, int j, int oi, int oj, char act, int nm) {
    if (i == oi && j == oj && nm >= 4)
        return 1;

    if (i < 0 || j < 0 || i >= n || j >= m || bs[i][j] || c[i][j] != act)
        return 0;

    bs[i][j] = 1;

    for (int l = 0; l < 4; l++) {
        int x = i + mv[l*2];
        int y = j + mv[l*2+1];

        if (dfs(x, y, oi, oj, act, nm+1))
            return 1;
    }

    return 0;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> c[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            for (int k = 0; k < n; k++)
                bs[k].reset();

            if (dfs(i, j, i, j, c[i][j], 0)) {
                cout << "Yes" << endl;
                return 0;
            }

        }
    }

    cout << "No" << endl;

    return 0;
}