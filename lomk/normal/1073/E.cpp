/*input
001 001 1


10 50 2


1 2345 10

1 2345 10
10 50 2

*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define __builtin_popcount __builtin_popcountll
#define int long long
#define bit(x,y) ((x>>y)&1LL)
#define loop(i,l,r) for(int i=(int)(l); i<=(int)(r); i++)
#define rloop(i,l,r) for(int i=(int)(l); i>=(int)(r); i--)

void read(int &number) {
    bool negative = false;
    int c;
    number = 0;
    c = getchar();
    while (c == ' ' || c == '\n')
        c = getchar();
    if (c == '-') {
        negative = true;
        c = getchar();
    }
    for (; (c > 47 && c < 58); c = getchar())
        number = number * 10 + c - 48;
    if (negative)
        number = -number;
}

template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &a) {
    return os << '(' << a.first << ", " << a.second << ')';
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &a) {
    os << '[';
    for (unsigned int i = 0; i < a.size(); i++)
        os << a[i] << (i < a.size() - 1 ? ", " : "");
    os << ']';
    return os;
}
template <class T>
ostream &operator<<(ostream &os, const set<T> &a) {
    os << '{';
    for (typename set<T>::iterator it = a.begin(); it != a.end(); it++) {
        typename set<T>::iterator jt = it;
        os << *it << (++jt != a.end() ? ", " : "");
    }
    os << '}';
    return os;
}
template <class T1, class T2>
ostream &operator<<(ostream &os, map<T1, T2> &a) {
    os << "{\n";
    for (typename map<T1, T2>::iterator it = a.begin(); it != a.end(); it++) {
        typename map<T1, T2>::iterator jt = it;
        os << "  " << it->first << ": " << it->second << (++jt != a.end() ? ",\n" : "\n");
    }
    os << '}';
    return os;
}

const int mod = 998244353;

#define pow binPow
int binPow(int a, int q) {
    int ret = 1;
    while (q) {
        if (q & 1) ret = ret * a % mod;
        a = a * a % mod;
        q >>= 1LL;
    }
    return ret;
}

int l, r, diff;
string L, R;
pair<int, int> dp[20][2][2][2][1024]; // sum all, cnt
int ans = 0;


pair<int, int> cal(int pos, bool Lx, bool Rx, bool zer, int mask) {
    if (__builtin_popcount(mask) > diff) return mp(0, 0);
    if (pos == R.size()) return mp(0, 1);
    auto &ret = dp[pos][Lx][Rx][zer][mask];
    if (ret.se != -1) return ret;
    ret = mp(0LL, 0LL);
    int lo = 0, hi = 9;
    if (Lx) lo = L[pos] - '0';
    if (Rx) hi = R[pos] - '0';
    loop(i, lo, hi) {
        int nmask = mask;
        if (zer == 0 || (zer == 1 && i)) {
            nmask |= (1 << i);
        }
        auto rec = cal(pos + 1, min(Lx, i == lo), min(Rx, i == hi), min(zer, (i == 0)), nmask);
        ret.se = (ret.se + rec.se) % mod;
        ret.fi = (ret.fi + rec.fi + binPow(10, R.size() - pos - 1) * i % mod * rec.se % mod) % mod;
    }
    return ret;
}

signed main() {
#ifndef UncleGrandpa
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#endif
    cin >> l >> r >> diff;
    while (l) {
        L += char(l % 10 + '0');
        l /= 10;
    }
    while (r) {
        R += char(r % 10 + '0');
        r /= 10;
    }
    reverse(L.begin(), L.end()); reverse(R.begin(), R.end());
    while (L.size() < R.size()) L = "0" + L;
    memset(dp, -1, sizeof(dp));
    cout << cal(0, 1, 1, 1, 0).fi << endl;
}