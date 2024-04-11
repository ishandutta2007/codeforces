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
 
const int MX = 1000005;
int n, a[105], res = 0;
char c[105];
bitset<MX> ini, bs;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c[i] >> a[i];

        if (c[i] == '+') {
            bs[a[i]] = 1;
        } else {
            if (bs[a[i]])
                bs[a[i]] = 0;
            else
                ini[a[i]] = 1;
        }
    }

    bs = ini;

    res = bs.count();
    for (int i = 0; i < n; i++) {
        if (c[i] == '+')
            bs[a[i]] = 1;
        else
            bs[a[i]] = 0;

        res = max(res, int(bs.count()));
    }

    cout << res << endl;

    return 0;
}