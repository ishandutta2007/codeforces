#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
 
#define fi first
#define se second
#define endl '\n'
#define MOD(n,k) (((n % k) + k ) % k)

int n, l, r, q, op, tam;
ll x, y;
vi a(510000), upset(710);
vvi seg(710, vi(710));

void update() {
    int ini = 0, fin = tam-1;
    l--, r--;

    for (int m = 0; m <= tam; m++, ini += tam, fin += tam) {
        if (l <= ini && fin <= r)
            upset[m] += x;
        else if (l > fin || r < ini)
            continue;
        else {
            for (int k = ini, lim = fin; k <= lim; k++) {
                if (k < l || k > r)
                    continue;
                a[k] += x;
            }

            for (int k = 0; k < tam; k++)
                seg[m][k] = a[ini+k];

            sort(seg[m].begin(), seg[m].begin()+tam);
        }
    }
}

void query() {
    int ini = 0, fin = tam-1;
    l = n, r = 0;

    for (int m = 0; m <= tam; m++) {
        if (upset[m] >= y) {
            continue;
        }

        if (binary_search (seg[m].begin(), seg[m].begin()+tam, y - upset[m])) {
            l = min(l, m);
            r = max(r, m);
        }
    }

    if (l == n) {
        cout << -1 << endl;
        return;
    }

    int ra = n, rb = 0;
    for (int k = 0; k < tam; k++) {
        int val = y - upset[l];
        if (a[l*tam+k] == val)
            ra = min(ra, l*tam+k);
    }

    for (int k = 0; k < tam; k++) {
        int val = y - upset[r];
        if (a[r*tam+k] == val)
            rb = max(rb, r*tam+k);
    }

    cout << rb - ra << endl;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;
    tam = ceil(sqrt(n));

    int j = 0, s = -1;
    for (int i = 0; i < n; i++, j++) {
        cin >> a[i];

        if (i % tam == 0) {
            j = 0;
            s++;
        }
        seg[s][j] = a[i];
    }

    for (int i = 0; i <= tam; i++)
        sort(seg[i].begin(), seg[i].begin()+tam);

    while (q--) {
        cin >> op;
        if (op == 1) {
            cin >> l >> r >> x;
            update();
        } else {
            cin >> y;
            query();
        }
    }

    return 0;
}