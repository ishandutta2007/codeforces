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

const int N = 1e6 + 5;

ll s1[N << 1], ans, minn = -1;
int s2[N << 1];
int a[N];
int n, x, y, maxn;

int main() {
	read(n); read(x); read(y);
	for(register int i = 1; i <= n; i++) {
		read(a[i]);
		maxn = max(maxn, a[i]);
		s1[a[i]] += a[i];
		++s2[a[i]];
	}
	for(register int i = 1; i <= maxn * 2; i++) {
		s1[i] += s1[i - 1];
		s2[i] += s2[i - 1];
	}
	int xay = x / y;
	for(register int d = 2; d <= max(2, maxn); d++) {
		ans = 0;
		for(register int l = 1, r = d; l <= maxn; l += d, r += d) {
			if(r - xay >= l) ans += ((ll)(s2[r] - s2[r - xay - 1]) * r - (s1[r] - s1[r - xay - 1])) * y + (ll)(s2[r - xay - 1] - s2[l - 1]) * x;
			else ans += ((ll)(s2[r] - s2[l - 1]) * r - (s1[r] - s1[l - 1])) * y;
		}
		if(~minn) minn = min(minn, ans); else minn = ans;
	}
	cout << minn << endl;
    return 0;
} //