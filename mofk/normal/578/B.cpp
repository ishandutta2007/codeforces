#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
using namespace std;
typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef vector <int> vi;

const int MAX = 2e5 + 5, INF = 1e9;

int N, K, X;
ll M = 1;
ll a[MAX];
ll s[MAX];

void init(void) {
    cin >> N >> K >> X;
    ff(i, 1, K) M *= X;
    ff(i, 1, N) cin >> a[i];
}

void process(void) {
    ff(i, 0, 32) {
        int cnt = 0, id = -1;
        ff(j, 1, N) if (a[j] & (1ll << i)) { id = j; cnt++; }
        if (cnt == 0) continue;
        if (cnt == 1) ff(j, 1, N) { if (j != id) s[j] |= (1ll << i); }
        else ff(j, 1, N) s[j] |= (1ll << i);
    }
    ll res = 0;
    ff(i, 1, N) res = max(res, s[i] | (a[i] * M));
    cout << res << endl;
}

int main(void) {
    init();
    process();
    return 0;
}