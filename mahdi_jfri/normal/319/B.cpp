#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+20;
int a[maxn],b[maxn],dp[maxn];
int main()
{
    int n;
	cin>>n;
	int j=0,ans=0;
	for (int i=0;i<n;i++)
	{
		cin>>a[i];
		while (j > 0 && a[b[j-1]]<a[i])
		{
                dp[i]=max(dp[i],dp[b[j-1]]);
                j--;
		}
		if (j == 0)
            dp[i]=maxn;
		else
            ans=max(ans,++dp[i]);
		b[j]=i;
		j++;
	}
	cout<<ans;
}