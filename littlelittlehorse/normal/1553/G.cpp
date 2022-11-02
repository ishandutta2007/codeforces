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
const int N = 1000033;
const int L = 1000000;
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int isprime[N], primes[N], a[N], id[N], rela[N], blg[N];
int getr(int x) {
    int p = x;
    while(rela[p] != p) p = rela[p];
    int p1 = p; p = x;
    while(rela[p] != p) {
        int p2 = rela[p];
        rela[p] = p1;
        p = p2;
    }
    return p1;
}
vector<int> fac[155555], e[155555];
void calc(int x, vector<int> & v) {
	int y = x;
	for(int i = 2; i * i <= x; i++) {
		if(y % i == 0) {
			v.pb(id[i]);
			while(y % i == 0) y /= i;
		}
	}
	if(y > 1) v.pb(id[y]);
}

int main() {
	int np = 0;
	fill(isprime + 2, isprime + L + 1, true);
	primes[0] = inf;
	for(int i = 2; i <= L; i++) {
		if(isprime[i]) {
			primes[++np] = i;
			id[i] = np;
		}
		for(int j = 1; j <= np && primes[j] * i <= L && i % primes[j - 1]; j++) {
			isprime[i * primes[j]] = false;
		}
	}
	//cout << np << endl;
	int n, q;
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= np; i++) {
		rela[i] = i;
	}

	
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		calc(a[i], fac[i]);
		for(int j = 0; j < (int)fac[i].size(); j++) {
			int x = getr(fac[i][j]);
			int y = getr(fac[i][0]);
			if(x != y) rela[x] = y;
		}
		blg[i] = getr(fac[i][0]);
		calc(a[i] + 1, fac[i]);
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < (int)fac[i].size(); j++) {
			fac[i][j] = getr(fac[i][j]);
		}
		sort(all(fac[i]));
		fac[i].resize(unique(all(fac[i])) - fac[i].begin());
		for(int j = 0; j < (int)fac[i].size(); j++) {
			for(int k = 0; k < j; k++) {
				e[fac[i][j]].pb(fac[i][k]);
				e[fac[i][k]].pb(fac[i][j]);
			}
		}
	}
	for(int i = 1; i <= np; i++) {
		sort(all(e[i]));
	}
	for(int i = 1; i <= n; i++) {
		blg[i] = getr(blg[i]);
	}
	for(int i = 1; i <= q; i++) {
		int x, y;
		int ans;
		scanf("%d%d", &x, &y);
		if(blg[x] == blg[y]) {
			ans = 0;
		}else {
			auto itr = lower_bound(all(e[blg[x]]), blg[y]);
			if(itr != e[blg[x]].end() && *itr == blg[y]) {
				ans = 1;
			}else ans = 2;
		}
		printf("%d\n", ans);
	}
}