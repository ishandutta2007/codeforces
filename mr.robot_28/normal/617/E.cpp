#include <bits/stdc++.h>

using namespace std;
int W[1 << 20];
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	vector <int> A(n);
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	int t = sqrt(n) + 1;
	vector <int> pref(n + 1);
	for(int i = 1; i <= n; i++)
	{
		pref[i] = pref[i - 1] ^ A[i - 1];
	}
	vector <pair <pair <int, int>,pair <int, int> > > quest;
	for(int i = 0; i < m; i++)
	{
		int l, r;
		cin >> l >> r;
		l--;
		r++;
		quest.push_back({{l / t, r}, {l, i}});
	}
	sort(quest.begin(), quest.end());
	vector <long long> rezult(m);
	long long ans = 0;
	for(int i = 0; i < quest.size(); i++)
	{
		if(i == 0 || quest[i].first.first != quest[i - 1].first.first)
		{
			if(i != 0){
				for(int j = quest[i - 1].second.first; j < quest[i - 1].first.second; j++)
				{
					W[pref[j]] = 0;
				}
			}
			ans = 0;
			for(int j = quest[i].second.first; j < quest[i].first.second; j++)
			{
				ans += W[k ^ pref[j]];
				W[pref[j]]++;
			}
		}
		else
		{
			for(int j = quest[i - 1].first.second; j < quest[i].first.second; j++)
			{
				ans += W[k ^ pref[j]];
				W[pref[j]]++;
			}
			if(quest[i - 1].second.first < quest[i].second.first)
			{
				for(int j = quest[i - 1].second.first; j < quest[i].second.first; j++)
				{
					W[pref[j]]--;
					ans -= W[pref[j] ^ k];
				}
			}
			else
			{
				for(int j = quest[i - 1].second.first - 1; j >= quest[i].second.first; j--)
				{
					ans += W[k^ pref[j]];
					W[pref[j]]++;
				}
			}
		}
		rezult[quest[i].second.second] = ans;
	}
	for(int i = 0; i < m; i++)
	{
		cout << rezult[i] << "\n";
	}
	return 0;
}