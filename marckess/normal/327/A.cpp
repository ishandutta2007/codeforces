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

int n, a, b, x, res;
bitset<105> bs;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    a = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        bs[i] = x;
        if ( bs[i] )
            a++;
    }

    res = 0;
    for ( int i = 0; i < n; i++ ) {
        x = 0;
        for ( int j = i; j < n; j++ ) {
            if ( bs[j] )
                x--;
            else
                x++;
            res = max ( a + x, res );
        }
    }

    cout << res << endl;

    return 0;
}