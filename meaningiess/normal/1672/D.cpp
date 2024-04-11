#include<bits/stdc++.h>
#define ll long long
using namespace std;
int cnt[200010],a[200010],b[200010],nxt[200010];
vector<int> c[200010];
int main()
{
	int T;cin>>T;
	while (T--)
	{
		int n,i,flg=0;cin>>n;
		for (i=1;i<=n;i++) cin>>a[i];
		for (i=1;i<=n;i++) cin>>b[i];
		for (i=1;i<=n;i++) c[i].clear(),nxt[i]=i+1;
		nxt[n+1]=n+2;
		int las=0;
		for (i=1;i<=n;i++)
		{
			if (b[las]==b[i]) c[b[i]].push_back(las);
			else las=i;
		}
		for (i=1;i<=n;i++) reverse(c[i].begin(),c[i].end());
		int j=1;
		for (i=1;i<=n;i++)
		{
			if (j>n) {flg=1;break;}
			if (a[i]!=b[j])
			{
				while (!c[a[i]].empty() && c[a[i]].back()<j) c[a[i]].pop_back();
				if (c[a[i]].empty()) {flg=1;break;}
				int p=c[a[i]].back(),d=nxt[p];
				nxt[p]=nxt[d];c[a[i]].pop_back();
			}
			else j=nxt[j];
		}
		if (flg) puts("NO");else puts("YES");
	}
}