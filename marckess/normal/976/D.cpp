#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef pair<ii, ll> iii;

int n, u[1000005], v[1000005], m = 0;
vi a;

void obtRes (vi &d) {
    if (d.size() == 0)
        return;

    if (d.size() == 1) {
        int x = d[0] + 1;
        
        for (int i = 1; i <= x; i++) {
            for (int j = i + 1; j <= x; j++) {
                u[m] = i, v[m] = j, m++;
            }
        }

        return;
    }

    for (int i = d.back() + 2 - d[0]; i <= d.back() + 1; i++)
        for (int j = 1; j < i; j++)
            if (i != j)
                u[m] = i, v[m] = j, m++;

    vi a;
    for (int i = 1; i < d.size() - 1; i++)
        a.push_back(d[i] - d[0]);

    obtRes(a);
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    a = vi(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    obtRes(a);

    cout << m << endl;
    for (int i = 0; i < m; i++)
        cout << u[i] << " " << v[i] << endl;

    return 0;
}