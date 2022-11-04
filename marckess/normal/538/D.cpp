#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

char res[105][105], c[55][55];
bitset<55> bs[55];
int n;

bool esPos (int mx, int my) {
    if (!mx && !my)
        return false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (c[i][j] != 'o')
                continue;

            int x = i + mx, y = j + my;
            if (x < 0 || y < 0 || x >= n || y >= n)
                continue;
            if (c[x][y] == '.')
                return false;
        }
    }

    return true;
}

void valido (int mx, int my) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (c[i][j] != 'o')
                continue;

            int x = i + mx, y = j + my;
            if (x < 0 || y < 0 || x >= n || y >= n)
                continue;
            bs[x][y] = 1;
        }

    res[n-1+mx][n-1+my] = 'x';
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> c[i];

    for (int i = 0; i < 2 * n - 1; i++)
        for (int j = 0; j < 2 * n - 1; j++)
            res[i][j] = '.';
    res[n-1][n-1] = 'o';
    
    for (int dx = -n+1; dx <= n-1; dx++)
        for (int dy = -n+1; dy <= n-1; dy++)
            if (esPos(dx, dy))
                valido(dx, dy);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            assert(c[i][j] != '.' || !bs[i][j]);
            if (c[i][j] == 'x' && !bs[i][j]) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    cout << "YES" << endl;
    for (int i = 0; i < 2 * n - 1; i++) {
        for (int j = 0; j < 2 * n - 1; j++)
            cout << res[i][j];
        cout << endl;
    }

    return 0;
}