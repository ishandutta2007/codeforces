#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;
const int sq = maxn;

map<pair<string , string> , int> ans;

map<string , int> mp;

int id = 1 , res;

vector<int> pos[maxn];

void handle(int pt1 , int sz1 , int pt2 , int sz2)
{
	res = min(res , max(pt1 + sz1 , pt2 + sz2) - min(pt1 , pt2));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;
	int n = s.size();

	for(int i = 0; i < n; i++)
		for(int j = 1; j <= 4 && i + j <= n; j++)
		{
			string tmp = s.substr(i , j);

			if(!mp[tmp])
				mp[tmp] = id++;

			pos[mp[tmp]].pb(i);
		}

	int q;
	cin >> q;

	while(q--)
	{
		string a , b;
		cin >> a >> b;

		pair<string , string> tmp = {a , b} , pmt = {b , a};

		if(ans[tmp])
		{
			cout << ans[tmp] << endl;
			continue;
		}

		if(!mp[a] || !mp[b])
		{
			ans[tmp] = ans[pmt] = -1;
			cout << -1 << endl;
			continue;
		}

		res = n;
		int i = mp[a] , j = mp[b];

		if(pos[i].size() > pos[j].size())
			swap(i , j) , swap(a , b);

		if(sq <= pos[i].size())
		{
			int pt = 0;

			for(auto x : pos[i])
			{
				while(pt < (int)pos[j].size() && pos[j][pt] < x)
					pt++;

				if(pt < (int)pos[j].size())
					handle(pos[j][pt] , b.size() , x , a.size());
				if(pt)
					handle(pos[j][pt - 1] , b.size() , x , a.size());
			}
		}
		else
			for(auto x : pos[i])
			{
				int k = lower_bound(pos[j].begin() , pos[j].end() , x) - pos[j].begin();

				if(k < (int)pos[j].size())
					handle(pos[j][k] , b.size() , x , a.size());
				if(k)
					handle(pos[j][k - 1] , b.size() , x , a.size());
			}

		ans[tmp] = ans[pmt] = res;
		cout << res << endl;
	}

}