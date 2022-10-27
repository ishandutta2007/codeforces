#include <bits/stdc++.h>
                  
using namespace std;
vector <pair <int, int> > ax, mx;
vector <int> g[1000][7];
long long crossproduct(pair <int, int> a, pair <int, int> b, pair <int, int> c)
{
	return 1LL *(a.first - b.first) * (c.second - b.second) - 1LL *(a.second - b.second) * (c.first - b.first);
}
long long dotproduct(pair <int, int> a, pair <int, int> b, pair <int, int> c)
{
	return 1LL * (a.first - b.first) * (c.first - b.first) + 1LL * (a.second - b.second) * (c.second - b.second);
}
int n, k;
vector <bool> used, vis;
int idx;
vector <int> vec, q;

bool flag ;
bool check()
{
	int it1 = 0;
	q[0] = (idx);
	int cnt = 1;
	vis[idx] = true;
	stack <int> st;
	st.push(idx);
	for(int it = 0; it < k; it++)
	{
		int v = q[it1];
		it1--;
		for(int i = 0; i < g[v][vec[it]].size() && i < k + 1; i++)
		{
			if(!vis[g[v][vec[it]][i]])
			{
				cnt++;
				vis[g[v][vec[it]][i]] = true;
				st.push(g[v][vec[it]][i]);
				it1++;
				if(it1 == k || cnt > k)
				{
					while(st.size() > 0){
						vis[st.top()] = false;
						st.pop();
					}
					return false;
				}
				q[it1] = (g[v][vec[it]][i]);
			}
		}
		if(it1 == -1)
		{
			while(st.size() > 0)
			{
				vis[st.top()] = false;
				st.pop();
			}
			return true;
		}
	}
	while(st.size() > 0)
	{
		vis[st.top()] = false;
		st.pop();
	}
	return false;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> k >> n;
	ax.resize(k);
	q.resize(k);
	mx.resize(n);
	used.resize(k);
	vis.resize(n);
	vec.resize(k);
	for(int i = 0; i < k; i++)
	{
		cin >> ax[i].first >> ax[i].second;
	}
	for(int i = 0; i < n; i++)
	{
		cin >> mx[i].first >> mx[i].second;
	}
	for(int i = 0; i < k; i++)
	{
		for(int j = 0; j < n; j++)
		{
			for(int d = 0; d < n; d++)
			{
				if(d == j)
				{
					continue;
				}
				if(crossproduct(ax[i], mx[j], mx[d]) == 0 && dotproduct(ax[i], mx[j], mx[d]) < 0)
				{
					g[d][i].push_back(j);
				}
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		flag = false;
		idx = i;
		for(int j = 0; j< k; j++)
		{
			used[j] = false;
		}
		for(int j = 0; j < k; j++){
			vec[j] = j;
		}
		do{
			if(check())
			{
				flag = true;
				break;
			}
		}while(next_permutation(vec.begin(), vec.end()));
		if(flag)
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}