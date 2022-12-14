#include<bits/stdc++.h>
using namespace std;
const int maxn=200000;
int Log[222222],n,m,test,a[222222],st[22][222222],suf[222222],x,y,pos,cnt,l,r,mid;
int get(int l,int r)
{
	if (l>r) return -1e9;
	int x=Log[r-l+1];
	return max(st[x][l],st[x][r-(1<<x)+1]); 
}
int main()
{
	for (int i=2;i<=maxn;i++) Log[i]=Log[i>>1]+1;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		for (int i=1;i<=n;i++) st[0][i]=a[i];
		for (int i=1;i<=18;i++)
		{
			for (int j=1;j<=n;j++)
			{
				st[i][j]=st[i-1][j];
				if (j+(1<<(i-1))<=n) st[i][j]=max(st[i][j],st[i-1][j+(1<<(i-1))]);
			}
		}
		for (int i=0;i<=n+1;i++) suf[i]=-1e9;
		scanf("%d",&m);
		for (int i=1;i<=m;i++)
		{
			scanf("%d%d",&x,&y);
			suf[y]=max(suf[y],x);
		}
		for (int i=n;i>=1;i--) suf[i]=max(suf[i],suf[i+1]);
		pos=1;cnt=0;
		while(pos<=n)
		{
			l=pos;r=n;
			while(l<=r)
			{
				mid=(l+r)>>1;
				if (suf[mid-pos+1]>=get(pos,mid)) l=mid+1;
				else r=mid-1;
			}
			if (r==pos-1) 
			{
				cnt=1e9;
				break;
			}
			cnt++;pos=r+1;
		}
		if (cnt>1e8) printf("-1\n");
		else printf("%d\n",cnt);
	}
	return 0;
}