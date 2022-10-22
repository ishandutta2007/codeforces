#include<bits/stdc++.h>
#define ll long long
using namespace std;
int b[100010],a[100010],c[100010];
vector<int> d[100010];
int main()
{
	int T;cin>>T;
	while (T--)
	{
		int n,i,tg=0;cin>>n;
		for (i=0;i<=n+1;i++) d[i].clear();
		for (i=1;i<=n;i++) {cin>>b[i];c[i]=b[i];if (!b[i]) tg=1;d[b[i]].push_back(i);}
		sort(c+1,c+n+1);c[n+1]=n+2;
		int k=n;
		for (i=1;i<=n;i++) if (c[i]!=c[i+1])
		{
			if (n-i>=c[i] && n-i<c[i+1]) {k=n-i;break;}
		}
		cout<<k<<endl;
		int nw=tg?0:n+1;
		while (1)
		{
			int nxt=-1;
			for (auto p:d[nw])
			{
				if (d[p].size()) nxt=p;
			}
			for (auto p:d[nw]) if (p!=nxt) cout<<p<<' ';
			if (nxt==-1) break;
			cout<<nxt<<' ';nw=nxt;
		}
		cout<<endl;
	}
}