#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

int b[maxn] , c[maxn] , d[maxn] , dist[maxn] , par[maxn];

pair<int , int> a[maxn] , mn[maxn * 4];

void build(int s , int e , int v)
{
	if(e - s < 2)
	{
		mn[v] = {b[a[s].second] , s};
		return;
	}
	int m = (s + e) / 2;

	build(s , m , 2 * v);
	build(m , e , 2 * v + 1);

	mn[v] = min(mn[2 * v] , mn[2 * v + 1]);
}

void rem(int p , int s , int e , int v)
{
	if(e - s < 2)
	{
		mn[v] = {2e9 , s};
		return;
	}

	int m = (s + e) / 2;
	if(p < m)
		rem(p , s , m , 2 * v);
	else
		rem(p , m , e , 2 * v + 1);

	mn[v] = min(mn[2 * v] , mn[2 * v + 1]);
}

pair<int , int> get(int l , int r , int s , int e , int v)
{
	if(l <= s && e <= r)
		return mn[v];
	if(r <= s || e <= l)
		return {2e9 , 0};

	int m = (s + e) / 2;
	return min(get(l , r , s , m , 2 * v) , get(l , r , m , e , 2 * v + 1));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> a[i].first >> b[i] >> c[i] >> d[i];
		a[i].second = i;
	}

	sort(a , a + n);

	build(0 , n , 1);

	queue<pair<pair<int , int> , int> > q;
	q.push({{0 , 0} , n});

	memset(dist , -1 , sizeof dist);
	memset(par , -1 , sizeof par);
	dist[n] = 0;

	while(!q.empty())
	{
		auto v = q.front();
		q.pop();

		int R = upper_bound(a , a + n , make_pair(v.first.first , maxn)) - a;

		while(get(0 , R , 0 , n , 1).first <= v.first.second)
		{
			auto tmp = get(0 , R , 0 , n , 1);
			rem(tmp.second , 0 , n , 1);

			int k = a[tmp.second].second;
			pair<pair<int , int> , int> x = {{c[k] , d[k]} , k};
			dist[k] = dist[v.second] + 1;
			par[k] = v.second;

			q.push(x);
		}
	}

	if(dist[n - 1] == -1)
		return cout << -1 << endl , 0;

	stack<int> st;
	int tmp = n - 1;
	while(tmp != -1)
	{
		st.push(tmp);
		tmp = par[tmp];
	}

	cout << dist[n - 1] << endl;

	st.pop();
	while(!st.empty())
		cout << st.top() + 1 << " " , st.pop();
	cout << endl;
}