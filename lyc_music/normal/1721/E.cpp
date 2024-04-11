#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N 1000005
using namespace std;
string st;
int dp[N][26];
int kmp[N];
int q;
void BellaKira()
{
	cin>>st;
	int n=st.size();
	st=' '+st;
	for (int i=1,j=0;i<=n;i++)
	{
		if (i!=1)
		{
			while (j&&st[j+1]!=st[i]) j=kmp[j];
			kmp[i]=j;
			if (st[kmp[i]+1]==st[i]) kmp[i]++,j++;
		}
		for (int k=0;k<26;k++)
		{
			if (i!=n&&st[i+1]==char('a'+k)) dp[i][k]=i;
			else dp[i][k]=dp[kmp[i]][k];
			// cout<<i<<","<<k<<" "<<dp[i][k]<<'\n';
		}
		// cout<<i<<" "<<kmp[i]<<endl;
	}
	cin>>q;
	while (q--)
	{
		string st1;
		cin>>st1;
		int m=st1.size();
		int j=kmp[n];
		st+=st1;
		for (int i=n+1,j=kmp[n];i<=n+m;i++)
		{
			while (j&&st[j+1]!=st[i]) 
			{
				if (j<=n) 
				{
					j=dp[j][st[i]-'a'];
					break;
				}
				j=kmp[j];
			}
			kmp[i]=j;
			if (st[kmp[i]+1]==st[i]) kmp[i]++,j++;
			cout<<kmp[i]<<" ";
		}
		cout<<'\n';
		while (m--) st.pop_back();
	}
			
}
signed main()
{
	IOS;cin.tie(0);
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}