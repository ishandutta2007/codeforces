#include<bits/stdc++.h>
using namespace std;
const int maxn=100;
int q,n,m;
int main()
{
	scanf("%d",&q);
	for(int cs=1;cs<=q;cs++)
	{
		scanf("%d%d",&n,&m);
		int T,L,R;
		int l=m,r=m,t=0;
		int fag=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&T,&L,&R);
			if(fag) continue;
			int d=T-t;
			t=T;
			l=l-d;
			r=r+d;
			if(r<L||R<l)
			{
				fag=1;
				continue;
			}
			l=max(l,L);
			r=min(r,R);
		}
		if(fag) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}