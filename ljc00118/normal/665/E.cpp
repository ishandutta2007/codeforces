#include <bits/stdc++.h>
#define CIOS ios::sync_with_stdio(false);
#define For(i, a, b) for(register int i = a; i <= b; i++)
#define Forr(i, a, b) for(register int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
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

const int N = 1e6 + 5;

int a[N], s[N], trie[N * 30][2], siz[N * 30];
int n, k, tot = 0; ll ans;

void ins(int x) {
	int rt = 0; siz[rt]++;
	for(register int i = 29; i >= 0; i--) {
		int now = ((x >> i) & 1);
		if(!trie[rt][now]) trie[rt][now] = ++tot;
		rt = trie[rt][now]; siz[rt]++;
	}
}

int qry(int rt, int dep, int x, int sum) {
	if(sum >= k) return siz[rt];
	if(sum + (1 << (dep + 1)) - 1 < k) return 0;
	if(dep == -1) return 0;
	int now = ((x >> dep) & 1) ^ 1, ans = 0;
	if(trie[rt][now]) ans += qry(trie[rt][now], dep - 1, x, sum ^ (1 << dep));
	if(trie[rt][now ^ 1]) ans += qry(trie[rt][now ^ 1], dep - 1, x, sum);
	return ans;
}

int main() {
	read(n); read(k);
	for(register int i = 1; i <= n; i++) read(a[i]), s[i] = s[i - 1] ^ a[i];
	for(register int i = n; i >= 0; i--) ins(s[i]), ans += (ll)qry(0, 29, s[i], 0);
	cout << ans << endl;
	return 0;
}