#include <bits/stdc++.h>
using namespace std;
vector <vector <int> > tree, pref1;
signed main() {
 //   ios::sync_with_stdio(false);
 //   cin.tie(0);
    int n, m;
    cin >> n >> m;
    long long l, r;
    cin >> l >> r;
    pref1.resize(max(n, m) + 1);
    for(int i = 1; i <= max(n, m); i++)
    {
    	int j = i;
    	while(j <= max(n, m))
    	{
    		pref1[j].push_back(i);
    		j += i;
		}
	}
	set <pair <int, int> > st;
	tree.resize(4 * m + 4);
	int L = m + 1;
	int R = m;
	for(int i = 1; i <= n; i++)
	{
		long long L1 = (l + i - 1) / i;
		long long R1 = r / i;
		R1 = min(R1, 1LL * m);
		while(L > L1)
		{
			L--;
			for(int j = 0; j < pref1[L].size(); j++)
			{
				st.insert({pref1[L][j], L});
			}
		}
		while(R > R1)
		{
			for(int j = 0; j < pref1[R].size(); j++)
			{
				st.erase({pref1[R][j], R});
			}
			R--;
		}
		vector <int> mass;
		if(L <= R && st.size() != 0)
		{
			for(int j = 0; j < pref1[i].size(); j++)
			{
				set <pair <int, int> > :: iterator it;
				it = st.lower_bound({pref1[i][j] + 1, 0});
				if(it != st.end())
				{
					if(1LL * i / pref1[i][j] * (it -> first) <= n)
					{
						mass.push_back(it -> second);
						mass.push_back(1LL * i / pref1[i][j] * (it -> first));
						mass.push_back(1LL * it -> second / (it -> first) * pref1[i][j]);
						break;
					}
				}
			}
			if(mass.size() == 0)
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << i << " " << mass[0] << " " << mass[1] << " " << mass[2] << "\n";
			}
		}
		else
		{
			cout << -1 << "\n";
		}
	}
    return 0;
}