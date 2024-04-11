#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define fi first
#define se second
#define endl '\n'
#define MOD(n,k) ( (n % k) + k ) % k
#define isOn(S, j) (S & (1 << j) )
#define setBit(S, j) (S |= (1 << j ) )
#define LSB(S) (S & (-S))

int sum = 0;
vector<vi> v(105, vi(105)), u;
int mCol[105], mFil[105];

int esPos (int n, int m) {
    int res = 0;
    for (int i = 0; i < n; i++) {
        int mn = 500;
        for (int j = 0; j < m; j++)
            mn = min(mn, v[i][j]);
        sum -= mn * m;
        for (int j = 0; j < m; j++)
            v[i][j] -= mn;
        mFil[i] = mn;
        res += mn;
    }

    for (int j = 0; j < m; j++) {
        int mn = 500;
        for (int i = 0; i < n; i++)
            mn = min(mn, v[i][j]);
        sum -= mn * n;
        for (int i = 0; i < n; i++)
            v[i][j] -= mn;
        mCol[j] = mn;
        res += mn;
    }

    return sum ? -1 : res;
}

void obtRes (int n, int m, bool f) {
    for ( int i = 0; i < n; i++ )
        while ( mFil[i]-- )
            cout << (f ? "row " : "col ") << i + 1 << endl;
    for ( int i = 0; i < m; i++ )
        while ( mCol[i]-- )
            cout << (f ? "col " : "row ") << i + 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, res;

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if ( n < m ){
                cin >> v[i][j];
                sum += v[i][j];
            }else{
                cin >> v[j][i];
                sum += v[j][i];
            }

    u = v;
    res = esPos( min(n, m), max(n, m) );
    if ( res > -1 ) {
        cout << res << endl;
        obtRes( min(n, m), max(n, m), n < m );
    } else{
        cout << -1 << endl;
    }

    return 0;
}