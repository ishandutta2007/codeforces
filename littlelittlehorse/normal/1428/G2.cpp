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
int n, m, t, X1, Y1, X2, Y2, q;
long long a[500011], c[500011], f[1000001];
char str[500011];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

long long calc(long long n) {
    long long v = 0;
    for (int i = 0; n; n /= 10, i++)
        if (n % 10 == 3)
            v += a[i];
        else
            if (n % 10 == 6)
                v += a[i] * 2;
            else
                if (n % 10 == 9)
                    v += a[i] * 3;
    return v;
}    

int main() {
    scanf("%d", &m);
    for (int i = 0; i <= 5; i++)
        scanf("%lld", &a[i]);
    memset(f, 128, sizeof(f));
    f[0] = 0;
    if (m) {
        for (int i = 1; i <= 6; i++) {
            int res = 1;
            for (int j = 1; j < i; j++)
                res *= 10;
            for (int j = 999999; j >= 0; j--)
                if (f[j] >= 0) {
                    if (j + 3 * res < 1000000)
                        f[j + 3 * res] = max(f[j + 3 * res], f[j] + a[i - 1]);
                    if (j + 6 * res < 1000000)
                        f[j + 6 * res] = max(f[j + 6 * res], f[j] + 2 * a[i - 1]);
                    if (j + 9 * res < 1000000)
                        f[j + 9 * res] = max(f[j + 9 * res], f[j] + 3 * a[i - 1]);
                    for (int k = 1; k < 10; k++)
                        if (j + k * res < 1000000)
                            f[j + k * res] = max(f[j + k * res], f[j]);
                }
            if (m > 1)
                for (int j = 999999; j >= 0; j--)
                    if (f[j] >= 0) {
                        if (j + 3 * res < 1000000)
                            f[j + 3 * res] = max(f[j + 3 * res], f[j] + a[i - 1]);
                        if (j + 6 * res < 1000000)
                            f[j + 6 * res] = max(f[j + 6 * res], f[j] + 2 * a[i - 1]);
                        if (j + 9 * res < 1000000)
                            f[j + 9 * res] = max(f[j + 9 * res], f[j] + 3 * a[i - 1]);
                    }
            int x = m - 2;
            if (x <= 0)
                continue;
            for (int j = 0; j < 20; j++)
                if (x < (1 << j))
                    break;
                else {
                    x -= (1 << j);
                    long long s = 1LL * ((1 << j)) * res * 9, v = 1LL * ((1 << j)) * 3 * a[i - 1];
                    for (int k = 999999; k >= 0; --k)
                        if (f[k] >= 0 && k + s < 1000000)
                            f[k + s] = max(f[k + s], f[k] + v);
                }
            long long s = 1LL * x * res * 9, v = 1LL * x * 3 * a[i - 1];
            for (int k = 999999; k >= 0; --k)
                if (f[k] >= 0 && k + s < 1000000)
                    f[k + s] = max(f[k + s], f[k] + v);
        }
    }
    
    scanf("%d", &q);
    for (; q--; ) {
        scanf("%d", &n);
        printf("%lld\n", f[n]);
    }
}