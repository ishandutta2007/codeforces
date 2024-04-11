#include<bits/stdc++.h>
using namespace std;
int bit1[5555][5555],bit2[11111][5555],ans[111111],x,y,len,dir;
int n,q,que1[111111],que2[111111],que3[111111],que4[111111],que5[111111];
void update1(int x,int y,int p)
{
	for (int i=x;i<=n;i+=i&(-i))
	{
		for (int j=y;j<=n;j+=j&(-j))
		{
			bit1[i][j]+=p;
		}
	}
}
void update2(int x,int y,int p)
{
	for (int i=x;i<=2*n;i+=i&(-i))
	{
		for (int j=y;j<=n;j+=j&(-j))
		{
			bit2[i][j]+=p;
		}
	}
}
int query1(int x,int y)
{
	if (x<=0 || y<=0) return 0;
	int res=0;
	for (int i=x;i;i-=i&(-i))
	{
		for (int j=y;j;j-=j&(-j))
		{
			res+=bit1[i][j];
		}
	}
	return res;
}
int query2(int x,int y)
{
	int res=0;
	for (int i=x;i;i-=i&(-i))
	{
		for (int j=y;j;j-=j&(-j)) 
		{
			res+=bit2[i][j];
		}
	}
	return res;
}
int main()
{
	scanf("%d%d",&n,&q);
	for (int i=1;i<=q;i++)
	{
		scanf("%d",&que1[i]);
		if (que1[i]==1)
		{
			scanf("%d%d%d%d",&que2[i],&que3[i],&que4[i],&que5[i]);
		}
		else
		{
			scanf("%d%d",&que2[i],&que3[i]);
		}
	}
	for (int i=1;i<=q;i++)
	{
		if (que1[i]==1)
		{
			dir=que2[i];x=que3[i];y=que4[i];len=que5[i];
			if (dir==1)
			{
				update1(x,y,1);
				if (x+len+1<=n) update1(x+len+1,y,-1);
				if (y+len+1<=n)
				{
					update2(x+(y+len+1),x,-1);
					if (x+len+1<=n) update2((x+len+1)+y,x+len+1,1);
				}
				else 
				{
					update2(x+(y+len+1),x+1,-1);
					if (x+len+1<=n) update2((x+len+1)+y,x+len+1,1);
				}
			}
			else if (dir==4)
			{
				update2(x+y-len,x-len,1);
				if (x+1<=n) update2(x+y-len,x+1,-1);
				if (y+1<=n)
				{
					update1(x-len,y+1,-1);
					if (x+1<=n) update1(x+1,y+1,1);
				}
			}
		}
		else
		{
			x=que2[i];y=que3[i];
			ans[i]=query1(x,y)+query2(x+y,x)-query2(x,x);
		}
	}
	memset(bit1,0,sizeof(bit1));
	memset(bit2,0,sizeof(bit2));
	for (int i=1;i<=q;i++)
	{
		if (que1[i]==1)
		{
			dir=que2[i];x=que3[i];y=que4[i];len=que5[i];
			if (dir==2)
			{
				update2(x-(y-len)+n,x,1);
				if (x+len+1<=n)
				{
					update2(x-(y-len)+n,x+len+1,-1);
				}
				if (y+1<=n)
				{
					update1(x,y+1,-1);
					if (x+len+1<=n) update1(x+len+1,y+1,1);
				}
			}
			else if (dir==3)
			{
				update1(x-len,y,1);
				if (x+1<=n) update1(x+1,y,-1);
				if (y+1<=n)
				{
					update2(x-(y+len+1)+n,x-len,-1);
					if (x+1<=n && y+len+2<=n) update2(x-(y+len+1)+n,x+1,1);
				}
			}
		}
		else
		{
			x=que2[i];y=que3[i];
			ans[i]+=(query1(x,y)+query2(x-1+n,x)-query2(x-(y+1)+n,x));
		}
	}
	for (int i=1;i<=q;i++)
	{
		if (que1[i]!=1) printf("%d\n",ans[i]);
	}
	return 0;
}