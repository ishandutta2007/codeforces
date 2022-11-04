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

int a, b, x1, x2;
string f = "FIRST", s = "SECOND", d = "DRAW";

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> x1 >> x2 >> a >> b;
    if (x1 + a <= x2 && x2 <= x1 + b) {
        cout << f << endl << x2 << endl;
        return 0;
    }

    if ( (x1 < x2 && a <= 0) || (x1 > x2 && b >= 0) ) {
        cout << d << endl;
        return 0;
    }

    int d = x2 - x1;

    if (d % abs(a + b)) {
    	d = (abs(d) % abs(a + b)) * (d / abs(d));

        if (x1 + a <= x1 + d && x1 + d <= x1 + b)
        	cout << f << endl << x1 + d << endl;
        else
        	cout << "DRAW" << endl;

    } else {
        cout << s << endl;
    }

    return 0;
}