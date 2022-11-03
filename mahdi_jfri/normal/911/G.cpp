#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int maxn = 2e5 + 20;
const int maxk = 1e2 + 20;

int t[maxn * 4][maxk] , a[maxn] , n;

void shift(int s , int e , int v)
{
	if(e - s >= 2)
		for(int i = 0; i < maxk; i++)
		{
			t[2 * v][i] = t[v][t[2 * v][i]];
			t[2 * v + 1][i] = t[v][t[2 * v + 1][i]];
		}
	for(int i = 0; i < maxk; i++)
		t[v][i] = i;
}

void update(int l , int r , int x , int y , int s , int e , int v)
{
	if(l <= s && e <= r)
	{
		for(int i = 0; i < maxk; i++)
			if(t[v][i] == x)
				t[v][i] = y;
		return;
	}
	if(r <= s || e <= l)
		return;
	shift(s , e , v);

	int m = (s + e) / 2;
	update(l , r , x , y , s , m , 2 * v);
	update(l , r , x , y , m , e , 2 * v + 1);
}

int get(int p , int s , int e , int v)
{
	if(e - s < 2)
		return t[v][a[s]];
	int m = (s + e) / 2;
	if(p < m)
		return t[v][get(p , s , m , 2 * v)];
	else
		return t[v][get(p , m , e , 2 * v + 1)];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for(int i = 0; i < maxn * 4; i++)
		for(int j = 0; j < maxk; j++)
			t[i][j] = j;

	int q;
	scanf("%d", &q);
	while(q--)
	{
		int l , r , x , y;
		scanf("%d%d%d%d", &l , &r, &x, &y);
		l--;
		update(l , r , x , y , 0 , n , 1);
	}
	for(int i = 0; i < n; i++)
		printf("%d ", get(i , 0 , n , 1));
	printf("\n");
}