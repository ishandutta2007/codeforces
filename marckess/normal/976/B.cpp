#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

ll n, m, k;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> m >> k;
    
    if (k < n) {
        cout << k + 1 << " " << 1 << endl;
    } else {
        k -= n;
        ll fil = k / (m - 1);
        ll col = k % (m - 1);

        cout << n - fil << " ";

        if (fil % 2)
            cout << m - col << endl;
        else
            cout << 2 + col << endl;
    }

    return 0;
}