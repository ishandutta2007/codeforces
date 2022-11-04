#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define fi first
#define se second
#define endl '\n'
#define MOD(n,k) ( (n % k) + k ) % k
#define isOn(S, j) (S & (1 << j) )
#define setBit(S, j) (S |= (1 << j ) )
#define LSB(S) (S & (-S))

int n, a[55][55];

bool esPos(int i , int j) {
    for (int k = 0; k < n; k++) {
        for (int l = 0; l < n; l++) {
            if ( a[i][j] == a[i][k] + a[l][j] )
                return true;
        }
    }
    return false;
}

bool obtRes () {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ( a[i][j] != 1 && !esPos(i, j) )
                return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    if (obtRes())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}