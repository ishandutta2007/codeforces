#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define fi first
#define se second
#define endl '\n'
#define MOD(n,k) ( (n % k) + k ) % k
#define isOn(S, j) (S & (1 << j) )
#define setBit(S, j) (S |= (1 << j ) )
#define LSB(S) (S & (-S))

struct BIT {
    vi v;

    BIT(int n) : v(n, 0) {}

    void update (int k, int x) {
        while ( k < v.size() ) {
            v[k] += x;
            k += LSB(k);
        }
    }

    int getVal (int k) {
        int sum = 0;
        while ( k ) {
            sum += v[k];
            k -= LSB(k);
        }
        return sum;
    }

};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, k, q, a, b, x;

    cin >> n >> k >> q;
    BIT rec(2e5+5);

    while (n--) {
        cin >> a >> b;
        rec.update(a, 1);
        rec.update(b+1, -1);
    }

    BIT res(2e5+5);
    for (int i = 1; i <= 200000; i++) {
        if ( rec.getVal(i) >= k ) {
            res.update(i, 1);
        }
    }

    while (q--) {
        cin >> a >> b;
        cout << res.getVal(b) - res.getVal(a-1) << endl;
    }

    return 0;
}