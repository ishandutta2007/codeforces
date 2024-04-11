#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int maxn = 1e6 + 20;

int par[maxn] , a[maxn] , from[maxn] , to[maxn] , w[maxn] , sz[maxn];

ll res;

vector<int> v;

bool cmp(int x , int y)
{
	return w[x] < w[y];
}

int root(int v)
{
	return ((par[v] == -1)? v : par[v] = root(par[v]));
}

void merge(int v , int u)
{
	v = root(v);
	u = root(u);
	if(v == u)
		return;
	par[v] = u;
	res += 1LL * sz[v] * sz[u];
	sz[u] += sz[v];
}

ll f(int n)
{
	ll ans = 0;
	res = 0;
	memset(par , -1 , sizeof par);
	for(int i = 0; i < n; i++)
		sz[i] = 1;
	for(int i = 0; i < n - 1; i++)
		w[i] = max(a[from[i]] , a[to[i]]);
	
	sort(v.begin() , v.end() , cmp);

	for(int i = 0; i < n - 1; i++)
	{
		ll res1 = res;
		int j = i;
		while(j < n - 1 && w[v[j]] == w[v[i]])
			merge(from[v[j]] , to[v[j]]) , j++;
		ans += 1LL * (res - res1) * w[v[i]];
		i = j - 1;
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll ans = 0;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];

	for(int i = 0; i < n - 1; i++)
	{
		int v1 , u;
		cin >> v1 >> u;
		v1--;
		u--;
		from[i] = v1;
		to[i] = u;
		w[i] = max(a[v1] , a[u]);
		v.pb(i);
	}

	ans = f(n);
	for(int i = 0; i < n; i++)
		a[i] = -a[i];
	ans += f(n);
	
	cout << ans << endl;
}