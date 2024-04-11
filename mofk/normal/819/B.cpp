#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

int N;
int a[1000006];
int p[2000006];
int cnt[2000006];
ll ans[1000006];
ll sz, lazy, tot;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    ff(i, 1, N) cin >> a[i], p[1-i+N] = i, ++cnt[a[i]-i+N];
    ff(i, 0, N + N - 1) {
        if (p[i]) ++sz, tot += a[p[i]];
        lazy += sz;
        ans[i%N] += tot - lazy;
        sz -= cnt[i];
    }
    ll res = 2LL * ans[0], id = 0;
    ff(i, 1, N - 1) if (res > 2LL * ans[i]) res = 2LL * ans[i], id = i;
    cout << res << ' ' << id << endl;
    return 0;
}