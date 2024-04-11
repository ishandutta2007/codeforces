#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int a, b, x, y;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> a >> b;

    x = 0, y = 0;

    for (int i = 1; x <= a && y <= b; i++) {
        if (i % 2)
            y++;
        else
            x++;
        if (x == a && y == b) {
            cout << "YES" << endl;
            return 0;
        }
    }

    x = 0, y = 0;

    for (int i = 2; x <= a && y <= b; i++) {
        if (i % 2)
            y++;
        else
            x++;
        if (x == a && y == b) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;

    return 0;
}