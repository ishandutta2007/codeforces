#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
map<int , int> mp;
int tah = 1 , g[maxn] , p[maxn] , t[maxn] , res[maxn];
vector<int> on_x[maxn * 3] , on_y[maxn * 3];
bool cmp(int x , int y)
{
	return p[x] < p[y];
}
int main()
{
	int n , w , h;
	cin >> n >> w >> h;
	for(int i = 0; i < n; i++)
	{
		cin >> g[i] >> p[i] >> t[i];
		if(g[i] == 1)
		{
			int x = p[i] - t[i];
	//		cout << x << endl;
			if(!mp[x])
				mp[x] = tah++;
			on_x[mp[x]].pb(i);
		}
		else
		{
			int x = p[i] - t[i];
	//		cout << x << endl;
			if(!mp[x])
				mp[x] = tah++;
			on_y[mp[x]].pb(i);
		}
	}
	for(int i = 1; i < tah; i++)
	{
		sort(on_x[i].begin() , on_x[i].end() , cmp);
		sort(on_y[i].begin() , on_y[i].end() , cmp);
//		for(auto x : on_x[i])
//			cout << p[x] << " ";
//		cout << endl;
//		for(auto x : on_y[i])
//			cout << p[x] << " ";
//		cout << endl;
	}
	for(int i = 1; i < tah; i++)
	{
		for(int j = 0; j < on_x[i].size(); j++)
		{
			int sz = on_x[i].size() - j;
			if(sz <= on_y[i].size())
				res[on_x[i][j]] = on_y[i][sz - 1];
			else
				res[on_x[i][j]] = on_x[i][on_y[i].size() + j];
		}
		for(int j = 0; j < on_y[i].size(); j++)
		{
			int sz = on_y[i].size() - j;
			if(sz <= on_x[i].size())
				res[on_y[i][j]] = on_x[i][sz - 1];
			else
				res[on_y[i][j]] = on_y[i][on_x[i].size() + j];
		}
	}
	for(int i = 0; i < n; i++)
	{
		if(g[res[i]] == 1)
		{
			cout << p[res[i]] << " " << h << endl;
		}
		else
		{
			cout << w << " " << p[res[i]] << endl;
		}
	}
}