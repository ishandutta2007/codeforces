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
int n, m, k, t, a[200011], c[200011];
char str[200011];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main() {
    scanf("%d", &t);
    for (; t--; ) {
        scanf("%d%d", &n, &k);
        scanf("%s", str + 1);
        int cnt0 = 0, cnt1 = 0, ans = 0, tot = 0;
        bool ok = false;
        for (int i = 1; i <= n; i++) {
            if (str[i] == 'W') {
                if (i == 1 || str[i - 1] == 'L')
                    ++ans;
                else
                    ans += 2;
            }
            else {
                if (i == 1 || str[i - 1] == 'W')
                    a[++tot] = 0;
                ++a[tot];
            }
        }
        if (!tot) {
            printf("%d\n", ans);
        } else 
            if (a[1] == n) {
                if (k && a[1])
                    ++ans, --k, --a[1];
                printf("%d\n", ans += 2 * min(k, a[1]));
            } else {
                int len = 0;
                int L = 1, wei = 0;
                if (str[1] == 'L') {
                    L = 2;
                    ++wei;
                    len += a[1];
                }
                int R = tot;
                if (str[n] == 'L') {
                    R = tot - 1;
                    len += a[tot];
                    ++wei;
                }
                sort(a + L, a + R + 1);
                sort(c + 1, c + len + 1);
                for (int i = L; i <= R && k; i++)
                    if (k < a[i])
                        ans += 2 * k, k = 0;
                    else
                        ans += 2 * a[i] + 1, k -= a[i];
                ans += 2 * min(k, len);
                printf("%d\n", ans);
            }
    }
}