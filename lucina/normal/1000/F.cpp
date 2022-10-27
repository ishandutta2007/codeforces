#include<bits/stdc++.h>

using namespace std;

const int INF = int(1e9);
const int N = 500001;

typedef pair<int, int> pt;

#define x first
#define y second
#define mp make_pair

const int M = 60 * N;

pt bufp[M];
int lf[M];
int rg[M];
int szt = 0;

int newnode(pt val)
{
	bufp[szt] = val;
	return szt++;
}

int newnode(int l, int r)
{
 	lf[szt] = l;
	rg[szt] = r;
	if(bufp[l].x < bufp[r].x)
	    bufp[szt] = bufp[l];
	else
	    bufp[szt] = bufp[r];
	return szt++;
}

pt curans;

void query(int t, int l, int r, int L, int R)
{
 	if(L >= R)
		return;
	if(l == L && r == R)
	{
	    if(bufp[t].x < curans.x)
	        curans = bufp[t];
	    return;
	}
	int mid = (l + r) >> 1;
	query(lf[t], l, mid, L, min(mid, R));
	query(rg[t], mid, r, max(mid, L), R);
}

int update(int t, int l, int r, int pos, int val)
{
 	if(l == r - 1)
		return newnode(mp(val, pos));
	else
	{
	 	int mid = (l + r) >> 1;
		if(pos < mid)
			return newnode(update(lf[t], l, mid, pos, val), rg[t]);
		else
			return newnode(lf[t], update(rg[t], mid, r, pos, val));
	}
}

int build(int l, int r)
{
 	if(l == r - 1)
		return newnode(mp(INF, l));
	else
	{
	 	int mid = (l + r) >> 1;
		return newnode(build(l, mid), build(mid, r));
	}
}

int last[N];

int main()
{
 	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	vector<int> left(n);
	for(int i = 0; i < N; i++)
	    last[i] = -1;
	for(int i = 0; i < n; i++)
	{
	 	left[i] = last[a[i]];
		last[a[i]] = i;
	}

	vector<int> T(n + 1);
	T[0] = build(0, n);
	for(int i = 0; i < n; i++)
	{
		int cur = T[i];
		if(left[i] != -1)
			cur = update(cur, 0, n, left[i], INF);
		cur = update(cur, 0, n, i, left[i]);
		T[i + 1] = cur;	
	}                      
	
	int q;
	scanf("%d", &q);
	for(int i = 0; i < q; i++)
	{
	 	int l, r;
		scanf("%d %d", &l, &r);
		--l;
		curans = mp(INF, 0);
		query(T[r], 0, n, l, r);
		if(curans.x < l)
			printf("%d\n", a[curans.y]);
		else
			printf("0\n");
	}
}