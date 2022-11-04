#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m, a, b;
    ld mx = 1e18;

    cin >> n >> m;
    while (n--) {
        cin >> a >> b;
        mx = min(mx, ld(a) / b);
    }

    cout << fixed << setprecision(8) << mx * m << endl;

	return 0;
}