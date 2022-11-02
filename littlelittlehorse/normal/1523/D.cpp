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
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int a[200001];
char str[71];
long long b[200001];
int n, m, p;
int c[77777], d[77777];
int main() {
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 1; i <= n; i++) {
        scanf("%s", str);
        long long status = 0;
        for (int j = 0; j < m; j++)
            if (str[j] == '1')
                status |= (1LL << j);
        b[i] = status;
    }
    long long ans = 0; int cur = 0;
    for (int i = 1; i <= 20; i++) {
        int k = gene() % n + 1;
        static vector<int> id;
        id.clear();
        for(int j = 0; j < m; j++) {
            if((b[k] >> j) & 1) {
                id.pb(j);
            }
        }
        for(int j = 0; j < (1 << (int)id.size()); j++) {
            c[j] = d[j] = 0;
        }
        for(int j = 1; j <= n; j++) {
            int msk = 0;
            int _ = 0;
            for(int k : id) {
                if((b[j] >> k) & 1) {
                    msk |= 1 << _;
                }
                _++;
            }
            d[msk]++;
        }
        for(int j = 0; j < (int)id.size(); j++) {
            for(int k = 0; k < (1 << (int)id.size()); k++) {
                if((k >> j) & 1) {
                    
                }else {
                    d[k] += d[k + (1 << j)];
                }
            }
        }
        for(int j = 0; j < (1 << (int)id.size()); j++) {
            if (d[j] >= (n + 1) / 2 && __builtin_popcount(j) > cur) {
                cur = __builtin_popcount(j);
                ans = 0;
                for(int k = 0; k < (int)id.size(); k++) {
                    if((j >> k) & 1) ans |= 1ll << id[k];
                }
            }
        }
    }
    for (int i = 1; i <= m; ans >>= 1, i++)
        printf("%d", (int)(ans & 1));
    printf("\n");
}