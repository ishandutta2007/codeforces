#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,p[333333],pos[333333],x,t,cnt;
pair<int,int> ans[3333333];
void SWAP(int x,int y)
{
	ans[++cnt]=make_pair(x,y);
	swap(p[x],p[y]);
	swap(pos[p[x]],pos[p[y]]);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
		pos[p[i]]=i;
	}
	for (int i=1;i<=n;i++)
	{
		x=pos[i];
		if (x==i) continue;
		if (abs(x-i)>=n/2)
		{
			SWAP(x,i);
		}
		else
		{
			if (i<=n/2) t=n;
			else t=1;
			if (abs(x-t)>=n/2)
			{
				SWAP(x,t);
				SWAP(t,i);
				SWAP(x,t);
			}
			else
			{
				SWAP(x,n+1-t);
				SWAP(t,n+1-t);
				SWAP(t,i);
				SWAP(t,n+1-t);
				SWAP(x,n+1-t);
			}
		}
	}
	printf("%d\n",cnt);
	for (int i=1;i<=cnt;i++)
	{
		printf("%d %d\n",ans[i].first,ans[i].second);
	}
	return Accepted;
}