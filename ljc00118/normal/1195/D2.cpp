#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
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

    void clear() { *this = hash_map_t(mod); }

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

const int N = 1e5 + 5, md = 998244353;

inline int add(int x, int y) {
	x += y;
	if(x >= md) x -= md;
	return x;
}

inline int sub(int x, int y) {
	x -= y;
	if(x < 0) x += md;
	return x;
}

inline int mul(int x, int y) { return 1ll * x * y % md; }

int a[N][15], len[N], cnt[15];
int n, ans;

int main() {
	read(n);
	for(register int i = 1; i <= n; i++) {
		int x; read(x);
		while(x) {
			a[i][++len[i]] = x % 10;
			x /= 10;
		}
		++cnt[len[i]];
	}
	for(register int i = 1; i <= n; i++) {
		for(register int j = 1; j <= 10; j++) {
			int now = 0;
			if(len[i] >= j) {
				int pw = 1;
				for(register int k = 2; k <= j * 2; k += 2) {
					now = add(now, mul(pw, a[i][k / 2]));
					pw = mul(100, pw);
				}
				for(register int k = j + 1; k <= len[i]; k++) {
					now = add(now, mul(pw, a[i][k]));
					pw = mul(10, pw);
				}
			} else {
				int pw = 1;
				for(register int k = 2; k <= len[i] * 2; k += 2) {
					now = add(now, mul(pw, a[i][k / 2]));
					pw = mul(100, pw);
				}
			}
			ans = add(ans, mul(now, cnt[j]));
		}
	}
	for(register int i = 1; i <= n; i++) {
		for(register int j = 1; j <= 10; j++) {
			int now = 0;
			if(len[i] >= j) {
				int pw = 10;
				for(register int k = 2; k <= j * 2; k += 2) {
					now = add(now, mul(pw, a[i][k / 2]));
					if(k != j * 2) pw = mul(100, pw);
					else pw = mul(10, pw);
				}
				for(register int k = j + 1; k <= len[i]; k++) {
					now = add(now, mul(pw, a[i][k]));
					pw = mul(10, pw);
				}
			} else {
				int pw = 10;
				for(register int k = 2; k <= len[i] * 2; k += 2) {
					now = add(now, mul(pw, a[i][k / 2]));
					pw = mul(100, pw);
				}
			}
			ans = add(ans, mul(now, cnt[j]));
		}
	}
	print(ans, '\n');
    return 0;
}