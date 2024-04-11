#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

struct dat { int L, R, V; } a[100005];
int N, M;
bool cmp(dat a, dat b) { if (a.L != b.L) return a.L < b.L; if (a.R != b.R) return a.R < b.R; return a.V < b.V; }
int ans[100005], s[100005];

void build(int k) {
    int last = 0;
    ff(i, 1, M) if (a[i].V >> k & 1) {
        ff(j, max(last + 1, a[i].L), a[i].R) ans[j] |= (1 << k);
        last = max(last, a[i].R);
    }
    memset(s, 0, sizeof s);
    ff(i, 1, N) s[i] = s[i-1] + (!(ans[i] >> k & 1));
    ff(i, 1, M) if (!(a[i].V >> k & 1)) if (s[a[i].R] == s[a[i].L-1]) { cout << "NO\n"; exit(0); }
}

int main(void) {
    cin >> N >> M;
    ff(i, 1, M) cin >> a[i].L >> a[i].R >> a[i].V;
    sort(a + 1, a + M + 1, cmp);
    ff(i, 0, 29) build(i);
    cout << "YES\n";
    ff(i, 1, N) cout << ans[i] << " "; cout << endl;
    return 0;
}