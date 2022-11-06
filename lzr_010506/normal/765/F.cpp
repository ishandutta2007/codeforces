#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
#define pb push_back
int n, a[N], w = 1100, mx = 1e9 / w, sm = sqrt(mx), q;
int A[N], B[N], C[N], id[N];
int Q, aa[N], ss[N], sn, bl;
int l[N], r[N], cnt[N * 10], c2[N];
int bk[N], bb[N][3], sb = 0, cm[N];

inline int min(int a, int b)
{
	if(a < b) return a;
	return b;
}

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = (x << 1) + (x << 3) + ch - '0'; ch = getchar(); }
	return x * f;
}
inline bool cmp(int a, int b)
{
	if(B[a] / bl != B[b] / bl)
		return(B[a] / bl < B[b] / bl);
	return(C[a] > C[b]);
}
inline void ins(int x, int k)
{
	if(x > mx || x < 0) return;
	cnt[x] += k; c2[x / sm] += k;
}
inline void del(int x)
{
	ins(aa[r[x]] - aa[x], -1);
	ins(aa[x] - aa[l[x]], -1);
	ins(aa[r[x]] - aa[l[x]], 1);
	++sb;
	bk[sb] = x;
	bb[sb][0] = aa[r[x]] - aa[x];
	bb[sb][1] = aa[x] - aa[l[x]];
	bb[sb][2] = aa[r[x]] - aa[l[x]];
	r[l[x]] = r[x];
	l[r[x]] = l[x];
}
#define Del(x) del(aid[x])
inline void rev()
{
	ins(bb[sb][0], 1);
	ins(bb[sb][1], 1);
	ins(bb[sb][2], -1);
	int x = bk[sb--];
	r[l[x]] = x; l[r[x]] = x;
}
inline int qmin()
{
	for(int i = 0; i <= sm + 1; i++)
	{
		if(!c2[i]) continue;
		for(int j = i * sm; j < i * sm + sm; j++)
			if(cnt[j]) return(j);
	}
}
int aidr[N], aid[N];
inline bool cmp2(int x, int y)
{
	return(a[x] < a[y]);
}
int main()
{
	n = read();
	for(int i = 1; i <= n; i++)
		aa[i] = a[i] = read(), aidr[i] = i;
	sort(aa + 1, aa + 1 + n);
	sort(aidr + 1, aidr + 1 + n, cmp2);
	for(int i = 1; i <= n; i++)
		aid[aidr[i]] = i;
	aa[0] = aa[n + 1] = 2e9;
	for(int i = 1; i <= n; i++)
	{
		l[i] = i - 1, r[i] = i + 1;
		ins(aa[i] - aa[i - 1], 1);
	}
	q = read();
	for(int i = 1; i <= q; i++)
	{
		B[i] = read(), C[i] = read();
		if(C[i] - B[i] <= w)
		{
			sn = 0;
			for(int p = B[i]; p <= C[i]; p++)
				ss[++sn] = a[p];
			sort(ss + 1, ss + 1 + sn);
			int minn = 1e9;
			for(int p = 2; p <= sn; p++)
				minn = min(minn, ss[p] - ss[p - 1]);
			A[i] = minn;
			continue;
		}
		id[++Q] = i;
	}
	bl = sqrt(n) * 0.5;
	if(bl < 1) bl = 1;
	sort(id + 1, id + 1 + Q, cmp);
	int bk = 1;
	for(int i = 1; i <= Q; i++)
	{
		int ls = i;
		for(int j = i; B[id[i]] / bl == B[id[j]] / bl; j++)
			ls = j;
		int cl = 1e9;
		for(int j = i; j <= ls; j++)
			cl = min(cl, B[id[j]]);
		for(int j = bk; j < cl; j++) Del(j);
		bk = cl;
		int r = n;
		for(int j = i; j <= ls; j++)
		{
			while(r > C[id[j]]) Del(r--);
			for(int p = cl; p < B[id[j]]; p++) Del(p);
			A[id[j]] = qmin();
			for(int p = cl; p < B[id[j]]; p++) rev();
		}
		for(int p = n; p > r; --p) rev();
		i = ls;
	}
	for(int i = 1; i <= q; i++)
		printf("%d\n", A[i]);
	return 0;
}