#include <bits/stdc++.h>
#define ff(i,a,b) for(int i = (a), _b = (b); i <= _b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
using namespace std;
typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef vector <int> vi;

const int MAX = 3e5 + 5, INF = 1e9;

int n, k, l;
vi a;
ll f[5005][5005];

void mnm(ll &p, ll q) { if (p > q) p = q; }

void init(void) {
    cin >> n >> k;
    ff(i, 1, n) { int x; cin >> x; a.pb(x); }
}

void process(void) {
    sort(a.begin(), a.end(), greater <int> ());
    l = n / k;
    ff(x, 0, n % k) ff(y, (x == 0), k - (n % k)) {
        int id = l * (x + y) + x;
        f[x][y] = 1ll * INF * INF;
        if (x > 0) mnm(f[x][y], f[x-1][y] - a[id-1] + a[id-l-1]);
        if (y > 0) mnm(f[x][y], f[x][y-1] - a[id-1] + a[id-l]);
    }
    cout << f[n%k][k - n%k] << endl;
}

int main(void) {
    init();
    process();
    return 0;
}