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
int n, m, t, l, v[200001][41];
long long f[200001][41];
int g[200001][2][2];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
set< pair<long long, pair<int, int> > > c;
set< pair< pair<int, int>, pair<int, int> > > d;

const int P = 998244353;

struct node {
    node *next;
    int where, v;
} *first[200001], a[400001];
inline void makelist(int x, int y, int z) {
    a[++l].where = y;
    a[l].v = z;
    a[l].next = first[x];
    first[x] = &a[l];
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        makelist(x, y, 0);
        makelist(y, x, 1);
    }
    memset(f, 127, sizeof(f));
    f[1][0] = 0;
    c.clear(); 
    c.insert( make_pair(0, make_pair(1, 0)) );
    for (; c.size();) {
        auto itr = c.begin();
        int x = itr->second.first, y = itr->second.second;
        c.erase(itr);
        if (x == n) {
            printf("%lld\n", f[x][y] % P);
            return 0;
        }
        for (node *z = first[x]; z; z = z->next)
            if ((y & 1) == z->v && f[x][y] + 1 < f[z->where][y]) {
                if (f[z->where][y] > 1LL << 60LL) {
                    f[z->where][y] = f[x][y] + 1;
                    c.insert(make_pair(f[z->where][y], make_pair(z->where, y)));
                } else {
                    c.erase(make_pair(f[z->where][y], make_pair(z->where, y)));
                    f[z->where][y] = f[x][y] + 1;
                    c.insert(make_pair(f[z->where][y], make_pair(z->where, y)));                    
                }
            }
        if (y < 40 && f[x][y] + (1LL << y) < f[x][y + 1]) 
            if (f[x][y + 1] > 1LL << 60LL) {
                f[x][y + 1] = f[x][y] + (1LL << y);
                c.insert(make_pair(f[x][y + 1], make_pair(x, y + 1)));
            } else {
                c.erase(make_pair(f[x][y + 1], make_pair(x, y + 1)));
                f[x][y + 1] = f[x][y] + (1LL << y);
                c.insert(make_pair(f[x][y + 1], make_pair(x, y + 1)));
            }
    }
    
    memset(g, 127, sizeof(g));
    g[1][0][0] = 0; g[1][0][1] = 0;
    d.clear();
    d.insert( make_pair(make_pair(0, 0), make_pair(1, 0)) );
    for (; d.size(); ) {
        auto itr = d.begin();
        int x = itr->second.first; int y = itr->second.second;
        d.erase(itr);
        if (x == n) {
            long long ans = 0;
            for (int i = 0, j = 1; i < g[x][y][0]; i++, j *= 2, j %= P)
                ans += j, ans %= P;
            ans += g[x][y][1];
            ans %= P;
            printf("%d\n", ans);
            return 0;
        }
        for (node *z = first[x]; z; z = z->next)
            if ((y & 1) == z->v && (g[x][y][0] < g[z->where][y][0] || (g[x][y][0] == g[z->where][y][0] && 
        g[x][y][1] + 1 < g[z->where][y][1]))) {
                if (g[z->where][y][0] > 1LL << 60LL) {
                    g[z->where][y][0] = g[x][y][0];
                    g[z->where][y][1] = g[x][y][1] + 1;
                    d.insert(make_pair(make_pair(g[z->where][y][0], g[z->where][y][1]), make_pair(z->where, y)));
                } else {
                    d.erase(make_pair(make_pair(g[z->where][y][0], g[z->where][y][1]), make_pair(z->where, y)));
                    g[z->where][y][0] = g[x][y][0];
                    g[z->where][y][1] = g[x][y][1] + 1;
                    d.insert(make_pair(make_pair(g[z->where][y][0], g[z->where][y][1]), make_pair(z->where, y)));
                }
            }
        
        if (g[x][y][0] + 1 < g[x][y ^ 1][0] || (g[x][y][0] + 1 == g[x][y ^ 1][0] && g[x][y][1] < g[x][y ^ 1][1]))
            if (g[x][y ^ 1][0] > 1LL << 60LL) {
                g[x][y ^ 1][0] = g[x][y][0] + 1;
                g[x][y ^ 1][1] = g[x][y][1];
                d.insert(make_pair(make_pair(g[x][y ^ 1][0], g[x][y ^ 1][1]), make_pair(x, y ^ 1)));
            } else {
                d.erase(make_pair(make_pair(g[x][y ^ 1][0], g[x][y ^ 1][1]), make_pair(x, y ^ 1)));
                g[x][y ^ 1][0] = g[x][y][0] + 1;
                g[x][y ^ 1][1] = g[x][y][1];
                d.insert(make_pair(make_pair(g[x][y ^ 1][0], g[x][y ^ 1][1]), make_pair(x, y ^ 1)));
            }
    }
}