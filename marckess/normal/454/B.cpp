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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, a[100005];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int mn = 1e9, ind;
    for (int i = 0; i < n; i++) {
        if ( a[i] < mn ) {
            mn = a[i];
            ind = i;
        }
    }

    int ant = a[ind], i;
    for ( i = (ind+1) % n; i != ind; i = (i+1)%n ) {
        if ( a[i] < ant ) {
            ind = n - 1;

            while ( a[ind] != mn )
                ind--;

            while ( ind > -1 && a[ind] == mn )
                ind--;

            ind++;
            ant = a[ind];

            for ( i = (ind+1)%n; i != ind; i = (i+1)%n ) {
                if ( a[i] < ant ) {
                    ind = n;
                    break;
                }
                ant = a[i];
            }

            break;
        }
        ant = a[i];
    }

    if ( ind == n )
        cout << -1 << endl;
    else
        cout << (n - ind) % n << endl;

    return 0;
}