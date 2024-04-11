#include <bits/stdc++.h>
using namespace std;
int cnt[26][200005];
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n,k,ans=0;
		string s;
		cin >> n >> k >> s;
		for (int i=0;i<n;i++)
		{
			int idx=i%k;
			if (idx>(k-1)/2)
			idx=k-idx-1;
			cnt[s[i]-'a'][idx]++;
		}
		for (int i=0;i<k;i++)
		{
			int sum=0,mx=0;
			for (int j=0;j<26;j++)
			{
				sum+=cnt[j][i];
				mx=max(mx,cnt[j][i]);
				cnt[j][i]=0;
			}
			ans+=sum-mx;
		}
		cout << ans << endl;
	}
}