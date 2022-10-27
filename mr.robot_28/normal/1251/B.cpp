#include<bits/stdc++.h>
using namespace std;
bool cmp(string a, string b)
{
	return a.size() < b.size();
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q;
	cin >> q;
	while(q--)
	{
		int n;
		cin >> n;
		vector <string> A(n);
		int cnt1 = 0, cnt2 = 0;
		for(int i = 0; i < n; i++)
		{
			cin>> A[i];
			for(int j = 0; j < A[i].size(); j++)
			{
				if(A[i][j] == '0')
				{
					cnt1++;
				}
				else
				{
					cnt2++;
				}
			}
		}
		int ans = 0;
		sort(A.begin(), A.end(), cmp);
		for(int i = 0; i < n; i++)
		{
			if(A[i].size() % 2 == 0)
			{
				int k = A[i].size();
				k -= min(cnt1 - cnt1 % 2, k);
				cnt1 -= min(cnt1 - cnt1 %2, int(A[i].size()));
				int e = min(cnt2 - cnt2 % 2, k);
				cnt2 -= min(cnt2 - cnt2 % 2, k);
				k -= e;
				if(k == 0)
				{
					ans++;
				}
				else
				{
					break;
				}
			}
			else
			{
				int k = A[i].size();
				if(cnt1 % 2 == 1)
				{
					k--;
					cnt1--;
				}
				else if(cnt2 % 2 == 1)
				{
					k--;
					cnt2--;
				}
				else if(cnt1 > 0)
				{
					cnt1--;
					k--;
				}
				else if(cnt2 > 0)
				{
					cnt2--;
					k--;
				}
				if(k % 2 != 0){
					break;
				}
				k -= min(cnt1 - cnt1 % 2, k);
				cnt1 -= min(cnt1 - cnt1 %2, int(A[i].size()) - 1);
				int e = min(cnt2 - cnt2 % 2, k);
				cnt2 -= min(cnt2 - cnt2 % 2, k);
				k -= e;
				if(k == 0)
				{
					ans++;
				}
				else
				{
					break;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}