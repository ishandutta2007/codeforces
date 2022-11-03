#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define bit(a , b) (((a)>>(b))&1)

const int maxn = 1e5 + 20;
const int maxb = 62;

ll b[maxn];

vector<int> hb[maxb] , shits[maxn];

int t[maxb] , h[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> ans;

	for(int i = 0; i < n; i++)
	{
		cin >> b[i];

		for(int j = 0; j < maxb; j++)
			if(bit(b[i] , j))
				t[j]++ , shits[i].pb(j);

		hb[shits[i].back()].pb(i);
	}

	for(int i = 0; i < n; i++)
	{
		bool f = 0;
		for(int j = 0; j < maxb; j++)
			if(t[j] % 2 == 1 && !hb[j].empty())
			{
				int ind = hb[j].back();
				ans.pb(ind);
				
				for(auto x : shits[ind])
					t[x]--;
				hb[j].pop_back();
				f = 1;
				break;
			}

		if(!f)
			return cout << "No" << endl ,0;
	}
	cout << "Yes" << endl;

	reverse(ans.begin() , ans.end());

	for(auto x : ans)
		cout << b[x] << " ";
	cout << endl;

}