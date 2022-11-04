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

int gcd (int a, int b) {
    return b ? gcd(b, a%b) : a;
}

vi divi;
void obtDivi (ll n) {
    for ( ll i = 1; i * i <= n; i++ ) 
        if ( n % i == 0 )
            divi.push_back(i);

    for (int i = divi.size() - 1; i >= 0; i--)
        divi.push_back(n / divi[i]);
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int x, y, com, q, a, b;

    cin >> x >> y;
    com = gcd(x, y);

    obtDivi(com);

    cin >> q;
    while (q--) {
        cin >> a >> b;
        auto it = upper_bound(divi.begin(), divi.end(), b);
        it--;
        if ( *it >= a )
            cout << *it << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}