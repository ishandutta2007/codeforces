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
D pi = acos(-1.);
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
const int N = 300033;
struct P {
    D x, y;
    D sqrlen() const { return x * x + y * y; }
    D len() const { return sqrt(sqrlen()); }
    void scan() {
        scanf("%lf%lf", &x, &y);
    }
} a[N];
inline D atan2(const P & x) {
    return atan2(x.y, x.x);
}
inline D _(double x) {
    while(x < 0) x += 2 * pi;
    while(x >= 2 * pi) x -= 2 * pi;
    return x;
}
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
namespace tmp {
    int n, m, a[200001], u[200001][2];
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    struct tree {
        int l, r, sum;
    } f[10000001];
    int root[200001];
    vector<int> p[200001];
    struct node{
        double  v;
        int pos1, pos2;
        bool operator < (const node &A) const {
            return v < A.v;
        }
    } q[200001];
    int yyu = 1;

    inline void buildtree(int k, int Left, int Right) {
        f[k].sum = 0;
        if (Left == Right)
            return;
        f[k].l = ++yyu;
        f[k].r = ++yyu;
        int i = (Left + Right) >> 1;
        buildtree(k + k, Left, i);
        buildtree(k + k + 1, i + 1, Right);
    }

    void change(int k1, int k2, int Left, int Right, int x) {
        f[k1].sum = f[k2].sum + 1;
        if (Left == Right)
            return;
        int i = (Left + Right) >> 1;
        if (x <= i) {
            f[k1].r = f[k2].r;
            f[k1].l = ++yyu;
            change(yyu, f[k2].l, Left, i, x);
        } else {
            f[k1].l = f[k2].l;
            f[k1].r = ++yyu;
            change(yyu, f[k2].r, i + 1, Right, x);
        }
    }

    int suan(int k, int Left, int Right, int s, int t) {
        if (s > t)
            return 0;
        if (Left == s && Right == t)
            return f[k].sum;
        int i = (Left + Right) >> 1;
        if (t <= i)
            return suan(f[k].l, Left, i, s, t);
        else
            if (s > i)
                return suan(f[k].r, i + 1, Right, s, t);
            else
                return suan(f[k].l, Left, i, s, i) + suan(f[k].r, i + 1, Right, i + 1, t);
    }

    long long calc(vector< pair<double, double> > a) {
        if(a.empty()) return 0;
        //for(auto tmp : a) printf("%f %f, ", tmp.fi, tmp.se);
        //printf("\n");
        int n = a.size(), tot = 0;
        for (int i = 0; i < n; i++) {
            double x = a[i].first, y = a[i].second;
            if (x > y)
                swap(x, y);
            q[++tot].v = x; q[tot].pos1 = i; q[tot].pos2 = 0;
            q[++tot].v = y; q[tot].pos1 = i; q[tot].pos2 = 1;
        }
        sort(q + 1, q + tot + 1);
        int cnt = 0;
        for (int i = 1; i <= tot; i++) {
            if (i == 1 || q[i].v != q[i - 1].v)
                ++cnt;
            u[q[i].pos1][q[i].pos2] = cnt;
        }
        for (int i = 1; i <= cnt; i++)
            p[i].clear();
        for (int i = 1; i <= n; i++) 
            p[u[i - 1][0]].push_back(u[i - 1][1]);

        //for (int i = 0; i < n; i++)
        //    printf("%d %d\n", u[i][0], u[i][1]);

        yyu = 0; root[0] = 1;
        buildtree(1, 1, tot);
        int cur;
        for (int i = 1; i <= cnt; i++) {
            cur = root[i - 1];
            for (auto j : p[i]) {
                int tmp = ++yyu;
                change(tmp, cur, 1, tot, j);
                cur = tmp;
            }
            root[i] = cur;
        }
        long long res = 0;
        for (int i = 0; i < n; i++) 
            res += suan(root[u[i][1] - 1], 1, tot, u[i][1] + 1, tot) - suan(root[u[i][0]], 1, tot, u[i][1] + 1, tot);
        return res;
    }

};
int main() {
    LL n, k;
    scanf("%I64d%I64d", &n, &k);
    for(int i = 0; i < n; i++) {
        a[i].scan();
    }
    D le = 0, ri = 3e4 + 10;
    for(int i = 0; i < 70; i++) {
        D mid = (le + ri) / 2;
        LL cntmid = 0;
        vector<pair<D, D> > v;
        for(int i = 0; i < n; i++) {
            if(a[i].len() <= mid) {
                cntmid++;
            }else {
                D ang = atan2(a[i]);
                D delta = acos(mid / a[i].len());
                v.pb(make_pair(_(ang - delta), _(ang + delta)));
            }
        }
        LL val = (LL)v.size() * ((LL)v.size() - 1) / 2 - tmp::calc(v) + cntmid * (n - cntmid) + cntmid * (cntmid - 1) / 2;
        //cout << cntmid << endl;
        //cout << val << ' ' << mid << endl;
        if(val < k) {
            le = mid;
        }else ri = mid;
    }
    printf("%.12f\n", le);

}