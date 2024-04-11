/*input
9 2 26
2 3


12 3 1
2 5 6



*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define int long long
#define N 200005
#define bit(x,y) ((x>>y)&1LL)
#define loop(i,l,r) for(int i=(int)(l); i<=(int)(r); i++)

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
long long binPow(long long a, long long q) {
    long long ret = 1;
    for (int i = 0; (1LL << i) <= q; i++) {
        if (q & (1LL << i)) ret = (ret * a) % mod;
        a = (a * a) % mod;
    }
    return ret;
}

int n, m, A;
vector<int> seg;
int dp[N][2];

int calSame(int len) {
    return binPow(A, len);
}

int calDiff(int len) {
    int tmp = binPow(A, len);
    int ret = tmp * (tmp - 1) % mod;
    if (ret < 0) ret += mod;
    ret = (ret * binPow(2, mod - 2)) % mod;
    return ret;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> A;
    int pre = 1;
    loop(i, 1, m) {
        int t; cin >> t;
        seg.push_back(t - pre + 1);
        pre = t + 1;
    }
    int lenRem = 0;
    if (pre != n / 2 + 1) {
        lenRem = n / 2 - pre + 1;
    }
    dp[0][0] = 1;
    loop(i, 1, seg.size()) {
        int it = seg[i - 1];
        dp[i][0] = calSame(it) * dp[i - 1][0] % mod;
        dp[i][1] = (dp[i - 1][1] * (calSame(it) + calDiff(it)) % mod + dp[i - 1][0] * calDiff(it) % mod) % mod;
    }
    int curans = (dp[seg.size()][1] + dp[seg.size()][0]) % mod;
    curans = curans * binPow(A, lenRem) % mod * binPow(A, lenRem) % mod;
    if (n % 2 == 1)
        curans = curans * A % mod;
    cout << curans << endl;
}