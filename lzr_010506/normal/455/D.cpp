#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ls rt << 1
#define rs rt << 1 | 1
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define eps 1e-9
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int N = 1e5 + 10;
struct treap
{
	int sz, rd, key;
	treap *L,*R,*fa,*cor;
	treap(int _key = 0) : sz(1), key(_key), L(NULL), R(NULL), fa(NULL), cor(NULL), rd(rand()){}
};
treap aa[2 * N];
int cnt=0;
treap *val[N], *ori = NULL;

inline int size(treap* x)
{
	return x ? x -> sz : 0;
}

inline void update(treap* x)
{
	if(x) x -> sz = size(x -> L) + size(x -> R) + 1;
}

treap* merge(treap* a,treap* b)
{
	if(a == NULL || b == NULL) return a ? a : b;
	if(a -> rd > b -> rd)
	{
		a -> R = merge(a -> R, b);
		if(a -> R) a -> R -> fa = a;
		update(a);
		return a;
	}
	else
	{
		b -> L = merge(a, b -> L);
		if(b -> L) b -> L -> fa = b;
		update(b);
		return b;
	}
}

void split(treap* x,int k,treap*& a,treap*& b)
{
	if(!x)
	{
		a = NULL;
		b = NULL;
		return;
	}
	if(size(x -> L) < k)
	{
		a = x;
		split(x -> R, k - size(x -> L) - 1, a -> R, b);
		if(a -> R) a -> R -> fa = a;
		update(a);
	}
	else
	{
		b = x;
		split(x -> L, k, a, b -> L);
		if(b -> L) b -> L -> fa = b;
		update(b);
	}
}

int find_index(treap* x)
{
	bool left = true;
	int r = 0;
	while(x != NULL)
	{
		if(left) r += size(x -> L) + 1;
		if(x -> fa && x -> fa -> R == x) left = true;
		else left = false;
		x = x -> fa;
	}
	return r;
}

int cal(int r,int k)
{
	treap *a = val[k], *b;
	int ans = 0;
	while(a != NULL)
	{
		if(find_index(a -> cor) <= r) ans += size(a -> L) + 1, a = a -> R;
		else a = a -> L;
	}
	return ans;
}


int main()
{
	int n, lastans = 0, l, r, k = 0, t, x, q;
	n = read();
	rep(i, 1, n) val[i] = NULL;
	rep(i, 0, n - 1)
	{
		x = read();
		ori = merge(ori, &(aa[cnt ++] = treap(x)));
		q = rand();
		val[x] = merge(val[x], &(aa[cnt ++] = treap(x)));
		q = rand();
		aa[cnt - 1].cor = &aa[cnt - 2];
		aa[cnt - 2].cor = &aa[cnt - 1];
	}
	q = read();
	while(q --)
	{
		t = read();
		l = read();
		r = read();
		if(t == 2) scanf("%d",&k);
		l = (l + lastans - 1) % n + 1;
		r = (r + lastans - 1) % n + 1;
		k = (k + lastans - 1) % n + 1;
		if(l > r) swap(l, r);
		if(t == 1)
		{
			treap *a,*b,*c,*d;
			int k, vl,vr;
			split(ori, l - 1, a, b);
			split(b, r - l + 1, c, b);
			split(c, r - l, c, d);
			k = d -> key;
			ori = merge(a, merge(d, merge(c, b)));
			vl = cal(l - 1, k) + 1;
			vr = cal(r, k);
			split(val[k], vl - 1, a, b);
			split(b, vr - vl + 1, c, b);
			split(c, vr - vl, c, d);
			val[k] = merge(a, merge(d, merge(c, b)));
		}
		else printf("%d\n", lastans = cal(r, k) - cal(l - 1, k));
	}
	return 0;
}