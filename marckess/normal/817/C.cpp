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

ll n, s;

ll sumDig (ll n) {
    ll sum = 0;
    while (n) {
        sum += n % 10L;
        n /= 10L;
    }
    return sum;
}

bool isPos (ll n) {
    return n - sumDig(n) >= s;
}

ll obtRes () {
    ll i = 0, j = 2e18, m = (i + j) / 2;

    for (int l = 0; l < 65; l++) {
        if ( isPos(m) )
            j = m;
        else
            i = m;
        m = (i + j) / 2;
    }

    return m + 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> s;
    ll res = obtRes();
    
    if ( res > n )
        cout << 0 << endl;
    else
        cout << n - res + 1 << endl;

    return 0;
}