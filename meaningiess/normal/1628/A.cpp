#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[200010],b[200010];
vector<int> p[200010];
int main()
{
	int T;cin>>T;
	while (T--)
	{
		int n,i,ans=0;cin>>n;p[0].clear();
		for (i=1;i<=n;i++) p[i].clear(),cin>>a[i];
		for (i=1;i<=n;i++) p[a[i]].push_back(i);
		for (i=0;i<=n;i++) p[i].push_back(n+1);
		int nw=1,o=0,lst=1;
		while (nw<=n)
		{
			int tp1=*lower_bound(p[o].begin(),p[o].end(),lst),tp2=*lower_bound(p[o].begin(),p[o].end(),nw+1);
			if (tp1!=tp2)
			{
				o++;continue;
			}
			else if (tp2==n+1)
			{
				b[++ans]=o;o=0;lst=nw=nw+1;
			}
			else nw=tp2;
		}
		cout<<ans<<endl;
		for (i=1;i<=ans;i++) cout<<b[i]<<' ';cout<<endl;
	}
}