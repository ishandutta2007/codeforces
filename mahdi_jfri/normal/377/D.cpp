#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;

int l[maxn] , v[maxn] , r[maxn] , n , res;

pair<ll , ll> x[maxn];

int lazy[maxn * 4];
pair<int , int> mx[maxn * 4];

set<pair<int , int> > st;

int low(int a)
{
	pair<ll , ll> b = {a , -1};
	return lower_bound(x , x + n , b) - x;
}

int upp(int a)
{
	pair<ll , ll> b = {a , maxn};
	return upper_bound(x , x + n , b) - x;
}


void shift(int s , int e , int v)
{
	if(e - s >= 2 && lazy[v])
	{
		lazy[2 * v] += lazy[v];
		mx[2 * v].first += lazy[v];
		lazy[2 * v + 1] += lazy[v];
		mx[2 * v + 1].first += lazy[v];
	}
	lazy[v] = 0;
}

void build(int s , int e , int v)
{
	if(e - s < 2)
	{
		mx[v] = {0 , s};
		return;
	}
	int m = (s + e) / 2;
	build(s , m , 2 * v);
	build(m , e , 2 * v + 1);
	mx[v] = max(mx[2 * v] , mx[2 * v + 1]);
}

void add(int l , int r , int val , int s , int e , int v)
{
	if(l <= s && e <= r)
	{
		lazy[v] += val;
		mx[v].first += val;
		return;
	}
	if(r <= s || e <= l)
		return;
	shift(s , e , v);
	int m = (s + e) / 2;
	add(l , r , val , s , m , 2 * v);
	add(l , r , val , m , e , 2 * v + 1);
	mx[v] = max(mx[2 * v] , mx[2 * v + 1]);
}

pair<int , int> get(int l , int r , int s , int e , int v)
{
	if(l <= s && e <= r)
		return mx[v];
	if(r <= s || e <= l)
		return {0 , -1};
	shift(s , e , v);
	int m = (s + e) / 2;
	return max(get(l , r , s , m , 2 * v) , get(l , r , m , e , 2 * v + 1));
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> l[i] >> v[i] >> r[i];
		x[i] = {v[i] , i};
	}
	pair<int , int> node1;
	sort(x , x + n);
	build(0 , n , 1);
	for(int i = 0; i < n; i++)
	{
		int k = x[i].second;
		while(!st.empty() && (*st.begin()).first < v[k])
		{
			int x = st.begin() -> second;
			add(low(l[x]) , upp(v[x]) , -1 , 0 , n , 1);
			st.erase(st.begin());
		}
		add(low(l[k]) , upp(v[k]) , 1 , 0 , n , 1);
		pair<int , int> tmp = get(low(l[k]) , upp(v[k]) , 0 , n , 1);
		if(res < tmp.first)
		{
			node1 = {tmp.second , i};
			res = tmp.first;
		}
		st.insert({r[k] , k});
	}
	cout << res << endl;
	for(int i = 0; i < n; i++)
	{
		int k = x[i].second;
		if(x[i].first >= x[node1.first].first && x[i].first <= x[node1.second].first && l[k] <= x[node1.first].first && r[k] >= x[node1.second].first)
			cout << k + 1 << " ";
	}
	cout << endl;
}