#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

const int MAX = 100005, INF = 1e9;

int N, Q;
int a[MAX];
int h[MAX];
int l[MAX], r[MAX];

int main(void) {
    cin >> N >> Q;
    ff(i, 1, N) cin >> a[i];
    ff(i, 2, N) h[i] = abs(a[i] - a[i-1]);
    h[1] = h[N+1] = INF;
    ff(i, 2, N) {
        l[i] = i;
        while (h[l[i]-1] <= h[i]) l[i] = l[l[i]-1];
    }
    fb(i, N, 2) {
        r[i] = i;
        while (h[r[i]+1] < h[i]) r[i] = r[r[i]+1];
    }
    int L, R; ll res;
    ff(o, 1, Q) {
        cin >> L >> R; ++L;
        res = 0;
        ff(i, L, R) {
            res += (1ll * (min(r[i], R) - i) * (i - max(l[i], L)) + min(r[i], R) - max(l[i], L) + 1) * h[i];
            //cout << (1ll * (min(r[i], R) - i) * (i - max(l[i], L)) + min(r[i], R) - max(l[i], L) + 1) << " ";
        }
        cout << res << "\n";
    }
    return 0;
}