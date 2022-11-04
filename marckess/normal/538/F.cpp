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

const int MX = 200010;

struct BIT {
    int ft[MX];

    void init () {
        memset(ft, 0, sizeof(ft));
    }

    void update (int i, int k) {
        while (i < MX) {
            ft[i] += k;
            i += i & -i;
        }
    }

    int get (int i) {
        int sum = 0;
        while (i) {
            sum += ft[i];
            i -= i & -i;
        }
        return sum;
    }

    int query (int a, int b) {
        return get(b) - get(a-1);
    }
}ft;

int n, a[MX], res[MX], q[MX];

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ft.init();

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    iota(q, q+n, 1);
    sort(q, q+n, [&] (int i, int j) {
        return a[i] < a[j];
    });

    for (int i = 0, j = 0; i < n; i++) {
        int u = q[i], k = 1;

        while (j < n && a[q[j]] < a[u])
            ft.update(q[j++], 1);

        while (k < n && k * (u - 1) + 2 <= n)
            res[k++] += ft.query(k * (u - 1) + 2, min(n, k * u + 1));
    }

    for (int i = 1; i < n; i++)
        cout << res[i] << " ";
    cout << endl;

    return 0;
}