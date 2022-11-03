#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 5e5 + 20;

int a[maxn] , l[maxn] , r[maxn] , R[maxn] , ans[maxn];

vector<int> pos[maxn] , ln[maxn] , lq[maxn];

pair<int , int> seg[maxn * 4];

void Set(int p , int s , int e , int v)
{
	if(e - s < 2)
	{
		seg[v] = make_pair(r[s] , a[s]);
		return;
	}

	int m = (s + e) / 2;

	if(p < m)
		Set(p , s , m , 2 * v);
	else
		Set(p , m , e , 2 * v + 1);

	seg[v] = max(seg[2 * v] , seg[2 * v + 1]);
}

pair<int , int> get(int l , int r , int s , int e , int v)
{
	if(l <= s && e <= r)
		return seg[v];
	if(r <= s || e <= l)
		return make_pair(0 , 0);

	int m = (s + e) / 2;

	return max(get(l , r , s , m , 2 * v) , get(l , r , m , e , 2 * v + 1));
}

int main()
{
	int n;
	scanf("%d", &n);

	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		pos[a[i]].pb(i);
	}

	for(int i = 0; i < maxn; i++)
		for(int j = 0; j < (int)pos[i].size(); j++)
		{
			int k = pos[i][j];
			if(!j)
				l[k] = 0;
			else
				l[k] = pos[i][j - 1] + 1;

			if(j + 1 < (int)pos[i].size())
				r[k] = pos[i][j + 1];
			else
				r[k] = n;

			ln[l[k]].pb(k);
		}

	int q;
	scanf("%d", &q);

	for(int i = 0; i < q; i++)
	{
		int l;
		scanf("%d%d", &l, &R[i]);
		l--;

		lq[l].pb(i);
	}

	for(int i = 0; i < n; i++)
	{
		for(auto ind : ln[i])
			Set(ind , 0 , n , 1);

		for(auto ind : lq[i])
		{
			pair<int , int> tmp = get(i , R[ind] , 0 , n , 1);

			if(tmp.first >= R[ind])
				ans[ind] = tmp.second;
		}
	}

	for(int i = 0; i < q; i++)
		printf("%d\n", ans[i]);

}