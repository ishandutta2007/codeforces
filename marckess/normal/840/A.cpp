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

int n, a[200005], b[200005], c[200005], q[200005];

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++)
    	cin >> a[i];
    for (int i = 0; i < n; i++)
    	cin >> b[i];

    iota(q, q+n, 0);
    sort(q, q+n, [&] (int x, int y) {
    	return b[x] < b[y];
    });
    sort(a, a+n, greater<int>());

    for (int i = 0; i < n; i++)
    	c[q[i]] = a[i];

    for (int i = 0; i < n; i++)
    	cout << c[i] << " ";
    cout << endl;

    return 0;
}