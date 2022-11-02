#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<algorithm>
#include<iostream>
#include<bitset>
#include<functional>
#include<numeric>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<iomanip>
#include<random>
#include<ctime>
#include<complex>
using namespace std;
typedef long long LL;
typedef double D;
#define all(v) (v).begin(), (v).end()
mt19937 gene(233);
typedef complex<double> Complex;
#define fi first
#define se second
#define ins insert
#define pb push_back
inline char GET_CHAR(){
    const int maxn = 131072;
    static char buf[maxn],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,maxn,stdin),p1==p2)?EOF:*p1++;
}
inline int getInt() {
    int res(0);
    char c = getchar();
    while(c < '0') c = getchar();
    while(c >= '0') {
        res = res * 10 + (c - '0');
        c = getchar();
    }
    return res;
}

inline LL fastpo(LL x, LL n, LL mod) {
    LL res(1);
    while(n) {
        if(n & 1) {
            res = res * (LL)x % mod;
        }
        x = x * (LL) x % mod;
        n /= 2;
    }
    return res;
}
LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }

inline string itoa(int x, int width = 0) {
    string res;
    if(x == 0) res.push_back('0');
    while(x) {
        res.push_back('0' + x % 10);
        x /= 10;
    }
    while((int)res.size() < width) res.push_back('0');
    reverse(res.begin(), res.end());
    return res;
}
const int _B = 131072;
char buf[_B];
int _bl = 0;
inline void flush() {
    fwrite(buf, 1, _bl, stdout);
    _bl = 0;
}
__inline void _putchar(char c) {
    if(_bl == _B) flush();
    buf[_bl++] = c;
}
inline void print(LL x, char c) {
    static char tmp[20];
    int l = 0;
    if(!x) tmp[l++] = '0';
    else {
        while(x) {
            tmp[l++] = x % 10 + '0';
            x /= 10;
        }
    }
    for(int i = l - 1; i >= 0; i--) _putchar(tmp[i]);
    _putchar(c);
}
struct P {
    D x, y;
};
const int N = 300033;
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
int l, n, m, k, q, t, a[500011], c[500011], size[500011], T, d[500001], u[500011], tmp[500011], f[500011], v[500011];
char str[200011];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<int> w[500011];
const int P = 998244353;

bool b[500011], r[500011], bb[500011];
int cc[3000011][4], ccc;
set<int> e;
map< pair<int, int>, vector< pair<int, int> > > ww;
set<int> www[500011];

int gf(int i) {
    if (i == f[i])
        return i;
    int j = gf(f[i]);
    if (f[i] != j) {
        cc[++ccc][0] = i;
        cc[ccc][1] = f[i];
        cc[ccc][2] = v[i];
        cc[ccc][3] = size[i];
    }
    v[i] = v[i] ^ v[f[i]];
    f[i] = j;
    return j;
}

int main() {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), w[a[i]].push_back(i), f[i] = i, size[i] = 1;
    for (int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (a[x] != a[y]) {
            ww[make_pair(a[x], a[y])].push_back(make_pair(x, y));
            ww[make_pair(a[y], a[x])].push_back(make_pair(x, y));
            www[a[x]].insert(a[y]);
            www[a[y]].insert(a[x]);
        } else 
            ww[make_pair(a[x], a[x])].push_back(make_pair(x, y));
    }
    long long ans = 0;
    int g = 0;
    for (int i = 1; i <= q; i++) {
        bool ok = true;
        for (auto j : ww[make_pair(i, i)]) {
            int x = j.first, y = j.second;
            if (gf(x) != gf(y)) {
                if (size[gf(x)] > size[gf(y)])
                    swap(x, y);
                v[gf(x)] = 1 - (v[x] ^ v[y]);
                size[gf(y)] += size[gf(x)];
                f[gf(x)] = gf(y);
            } else {
                if (v[x] == v[y])
                    ok = false;
            }
            if (!ok)
                break;
        }
        r[i] = ok;
        if (!ok)
            ++g;        
    }
    ans = 1LL * (q - g) * g + 1LL * g * (g - 1) / 2;
    
    for (int i = 1; i <= q; i++)
        if (r[i]) {
            for (auto j : www[i])
                if (r[j])
                    if (j < i) {
                        ccc = 0;
                        bool ok = true;
                        for (auto k : ww[make_pair(i, j)]) {
                            int x = k.first, y = k.second;
                            if (gf(x) != gf(y)) {
                                if (size[gf(x)] > size[gf(y)])
                                    swap(x, y);
                                int uuu = ++ccc;
                                cc[uuu][0] = gf(x);
                                cc[uuu][1] = gf(x);
                                cc[uuu][2] = v[gf(x)];
                                cc[uuu][3] = size[gf(x)];
                                uuu = ++ccc;
                                cc[uuu][0] = gf(y);
                                cc[uuu][1] = gf(y);
                                cc[uuu][2] = v[gf(y)];
                                cc[uuu][3] = size[gf(y)];
                                v[gf(x)] = 1 - (v[x] ^ v[y]);
                                size[gf(y)] += size[gf(x)];
                                f[gf(x)] = gf(y);
                            } else
                                if (v[x] == v[y])
                                    ok = false;
                            if (!ok)
                                break;
                        }
                        if (!ok) ++ans;
                        for (int k = ccc; k; --k) {
                            f[cc[k][0]] = cc[k][1];
                            v[cc[k][0]] = cc[k][2];
                        }
                    }
        }
    ans = 1LL * q * (q - 1) / 2 - ans;
    printf("%lld\n", ans);
    
}