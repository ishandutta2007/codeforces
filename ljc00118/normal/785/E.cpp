#include <bits/stdc++.h>
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

#define update(u) if(u -> left -> size) u -> size = u -> left -> size + u -> right -> size, u -> value = u -> right -> value
#define new_Node(a, b, c, d) (&(*st[cnt++] = Node(a, b, c, d)))
#define merge(a, b) new_Node(a -> size + b -> size, b -> value, a, b)
#define ratio 4

struct Node {
	int size, value;
	Node *left, *right;
	Node (int a, int b, Node *c, Node *d) : size(a), value(b), left(c), right(d) {}
	Node () {}
}*root[200005], *null, *st[8000005], t[8000005];

int a[200005];
ll ans = 0;
int n, m, cnt;

void maintain(Node *u) {
	if(u -> left -> size > u -> right -> size * ratio) u -> right = merge(u -> left -> right, u -> right), st[--cnt] = u -> left, u -> left = u -> left -> left;
	if(u -> right -> size > u -> left -> size * ratio) u -> left = merge(u -> left, u -> right -> left), st[--cnt] = u -> right, u -> right = u -> right -> right;
}

void ins(Node *u, int x) {
	if(u -> size == 1) u -> left = new_Node(1, min(u -> value, x), null, null), u -> right = new_Node(1, max(u -> value, x), null, null);
	else ins(x > u -> left -> value ? u -> right : u -> left, x);
	update(u); maintain(u);
}

void earse(Node *u, int x) {
	if(u -> left -> size == 1 && u -> left -> value == x) st[--cnt] = u -> left, st[--cnt] = u -> right, *u = *u -> right;
	else if(u -> right -> size == 1 && u -> right -> value == x) st[--cnt] = u -> left, st[--cnt] = u -> right, *u = *u -> left;
	else earse(x > u -> left -> value ? u -> right : u -> left, x);
	update(u); maintain(u);
}

int find1(Node *u, int x) {
	if(u -> size == 1) return x > u -> value;
	return x > u -> left -> value ? find1(u -> right, x) + u -> left -> size : find1(u -> left, x); 
}

int find2(Node *u, int x) {
	if(u -> size == 1) return x < u -> value;
	return x < u -> left -> value ? find2(u -> left, x) + u -> right -> size : find2(u -> right, x);
}

int lowbit(int x) {return x & -x;}

int main() {
	null = new Node(0, 0, 0, 0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) root[i] = new Node(1, INT_MAX, null, null);
	for(int i = 0; i < 8000005; i++) st[i] = &t[i];
	for(int t = 1; t <= n; t++) {
		a[t] = t;
		for(int i = t; i <= n; i += lowbit(i)) ins(root[i], t);
	}
	while(m--) {
		int x, y; read(x); read(y);
		if(x == y) {
			printf("%I64d\n", ans);
			continue;
		}
		for(int i = x; i; i -= lowbit(i)) ans -= (ll)find2(root[i], a[x]) - 1ll;
		for(int i = n; i; i -= lowbit(i)) ans -= (ll)find1(root[i], a[x]);
		for(int i = x - 1; i; i -= lowbit(i)) ans += (ll)find1(root[i], a[x]);
		for(int i = x; i <= n; i += lowbit(i)) earse(root[i], a[x]);
		for(int i = y; i; i -= lowbit(i)) ans -= (ll)find2(root[i], a[y]) - 1ll;
		for(int i = n; i; i -= lowbit(i)) ans -= (ll)find1(root[i], a[y]);
		for(int i = y - 1; i; i -= lowbit(i)) ans += (ll)find1(root[i], a[y]);
		for(int i = y; i <= n; i += lowbit(i)) earse(root[i], a[y]);
		swap(a[x], a[y]);
		for(int i = x; i <= n; i += lowbit(i)) ins(root[i], a[x]);
		for(int i = x; i; i -= lowbit(i)) ans += (ll)find2(root[i], a[x]) - 1ll;
		for(int i = n; i; i -= lowbit(i)) ans += (ll)find1(root[i], a[x]);
		for(int i = x - 1; i; i -= lowbit(i)) ans -= (ll)find1(root[i], a[x]);
		for(int i = y; i <= n; i += lowbit(i)) ins(root[i], a[y]);
		for(int i = y; i; i -= lowbit(i)) ans += (ll)find2(root[i], a[y]) - 1ll;
		for(int i = n; i; i -= lowbit(i)) ans += (ll)find1(root[i], a[y]);
		for(int i = y - 1; i; i -= lowbit(i)) ans -= (ll)find1(root[i], a[y]);
		printf("%I64d\n", ans);
	}
	return 0;
}