#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;

int a[maxn] , b[maxn] , lazy[maxn * 4];

void update(int x , int y , int k , int s , int e , int v)
{
	if(y - 1 <= s && e <= y + k - 1)
	{
		lazy[v] = s - y + 1 + x;
		return;
	}
	if(y + k - 1 <= s || e <= y - 1)
		return;
	int m = (s + e) / 2;
	if(lazy[v])
	{
		lazy[2 * v] = lazy[v];
		lazy[2 * v + 1] = lazy[v] + m - s;
		lazy[v] = 0;
	}
	update(x , y , k , s , m , 2 * v);
	update(x , y , k , m , e , 2 * v + 1);
}

int get(int p , int s , int e , int v)
{
	if(e - s < 2)
		return lazy[v];
	if(lazy[v])
		return p - s + lazy[v];
	int m = (s + e) / 2;
	if(p < m)
		return get(p , s , m , 2 * v);
	else
		return get(p , m , e , 2 * v + 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n , m;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++)
		cin >> b[i];
	while(m--)
	{
		int t;
		cin >> t;
		if(t == 1)
		{
			int x , y , k;
			cin >> x >> y >> k;
			update(x , y , k , 0 , n , 1);
		}
		else
		{
			int p;
			cin >> p;
			p--;
			int res = get(p , 0 , n , 1);
			if(!res)
				cout << b[p] << endl;
			else
				cout << a[res - 1] << endl;
		}
	}
}