#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

int N, mod;
int a[100005];
set <int> s, s2;
int save;
bool inv;

int pw(int x, int y) {
    int ret = 1;
    while (y) {
        if (y & 1) ret = 1ll * ret * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> mod >> N;
    ff(i, 1, N) cin >> a[i], s2.insert(a[i]);
    s = s2;
    if (N == 1) return cout << a[1] << " " << 0 << endl, 0;
    if (N == mod) return cout << 0 << " " << 1 << endl, 0;
    if (N == mod - 1) {
        ff(i, 0, mod - 1) if (s2.find(i) == s2.end()) return cout << (i + 1) % mod << " " << 1 << endl, 0;
    }
    if (2 * N > mod) {
        inv = 1;
        N = 0;
        ff(i, 0, mod - 1) if (s.find(i) == s.end()) a[++N] = i;
        s.clear();
        ff(i, 1, N) s.insert(a[i]);
    }
    sort(a + 1, a + N + 1);
    int gap = a[2] - a[1];
    ff(i, 1, N) s.erase((a[i] + gap) % mod);
    int d = 1ll * gap * pw(s.size(), mod - 2) % mod;
    int first = *s2.begin(), last = *s2.begin(), cnt = 1;
    while (s2.find((last + d) % mod) != s2.end()) last = (last + d) % mod, ++cnt;
    while (s2.find((first - d + mod) % mod) != s2.end()) first = (first - d + mod) % mod, ++cnt;
    if (inv) N = mod - N;
    if (cnt != N) cout << -1 << endl;
    else cout << first << " " << d << endl;
    return 0;
}