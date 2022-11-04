#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
 
#define fi first
#define se second
#define endl '\n'
#define MOD(n,k) (((n % k) + k ) % k)

struct ST {
    vi lazy;

    ST (int n) : lazy(4*n) {}

    void update (int i, int j, int a, int b, int k, int pos) {
        if (lazy[pos]) {
            if (i != j) {
                lazy[pos*2] = lazy[pos];
                lazy[pos*2+1] = lazy[pos];
                lazy[pos] = 0;
            }
        }

        if (a > j || b < i)
            return;
        
        if (a <= i && j <= b) {
            lazy[pos] = k;
            return;
        }

        int m = (i+j)/2;
        update(i, m, a, b, k, pos*2);
        update(m+1, j, a, b, k, pos*2+1);
    }

    void obtRes (int i, int j, int pos) {
        if (lazy[pos]) {
            if (i != j) {
                lazy[pos*2] = lazy[pos];
                lazy[pos*2+1] = lazy[pos];
                lazy[pos] = 0;
            }
        }

        if (i == j) {
            cout << lazy[pos] << " ";
            return;
        }

        int m = (i+j)/2;
        obtRes(i, m, pos*2);
        obtRes(m+1, j, pos*2+1);
    }
};

int n, m, l[300005], r[300005], x[300005];
ST ft(0);

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    ft = ST(n+3);

    for (int i = 0; i < m; i++)
        cin >> l[i] >> r[i] >> x[i];

    for (int i = m-1; i >= 0; i--) {
        int a = l[i], b = r[i], c = x[i];

        if (c > a)
            ft.update(1, n, a, c-1, c, 1);
        if (c < b)
            ft.update(1, n, c+1, b, c, 1);
    }

    ft.obtRes(1, n, 1);
    cout << endl;

    return 0;
}