#include <bits/stdc++.h>
#define X first
#define Y second
#define ll long long
#define pii pair<int, int>
using namespace std;

const int N = 2e5 + 100;
ll T[4 * N];
int n, m;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
struct Node
{
	int x, id, cnt;
	ll len;
	bool operator<(const Node & b )const
	{
		return x < b.x;
	}
} a[N];

void build(int rt, int l, int r)
{
	if(l == r)
	{
		T[rt] = a[l].x + a[l].len;
		return;
	}
	int mid = l + ((r - l) >> 1), L = (rt << 1) | 1, R = L + 1;
	build(L, l, mid);
	build(R, mid + 1, r);
	T[rt] = max(T[L], T[R]);
}
int get(int rt, int l, int r, int v)
{
	if(l == r)
	{
		if(T[rt] >= v && a[l].x <= v) return l;
		return -1;
	}
	int mid = l + ((r - l) >> 1), L = (rt << 1) | 1, R = L + 1;
	if(T[L] >= v) return get(L, l, mid, v);
	else if(T[R] >= v) return get(R, mid + 1, r, v);
	return -1;
}
void add(int rt, int l, int r, int i, int v)
{
	if(l == r)
	{
		a[l].cnt ++;
		T[rt] += v;
		a[l].len += v;
		return ;
	}
	int mid= l + ((r - l) >> 1), L = (rt << 1) | 1, R = L + 1;
	if(i <= mid) add(L, l, mid, i, v);
	else add(R, mid + 1, r, i, v);
	T[rt] = max(T[L], T[R]);
}

multiset<pii> st;

bool cmp(Node &a,Node &b)
{
	return a.id < b.id;
}

int main()
{
	n = read();
	m = read();
	for(int i = 0; i < n; i ++)
	{
		a[i].x = read();
		a[i].len = read();
		a[i].id = i;
		a[i].cnt = 0;
	}
	sort(a, a + n);
	build(0, 0, n - 1);
	for(int i = 0; i < m; i ++)
	{
		int p, b;
		p = read();
		b = read();
		int j = get(0, 0, n - 1, p);
		if(j == -1)
		{
			st.insert(make_pair(p, b));
			continue;
		}
		add(0, 0, n - 1, j, b);
		ll mx = a[j].x + a[j].len;
		while(1)
		{
			auto it = st.lower_bound(make_pair(a[j].x, -1e9));
			if(it == st.end() || it -> X > mx)break;
			add(0, 0, n - 1, j, it -> Y);
			mx += it -> Y;
			st.erase(it);
		}
	}
	sort(a, a + n, cmp);
	for(int i = 0; i < n; i ++)
		printf("%d %I64d\n", a[i].cnt, a[i].len);
	return 0;
}