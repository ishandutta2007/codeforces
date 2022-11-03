#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e4 + 20;
const int maxb = 19;

bitset<maxn> a[maxb] , res;

vector<int> obj[maxn * 4];

void add(int l , int r , int x , int s , int e , int v)
{
	if(l <= s && e <= r)
	{
		obj[v].pb(x);
		return;
	}
	if(r <= s || e <= l)
		return;

	int m = (s + e) / 2;

	add(l , r , x , s , m , 2 * v);
	add(l , r , x , m , e , 2 * v + 1);
}

void dfs(int s , int e , int v , int h)
{
	a[h][0] = 1;
	for(auto shit : obj[v])
		a[h] |= (a[h] << shit);

	if(e - s < 2)
	{
		res |= a[h];
		return;
	}

	int m = (s + e) / 2;

	a[h + 1] = a[h];
	dfs(s , m , 2 * v , h + 1);
	
	a[h + 1] = a[h];
	dfs(m , e , 2 * v + 1 , h + 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , q;
	cin >> n >> q;

	for(int i = 0; i < q; i++)
	{
		int l , r , x;
		cin >> l >> r >> x;
		l--;

		add(l , r , x , 0 , n , 1);
	}

	dfs(0 , n , 1 , 0);

	vector<int> ans;
	for(int i = 1; i <= n; i++)
		if(res[i])
			ans.pb(i);

	cout << ans.size() << endl;
	for(auto x : ans)
		cout << x << " ";
	cout << endl;

}