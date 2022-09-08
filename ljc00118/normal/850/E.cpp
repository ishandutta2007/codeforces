#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> " << endl;
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

template <typename T>
struct hash_map_t {
    vector <T> v, val, nxt;
    vector <int> head;
    int mod, tot, lastv;
    T lastans;
    bool have_ans;

    hash_map_t (int md = 0) {
        head.clear(); v.clear(); val.clear(); nxt.clear(); tot = 0; mod = md;
        nxt.resize(1); v.resize(1); val.resize(1); head.resize(mod);
        have_ans = 0;
    }

    bool count(int x) {
        int u = x % mod;
        for(register int i = head[u]; i; i = nxt[i]) {
            if(v[i] == x) {
                have_ans = 1;
                lastv = x;
                lastans = val[i];
                return 1;
            }
        }
        return 0;
    }

    void ins(int x, int y) {
        int u = x % mod;
        nxt.push_back(head[u]); head[u] = ++tot;
        v.push_back(x); val.push_back(y);
    }

    int qry(int x) {
        if(have_ans && lastv == x) return lastans;
        count(x);
        return lastans;
    }
};

bool is_prime(int x) {
	for(register int i = 2; i * i <= x; i++) {
		if(x % i == 0) return 0;
	}
	return 1;
}

const int N = 1 << 20, md = 1e9 + 7, inv2 = (md + 1) >> 1;

int a[N], b[N], cnt[N], pw2[25];
char c[N];
int n, ans;

void fwt(int *a, int opt) {
	for(register int mid = 1; mid < (1 << n); mid <<= 1) {
		for(register int i = 0; i < (1 << n); i += (mid << 1)) {
			for(register int j = 0; j < mid; j++) {
				int x = a[i + j], y = a[i + j + mid];
				a[i + j] = x + y; a[i + j + mid] = x - y;
				if(opt == -1) {
					a[i + j] = 1ll * a[i + j] * inv2 % md;
					a[i + j + mid] = 1ll * a[i + j + mid] * inv2 % md;
				}
			}
		}
	}
}

int main() {
	read(n); scanf("%s", c);
	for(register int i = 0; i < (1 << n); i++) a[i] = c[i] - '0', b[i] = a[i] ^ 1;
	fwt(a, 1); fwt(b, 1);
	for(register int i = 0; i < (1 << n); i++) a[i] = 1ll * a[i] * b[i] % md;
	fwt(a, -1);
	for(register int i = 1; i < (1 << n); i++) cnt[i] = cnt[i >> 1] + (i & 1);
	pw2[0] = 1;
	for(register int i = 1; i <= 20; i++) pw2[i] = pw2[i - 1] * 2 % md;
	for(register int i = 0; i < (1 << n); i++) ans = (1ll * pw2[cnt[i]] * a[i] + ans) % md;
	ans = 1ll * ans * 3 % md;
	cout << ans << endl;
    return 0;
}