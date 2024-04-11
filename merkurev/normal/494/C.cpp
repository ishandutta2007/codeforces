#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;


const int maxn = 100500;
int val[maxn];

const int maxq = 5005;
vector <int> ch[maxq];
int l[maxq], r[maxq];
double prob[maxq];
int p[maxq];
int numP[maxq];
int _id[maxq];


bool isP(int pp, int y)
{
	return l[pp] <= l[y] && r[y] <= r[pp];
}
bool eq(int x, int y)
{
	return l[x] == l[y] && r[x] == r[y];
}

int st[maxq];
double a[maxq][maxq];
double psum[maxq][maxq];

	
	void calcPsum(int id)
	{
		psum[id][0] = a[id][0];
		for (int i = 1; i < maxq; i++)
			psum[id][i] = psum[id][i - 1] + a[id][i];
	}
	double getPLE(int id, int x)
	{
		if (x < st[id] )
			return 0;
		if (x >= st[id] + maxq)
			return 1;
		return psum[id][x - st[id] ];
	}
	void addOne(int id, double px)
	{
		for (int i = maxq; i >= 1; i--)
		{
			a[id][i] = a[id][i] * (1. - px) + a[id][i - 1] * px;
		}
		a[id][0] *= (1. - px);
		calcPsum(id);
	}
	void Add (int id, int oi)
	{
		int nst = max(st[id], st[oi] );
		double prv = 0;
		for (int i = 0; i < maxq; i++)
		{
			a[id][i] = getPLE(id, nst + i) * getPLE(oi, nst + i) - prv;
			prv += a[id][i];
		}
		st[id] = nst;
		calcPsum(id);
	}
	double getME(int id)
	{
		double ans = 0;
		for (int i = 0; i < maxq; i++)
		{
			ans += (st[id] + i) * a[id][i];
		}
		return ans;
	}
void print(int id)
{
	fprintf(stderr, "st = %d\n", st[id] );
	for (int i = 0; i < 10; i++)
		fprintf(stderr, "%.4lf ", a[id][i] );
	fprintf(stderr, "\n");
}


vector <pair<int, int> > c;
void getAns(int v)
{
	int L = l[v];
	int R = r[v];
	
	for (int i = 0; i < (int) ch[v].size(); i++)
	{
		int nv = ch[v][i];
		c.push_back(make_pair(l[nv], r[nv] ) );
	}
	c.push_back(make_pair(L - 1, L) );
	c.push_back(make_pair(R, R + 1) );	
	sort(c.begin(), c.end() );
	
	int mx = 0;
	for (int i = 0; i < (int) c.size() - 1; i++)
	{
		int _a = c[i].second;
		int b = c[i + 1].first;
		for (int j = _a; j < b; j++)
			mx = max(mx, val[j] );
	}
	c.clear();

	a[v][0] = 1;
	st[v] = mx;
	calcPsum(v);

	for (int i = 0; i < (int) ch[v].size(); i++)
	{
		int nv = ch[v][i];
		getAns(nv);
		Add(v, nv);
	}

	addOne(v, prob[v] ); 
}


int main()
{
#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
#endif
	
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++)
		scanf("%d", &val[i] );
	for (int i = 0; i < q; i++)
	{
		scanf("%d%d%lf", &l[i], &r[i], &prob[i] );
		l[i]--;
	}

	for (int i = 0; i < q; i++)
	{
		p[i] = -2;
		for (int j = 0; j < q; j++)
			if (isP(j, i) && !eq(i, j) )
				numP[i]++;
	}
	for (int i = 1; i <= q; i++)
	{
		int x = -1;
		for (int j = 0; j < q; j++)
		{
			if (p[j] != -2 || numP[j] != 0)
				continue;
			x = j;
			break;
		}
		int par = q;
		for (int j = 0; j < q; j++)
		{
			if (p[j] == -2)
				continue;
			if (!isP(j, x) )
				continue;
			if (_id[j] > _id[par] )
				par = j;
		}
		for (int j = 0; j < q; j++)
		{
			if (isP(x, j) && !eq(x, j) )
				numP[j]--;
		}
		_id[x] = i;
		p[x] = par;
		
		ch[par].push_back(x);
	}

	l[q] = 0;
	r[q] = n;
	getAns(q);
	printf("%.10lf\n", getME(q) );

	return 0;
}