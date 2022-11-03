#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define plus plushhhhhhhhhh
const int maxn = 1e5 + 20;
vector<int> pos[maxn];
ll now = maxn , plus , res;
void go(int x , int p)
{
	int k = lower_bound(pos[x].begin() , pos[x].end() , p)-pos[x].begin();
	ll z = ((ll)pos[x].size() - k);
	if(z == 0)
		return;
	plus -= z;
	p = pos[x].back();
	while(z--)
		pos[x].pop_back();
	if(!plus)
	     return;
	if(pos[x].empty())
	{
		while(pos[x].empty())
			x++;
		now = x;
		go(x , p);
	}
}
int main()
{
	ll n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		pos[a].pb(i);
		now = min(now , (ll)a);
	}
	plus = n;
	while(plus)
	{
		res += plus;
		while(pos[now].empty())
			now++;
		go(now , pos[now][0]);
	}
	cout << res << endl;
}