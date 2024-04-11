#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

int N, s;
int a[200005];
int exist[200005];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> s;
    ff(i, 1, N) cin >> a[i];
    if (N == 1) return cout << 0 << endl, 0;
    int flag = (!!a[s]);
    ff(i, 1, N) if (i != s) ++exist[a[i]];
    int ans = N, cur = 0, need = 0;
    ff(i, 1, N - 1) {
        if (!exist[i]) ++need;
        cur += exist[i];
        ans = min(ans, max(N - 1 - cur, need) + flag);
    }
    cout << ans << endl;
    return 0;
}