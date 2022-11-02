#include<bits/stdc++.h>
using namespace std;
const int N = 300000 + 5;
const int maxn = 300000 + 5;
using LL = long long;
struct bit {
    LL c[maxn + 5];
    void add(int x, LL v) {
        for (int i = x; i < maxn; i += i & (-i))
            c[i] += v;
    }
    LL ask(int x) {
        LL ret = 0;
        for (int i = x; i; i -= i & (-i)) {
            ret += c[i];
        }
        return ret;
    }
}bitk, bitb, bits, bitc;
int n;
LL ans = 0;
LL a[N];
void upd(int x) {
    for (int o = 1; o <= maxn; o += x) {
        LL t = min((LL)o + x - 1, (LL)maxn + 1);
        bitk.add(o, 1), bitk.add(t, -1);
        bitb.add(o, 1 - o), bitb.add(t, o - 1);
    }
}
void pd(LL x) {
    bits.add(x, x);
    bitc.add(x, 1);
}
void pr(LL x) {
    ans += 1ll * bitk.ask(x) * x;
    ans += bitb.ask(x);
}
int main() {
    ios::sync_with_stdio(false);
    int T = 1;
    while (T--) {
        cin >> n;
        LL mm = 0;
        for (int i = 1; i <= n; i += 1)
            cin >> a[i], mm = max(mm, a[i]);
        for (int i = 1; i <= n; i += 1) {
            LL x = a[i];
            pr(x);
            for (int o = 1; o <= maxn; o += a[i]) {
                LL R = min((LL)o + x - 2, (LL)maxn);
                LL tmp = (bitc.ask(R) - bitc.ask(o - 1));
                ans -= 1ll * tmp * (o - 1);
                ans += bits.ask(R) - bits.ask(o - 1);
            }
            pd(x);
            upd(a[i]);

            cout << ans << ' ';
        }

    }
}
/*
ABABABABAB
4433221100
544
*/