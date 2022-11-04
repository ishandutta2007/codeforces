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

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int mov[3] = {-1, 2, 1};
    int v[4][4];

    bool f = false;
    for ( int i = 0; i < 4; i++ ) {
        for ( int j = 0; j < 4; j++ ) {
            cin >> v[i][j];
        }
    }

    for ( int i = 0; i < 4; i++ ) {
        for ( int j = 0; j < 3; j++ ) {
            if ( v[i][j] && v[(mov[j]+i+4)%4][3] )
                f = true;
            if ( v[i][j] && v[i][3] )
                f = true;
        }
    }

    if (f)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}