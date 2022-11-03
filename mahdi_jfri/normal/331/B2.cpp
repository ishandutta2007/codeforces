#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define lb(a) ((a)&(-(a)))

const int maxn = 3e5 + 20;

int fen[maxn] , pos[maxn] , a[maxn];

void add(int p , int val)
{
	for(p++; p < maxn; p += lb(p))
		fen[p] += val;
}

int get(int p)
{
	int res = 0;
	for(p++; 0 < p; p -= lb(p))
		res += fen[p];
	return res;
}

void okl(int p)
{
	if(p)
		add(p , -(pos[p - 1] > pos[p]));
}

void addl(int p)
{
	if(p)
		add(p , pos[p - 1] > pos[p]);
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		a[i]--;
		pos[a[i]] = i;
	}
	for(int i = 1; i < n; i++)
		addl(i);
	int q;
	scanf("%d", &q);
	while(q--)
	{
		int type;
		scanf("%d", &type);
		if(type == 1)
		{
			int x , y;
			scanf("%d%d", &x, &y);
			x-- , y--;
			printf("%d\n", get(y) - get(x) + 1);
		}
		else
		{
			int x , y;
			scanf("%d%d", &x, &y);
			x-- , y--;
			swap(a[x] , a[y]);
			x = a[x];
			y = a[y];
			if(x > y)
				swap(x , y);
			if(y == x + 1)
			{
				okl(x + 1);
				okl(y + 1);
				okl(x);
				swap(pos[x] , pos[y]);
				addl(x + 1);
				addl(y + 1);
				addl(x);
			}
			else
			{
				okl(x + 1);
				okl(x);
				okl(y + 1);
				okl(y);
				swap(pos[x] , pos[y]);
				addl(x + 1);
				addl(x);
				addl(y + 1);
				addl(y);
			}
		}
	}
}