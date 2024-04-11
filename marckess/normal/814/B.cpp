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
    
    int a[1005], b[1005], p[1005], n, c1 = -1, c2 = -1;
    bitset<1005> bs;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
        cin >> b[i];

    for (int i = 0; i < n; i++) {
        if ( a[i] != b[i] ) {
            if ( c1 > -1 )
                c2 = i;
            else
                c1 = i;
        } else {
            p[i] = a[i];
            bs[a[i]] = 1;
        }
    }

    if ( c2 == -1 ) {
        int i = 1;
        for ( i = 1; bs[i]; i++ );
        p[c1] = i;
    } else {
        if ( !bs[a[c1]] && !bs[b[c2]] && a[c1] != b[c2] ) {
            p[c1] = a[c1];
            p[c2] = b[c2];
        } else if ( !bs[b[c1]] && !bs[a[c2]] && b[c1] != a[c2] ) {
            p[c1] = b[c1];
            p[c2] = a[c2];
        } else if ( !bs[a[c1]] && !bs[a[c2]] && a[c1] != a[c2] ) {
            p[c1] = a[c1];
            p[c2] = a[c2];
        } else {
            p[c1] = b[c1];
            p[c2] = b[c2];
        }
    }

    for (int i = 0; i < n; i++)
        cout << p[i] << " ";
    cout << endl;

}