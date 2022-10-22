#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[100010],b[100010],c[100010],e[100010];
priority_queue<int> q;
int main()
{
	int T;cin>>T;
	while (T--)
	{
		int n,k,i,d=0,ans;cin>>n>>k;ans=n;
		while (!q.empty()) q.pop();
		for (i=0;i<=n;i++) c[i]=0;
		for (i=1;i<=n;i++) {cin>>a[i];if (a[i]<=n) c[a[i]]++;}
		sort(a+1,a+n+1);
		int cnt=1,tot=0;
		e[0]=0;
		for (i=1;i<=n;i++) e[i]=e[i-1]+(c[i-1]==0);
		for (i=n;i && a[i]>n;i--) if (a[i]!=a[i-1])
		{
			b[++tot]=cnt;cnt=1;d++;
		}
		else cnt++;
		//cout<<d<<endl;
		int s=0;
		for (i=1;i<=tot;i++)
		{
			//cout<<b[i]<<' ';
			s+=b[i];
			q.push(b[i]);
			while (s>k) s-=q.top(),q.pop();
		}
		//cout<<endl;
		for (i=n;i>=0;i--)
		{
			s+=c[i];
			if (c[i])
			{
				d++;
				q.push(c[i]);
				while (s>k) s-=q.top(),q.pop();
			}
			//cout<<i<<' '<<d<<' '<<q.size()<<' '<<e[i]<<endl;
			if (e[i]<=k) ans=min(ans,d-(int)q.size());
		}
		cout<<ans<<endl;
	}
}