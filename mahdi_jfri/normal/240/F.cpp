#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
const int maxs = 30;

int t[maxn * 4][maxs] , lazy[maxn * 4][maxs];

int num[30];

string a;

void shift(int s , int e , int v , int i)
{
	if(e - s >= 2 && lazy[v][i] != -1)
	{
		int m = (s + e) / 2;
		lazy[2 * v][i] = lazy[v][i];
		if(lazy[v][i])
			t[2 * v][i] = (m - s);
		else
			t[2 * v][i] = 0;
		lazy[2 * v + 1][i] = lazy[v][i];
		if(lazy[v][i])
			t[2 * v + 1][i] = (e - m);
		else
			t[2 * v + 1][i] = 0;
	}
	lazy[v][i] = -1;
}

void build(int s , int e , int v)
{
	if(e - s < 2)
	{
		for(int i = 0; i < 26; i++)
			lazy[v][i] = -1;
		t[v][a[s] - 'a'] = 1;
		return;
	}
	int m = (s + e) / 2;
	build(s , m , 2 * v);
	build(m , e , 2 * v + 1);
	for(int i = 0; i < 26; i++)
		t[v][i] = t[2 * v][i] + t[2 * v + 1][i] , lazy[v][i] = -1;
}

void update(int l , int r , int x , int val , int s , int e , int v)
{
	if(l >= r)
		return;
	if(l <= s && e <= r)
	{
		lazy[v][x] = val;
		if(val)
			t[v][x] = e - s;
		else
			t[v][x] = 0;
		return;
	}
	if(r <= s || e <= l)
		return;
	shift(s , e , v , x);
	int m = (s + e) / 2;
	update(l , r , x , val , s , m , 2 * v);
	update(l , r , x , val , m , e , 2 * v + 1);
	t[v][x] = t[2 * v][x] + t[2 * v + 1][x];
}

int get(int l , int r , int x , int s , int e , int v)
{
	if(l >= r)
		return 0;
	if(l <= s && e <= r)
		return t[v][x];
	if(r <= s || e <= l)
		return 0;
	shift(s , e , v , x);
	int m = (s + e) / 2;
	return get(l , r , x , s , m , 2 * v) + get(l , r , x , m , e , 2 * v + 1);
}

int main()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int n , q;
	cin >> n >> q >> a;
	build(0 , n , 1);
	while(q--)
	{
		int l , r;
		cin >> l >> r;
		l--;
		int x = 0;
		for(int i = 0; i < 26; i++)
		{
			num[i] = get(l , r , i , 0 , n , 1);
			x += num[i] % 2;
		}
		if(x > 1)
			continue;
		int sum = 0;
		for(int i = 0; i < 26; i++)
		{
			if(!num[i])
				continue;
			update(l , r , i , 0 , 0 , n , 1);
			update(l + sum , l + sum + num[i] / 2 , i , 1 , 0 , n , 1);
			update(r - sum - num[i] / 2 , r - sum , i , 1 , 0 , n , 1);
			if(num[i] % 2)
				update(l + (r - l) / 2 , l + (r - l) / 2 + 1 , i , 1 , 0 , n , 1);
			sum += num[i] / 2;
		}
	}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < 26; j++)
			if(get(i , i + 1 , j , 0 , n , 1))
			{
				cout << (char)('a' + j);
				break;
			}
}