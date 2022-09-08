#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define CIOS ios::sync_with_stdio(false);
#define For(i, a, b) for(register int i = a; i <= b; i++)
#define Rof(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> ";
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename T>
inline void read(T &f) {
	f = 0; T fu = 1; char c = getchar();
	while(c < '0' || c > '9') {if(c == '-') fu = -1; c = getchar();}
	while(c >= '0' && c <= '9') {f = (f << 3) + (f << 1) + (c & 15); c = getchar();}
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

const int N = 2e6 + 5;

map <int, int> pre;
int fa[N], ch[N][2], val[N], sum[N], rev[N], st[N], n, m, len, lastans, tot;

int isroot(int u) { return ch[fa[u]][0] != u && ch[fa[u]][1] != u; }

int get(int u) { return ch[fa[u]][1] == u; }

void update(int u) { sum[u] = sum[ch[u][0]] ^ sum[ch[u][1]] ^ val[u]; }

void pushdown(int u) {
    if(rev[u]) {
        swap(ch[u][0], ch[u][1]);
        rev[ch[u][0]] ^= 1;
        rev[ch[u][1]] ^= 1;
        rev[u] ^= 1;
    }
}

void rotate(int u) {
    int old = fa[u], oldd = fa[old], k = get(u);
    if(!isroot(old)) ch[oldd][get(old)] = u; fa[u] = oldd;
    ch[old][k] = ch[u][k ^ 1]; fa[ch[u][k ^ 1]] = old;
    fa[old] = u; ch[u][k ^ 1] = old;
    update(old); update(u);
}

void splay(int u) {
    st[len = 1] = u;
    for(int i = u; !isroot(i); i = fa[i]) st[++len] = fa[i];
    for(int i = len; i >= 1; i--) pushdown(st[i]);
    for(; !isroot(u); rotate(u)) if(!isroot(fa[u])) rotate(get(u) == get(fa[u]) ? fa[u] : u);
}

void access(int u) {
    for(int i = 0; u; i = u, u = fa[u]) {
        splay(u);
        ch[u][1] = i;
        update(u);
    }
}

void makeroot(int u) {
    access(u);
    splay(u);
    rev[u] ^= 1;
}

int f[N];
int find(int u) { return f[u] == u ? u : f[u] = find(f[u]); }

void link(int u, int v) {
//	cerr << "link : " << u << " " << v << endl;
	f[find(u)] = find(v);
    makeroot(u);
    fa[u] = v;
}

void cut(int u, int v) {
    makeroot(u);
    access(v);
    splay(v);
    if(fa[u] != v || ch[u][1]) return;
    fa[u] = ch[v][0] = 0;
    update(v);
}

void change(int u, int x) {
    val[u] = x;
    access(u);
    splay(u);
}

int query(int u, int v) {
    makeroot(u);
    access(v);
    splay(v);
    return sum[v];
}

int main() {
    read(n);
    for(register int i = 1; i <= n; i++) {
    	int opt, l, r;
    	read(opt); read(l); read(r); l ^= lastans; r ^= lastans; if(l > r) swap(l, r); l--;
//    	cerr << "DEBUG >>> " << l << " " << r << endl; 
    	if(!pre.count(l)) pre[l] = ++tot, f[tot] = tot;
    	if(!pre.count(r)) pre[r] = ++tot, f[tot] = tot;
    	l = pre[l]; r = pre[r];
//    	cerr << "DEBUG >>> " << l << " " << r << endl; 
    	if(opt == 1) {
    		int x; read(x); x ^= lastans;
    		if(find(l) != find(r)) {
				val[++tot] = x; f[tot] = tot; sum[tot] = x;
				link(l, tot); link(tot, r);
			}
		} else {
			if(find(l) != find(r)) {
				print(-1, '\n');
				lastans = 1;
			} else {
				makeroot(l); access(r); splay(r);
				print(lastans = sum[r], '\n');
			}
		}
	}
    return 0;
}