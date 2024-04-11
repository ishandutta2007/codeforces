#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
vector<int> in[maxn];
int out[maxn] , res[maxn];
set<int> st;
int main()
{
	int n , m;
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int a , b;
		cin >> a >> b;
		in[b].pb(a);
		out[a]++;
	}
	for(int i = 1; i <= n; i++)
		if(out[i] == 0)
			st.insert(-i);
	int now = n;
	while(!st.empty())
	{
		int x = *st.begin();
		st.erase(x);
		x *= -1;
		for(auto u : in[x])
		{
			out[u]--;
			if(!out[u])
				st.insert(-u);
		}
		res[x] = now;
		now--;
	}
	for(int i = 1; i <= n; i++)
		cout << res[i] << " ";
}