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

ll M;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    map<ll, ll> m;
    ll n, k, x, sum = 0, res = 0;    

    cin >> n >> k;
    m[0] = 1;
    for (int i = 0; i < n; i++) {
        cin >> x;
        sum += x;
        M = max (M, max (sum, -sum));
        if ( abs(k) > 1 ){
            for (x = 1; abs(x) <= M*2; x *= k)
                if ( m.find(sum - x) != m.end() )
                    res += m[sum - x];
        }else if ( k == 1 ){
            if ( m.find(sum - 1) != m.end() )
                    res += m[sum - 1];
        }else {
            if ( m.find(sum - 1) != m.end() )
                    res += m[sum - 1];
            if ( m.find(sum + 1) != m.end() )
                res += m[sum + 1];
        }
        m[sum]++;
    }

    cout << res << endl;

    return 0;
}