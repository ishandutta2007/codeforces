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

const int MX = 300005;
int n, l[MX], r[MX], q[MX];

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        q[i] = i;
    }

    sort(q, q+n, [&] (int a, int b) {
        if (l[a] == l[b])
            return r[a] > r[b];
        return l[a] < l[b];
    });

    int mx = -1, ind;
    for (int i = 0; i < n; i++) {
        int u = q[i];

        if (l[u] > mx) {
            mx = r[u];
            ind = u + 1;
        } else {
            if (r[u] <= mx) {
                cout << u + 1 << " " << ind << endl;
                return 0;
            }

            if (r[u] > mx) {
                mx = r[u];
                ind = u + 1;
            }
        }
    }

    cout << -1 << " " << -1 << endl;

    return 0;
}