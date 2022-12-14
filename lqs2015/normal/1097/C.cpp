#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
const int maxn=500005;
int n,mn,all,cnt[1111111],ans;
string s[111111];
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>s[i];
	for (int i=1;i<=n;i++)
	{
		all=0;mn=1e9;
		for (int j=0;j<s[i].size();j++)
		{
			if (s[i][j]=='(') 
			{
				all++;
			 } 
			 else all--;
			 mn=min(mn,all);
		}
		if (all<=0 && mn<all) continue;
		if (all>0 && mn<0) continue;
		cnt[all+maxn]++;
	}
	for (int i=0;i<=maxn-1;i++) ans+=min(cnt[i],cnt[2*maxn-i]);
	ans+=(cnt[maxn]/2);
	cout<<ans<<endl;
	return Accepted;
}