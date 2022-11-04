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

int n, ma = 0, mb = 0, mc = 0;
string a, b, c;
vi ca(255), cb(255), cc(255);

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> a >> b >> c;

    for (int i = 0; i < a.size(); i++) {
    	ca[a[i]]++;
    	ma = max(ma, ca[a[i]]);
    }

    for (int i = 0; i < b.size(); i++) {
    	cb[b[i]]++;
    	mb = max(mb, cb[b[i]]);
    }

    for (int i = 0; i < c.size(); i++) {
    	cc[c[i]]++;
    	mc = max(mc, cc[c[i]]);
    }

    if (n == 1 && ma == a.size())
        ma--;
    else 
        ma = min(ma + n, (int)a.size());

    if (n == 1 && mb == b.size())
        mb--;
    else
        mb = min(mb + n, (int)b.size());

    if (n == 1 && mc == c.size())
        mc--;
    else
        mc = min(mc + n, (int)c.size());

    if (ma > mb && ma > mc)
    	cout << "Kuro" << endl;
    else if (mb > mc && mb > ma)
    	cout << "Shiro" << endl;
    else if (mc > ma && mc > mb)
    	cout << "Katie" << endl;
    else
    	cout << "Draw" << endl;

    return 0;
}