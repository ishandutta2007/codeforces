#include<bits/stdc++.h>
using namespace std;
int test,n,m,a[1111],b[1111],sum,cur,tt,xx,yy,ct;
bitset<1000001> dp[1111];
vector<int> ax,ay,bx,by;
void add(int x,int y)
{
	if (tt==0) printf("%d %d\n",x,y);
	else printf("%d %d\n",y,x);
}
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		scanf("%d",&m);
		for (int i=1;i<=m;i++) scanf("%d",&b[i]);
		if (n!=m)
		{
			printf("No\n");
			continue;
		}
		ax.clear();ay.clear();bx.clear();by.clear();
		for (int i=0;i<=n;i++) dp[i].reset();
		sum=0;
		for (int i=1;i<=n;i++) sum+=a[i];
		dp[0][0]=1;
		for (int i=1;i<=n;i++)
		{
			dp[i]=dp[i-1]|(dp[i-1]<<a[i]);
		}
		if ((sum&1) || !dp[n][sum>>1])
		{
			printf("No\n");
			continue;
		}
		cur=(sum>>1);
		for (int i=n;i>=1;i--)
		{
			if (dp[i-1][cur]) 
			{
				ay.push_back(a[i]);
			}
			else
			{
				cur-=a[i];
				ax.push_back(a[i]);
			}
		}
		for (int i=0;i<=m;i++) dp[i].reset();
		sum=0;
		for (int i=1;i<=m;i++) sum+=b[i];
		dp[0][0]=1;
		for (int i=1;i<=m;i++)
		{
			dp[i]=dp[i-1]|(dp[i-1]<<b[i]);
		}
		if ((sum&1) || !dp[m][sum>>1])
		{
			printf("No\n");
			continue;
		}
		cur=(sum>>1);
		for (int i=m;i>=1;i--)
		{
			if (dp[i-1][cur]) 
			{
				by.push_back(b[i]);
			}
			else
			{
				cur-=b[i];
				bx.push_back(b[i]);
			}
		}
		printf("Yes\n");
		tt=0;
		if (ax.size()>bx.size())
		{
			tt=1;
			swap(ax,bx);swap(ay,by);
		}
		sort(ax.begin(),ax.end());
		reverse(ax.begin(),ax.end());
		sort(bx.begin(),bx.end());
		sort(ay.begin(),ay.end());
		reverse(ay.begin(),ay.end());
		sort(by.begin(),by.end());
		xx=yy=0;
		for (int i=0;i<ax.size();i++)
		{
			add(xx,yy);
			xx+=ax[i];
			add(xx,yy);
			yy+=bx[i];
		}
		ct=0;
		for (int i=ax.size();i<bx.size();i++)
		{
			add(xx,yy);
			xx-=ay[ct];ct++;
			add(xx,yy);
			yy+=bx[i];
		}
		for (int i=0;i<by.size();i++)
		{
			add(xx,yy);
			xx-=ay[ct];ct++;
			add(xx,yy);
			yy-=by[i];
		}
	}
	return 0;
}