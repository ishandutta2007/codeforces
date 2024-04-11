#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 5e3 + 20;
const int maxnum = 1e6 + 20;
int a[maxn] , t[maxnum] , visited[maxn] , ti = 1;
pair<int , int> p[maxnum][20];
vector<int> A[maxn];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n , k;
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(a , a + n);
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
		{
			ll x = a[j] - a[i];
			if(t[x] > k * (k + 1) / 2)
				continue;
			p[x][t[x]] = {i , j};
			t[x]++;
		}
	for(int i = 1; i < maxnum; i++)
	{
		ll x = 0;
		for(int j = i; j < maxnum && x <= (k + 1) * k / 2; j += i)
			x += t[j];
		if(x > (k + 1) * k / 2)
			continue;
		vector<int> st;
		for(int j = i; j < maxnum; j += i)
			for(int z = 0; z < t[j]; z++)
			{
				pair<int, int> x = p[j][z];
				st.pb(x.first);
				st.pb(x.second);
				A[x.first].pb(x.second);
				A[x.second].pb(x.first);
			}
		x = 0;
		for(auto v : st)
		{
			if(visited[v] != ti)
			{
				visited[v] = ti;
				for(auto u : A[v])
					visited[u] = ti;
				x += (int)A[v].size();
			}
			A[v].clear();
		}
		if(x <= k)
		{
			cout << i << endl;
			return 0;
		}
		ti++;
	}
}