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
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int a[200011], f[300001], o[300001];
long long g[300011], v[300011];

inline void inc(long long a[], int x, long long y) {
	for (; x <= 300000; x += x & (-x))
		a[x] += y;
}

long long calc(long long a[], int x) {
	long long res = 0;
	for (; x; x -= x & (-x))
		res += a[x];
	return res;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	long long ans = 0;
	//long long ans1 = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] <= 1000) {
			ans += f[a[i]];
			++o[a[i]];
		} else {
			for (int j = 0; ; j++) {
				int L = max(1, j * a[i]), R = min(300000, (j + 1) * a[i] - 1);
				long long A = calc(g, R) - calc(g, L - 1);
				long long B = calc(v, R) - calc(v, L - 1);
				ans += B - A * j * a[i];
				if (R == 300000)
					break;
			}
		}
		for (int j = 1; j <= 1000; j++)
			f[j] += a[i] % j;
		inc(v, a[i], a[i]);
		inc(g, a[i], 1);
		
		//-----
		
		//for (int j = 1; j < i; j++)
		//	ans1 += a[j] % a[i];
		
		/*if (ans != ans1) {
			printf("1 %lld %lld\n", ans, ans1);
			return 0;
		}*/
	
		
		//printf("1 %lld\n", ans);
		
		ans += 1LL * a[i] * (calc(g, 300000) - calc(g, a[i]));
		//printf("2 %lld\n", ans);
		
		for (int j = 1; j <= 300; j++) {
			int L = a[i] / (j + 1) + 1, R = a[i] / j;
			if (R < L)
				continue;
			if (L > R)
				break;
			long long A = calc(g, R) - calc(g, L - 1);
			long long B = calc(v, R) - calc(v, L - 1);
			ans += A * a[i] - B * j;
		}
		
		//printf("3 %lld\n", ans);
		
		for (int j = 1; a[i] / j > 300; j++)
			ans += 1LL * (a[i] % j) * o[j];
		
		//for (int j = 1; j < i; j++)
		//	ans1 += a[i] % a[j];
			
		/*if (ans != ans1) {
			printf("2 %d %d %lld %lld\n", i, a[i], ans, ans1);
			return 0;
		}*/
		printf("%lld ", ans);
	}
	printf("\n");
}