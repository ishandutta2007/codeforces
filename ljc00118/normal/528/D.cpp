#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define CIOS ios::sync_with_stdio(false);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> ";
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename T>
inline void read(T &f) {
	f = 0; T fu = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') fu = -1; c = getchar(); }
	while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
	f *= fu;
}

template <typename T>
void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x < 10) putchar(x + 48);
	else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
	print(x); putchar(t);
}

const int P = 998244353; 

inline int add(int x, int y) {
    x += y;
    if(x >= P) x -= P;
    return x;
}

inline int sub(int x, int y) {
    x -= y;
    if(x < 0) x += P;
    return x;
}

inline int mul(int x, int y) {
    return (ll)x * y % P;
}

inline int fpow(int x, int y) {
    int ans = 1;
    while(y) {
        if(y & 1) ans = mul(ans, x);
        y >>= 1; x = mul(x, x);
    }
    return ans;
}

namespace ntt {
    int base = 1, root = -1, maxbase = -1;
    vector <int> roots = {0, 1}, rev = {0, 1};
    
    void init() {
        int tmp = P - 1; maxbase = 0;
        while(!(tmp & 1)) {
            tmp >>= 1;
            maxbase++;
        }
        root = 2;
        while(1) {
            if(fpow(root, 1 << maxbase) == 1 && fpow(root, 1 << (maxbase - 1)) != 1) break;
            root++;
        }
    }
    
    void ensure_base(int nbase) {
        if(maxbase == -1) init();
        if(nbase <= base) return;
        assert(nbase <= maxbase);
        rev.resize(1 << nbase);
        for(register int i = 1; i < (1 << nbase); i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (nbase - 1));
        roots.resize(1 << nbase);
        while(base < nbase) {
            int z = fpow(root, 1 << (maxbase - base - 1));
            for(register int i = (1 << (base - 1)); i < (1 << base); i++) {
                roots[i << 1] = roots[i];
                roots[i << 1 | 1] = mul(roots[i], z);
            }
            base++;
        } 
    }
    
    void dft(vector <int> &a) {
        int n = a.size(), zeros = __builtin_ctz(n);
        ensure_base(zeros);
        int shift = base - zeros;
        for(register int i = 0; i < n; i++) if(i < (rev[i] >> shift)) swap(a[i], a[rev[i] >> shift]);
        for(register int mid = 1; mid < n; mid <<= 1) {
            for(register int i = 0; i < n; i += (mid << 1)) {
                for(register int j = 0; j < mid; j++) {
                    int x = a[i + j], y = mul(a[i + j + mid], roots[mid + j]);
                    a[i + j] = add(x, y); a[i + j + mid] = sub(x, y);
                }
            }
        }
    }
    
    vector <int> pmul(vector <int> a, vector <int> b, bool is_sqr = false) {
        int need = a.size() + b.size() - 1, nbase = 0;
        while((1 << nbase) < need) nbase++;
        ensure_base(nbase); int size = 1 << nbase;
        a.resize(size); dft(a); if(!is_sqr) b.resize(size), dft(b); else b = a;
        int inv = fpow(size, P - 2);
        for(register int i = 0; i < size; i++) a[i] = mul(a[i], mul(b[i], inv));
        reverse(a.begin() + 1, a.end()); dft(a); a.resize(need); return a;
    }
    
    vector <int> psqr(vector <int> a) { return pmul(a, a, 1); }
    
    vector <int> inv(vector <int> a, int size) {
    	if(size == 1) return vector <int> { fpow(a[0], P - 2) };
    	vector <int> b = inv(a, size >> 1); a = pmul(a, psqr(b)); b.resize(size);
    	for(register int i = 0; i < size; i++) b[i] = sub(add(b[i], b[i]), a[i]);
    	return b;
    }
    
    vector <int> pinv(vector <int> a) {
    	int nbase = 0; while((1 << nbase) < a.size()) nbase++;
    	return inv(a, 1 << nbase);
    }
}

const int N = 2e5 + 5;

vector <int> a, b;
char c[N], c2[N];
int s[N], ans[N], n, m, k;

int calc(int l, int r) {
	r = min(r, n);
	if(l <= 0) return s[r];
	return s[r] - s[l - 1];
}

int calc(char c) {
	if(c == 'A') return 1;
	if(c == 'C') return 2;
	if(c == 'T') return 3;
	return 4;
}

int main() {
	read(n); read(m); read(k);
	scanf("%s%s", c + 1, c2 + 1);
	for(register int t = 1; t <= 4; t++) {
		a.resize(n + 1, 0); b.resize(m + 1, 0);
		for(register int i = 1; i <= n; i++) {
			int val = (calc(c[i]) == t);
			s[i] = s[i - 1] + val;
		}
		for(register int i = 1; i <= m; i++) b[m - i + 1] = (calc(c2[i]) == t);
		for(register int i = 1; i <= n; i++) {
			if(calc(i - k, i + k)) a[i] = 1;
			else a[i] = 0;
		}
//		fprintf(stderr, "a : ");
//		for(register int i = 1; i <= n; i++) fprintf(stderr, "%d%c", a[i], i == n ? '\n' : ' ');
//		fprintf(stderr, "b : ");
//		for(register int i = 1; i <= m; i++) fprintf(stderr, "%d%c", b[i], i == m ? '\n' : ' ');
		a = ntt::pmul(a, b);
//		fprintf(stderr, "res : ");
//		for(register int i = 1; i <= n + m; i++) fprintf(stderr, "%d%c", a[i], i == n + m ? '\n' : ' ');
		for(register int i = m + 1; i <= n + m + 1; i++) ans[i - m] += a[i];
	}
	int sum = 0;
	for(register int i = 1; i <= n - m + 1; i++) sum += (ans[i] == m);
	print(sum, '\n');
	return 0;
}