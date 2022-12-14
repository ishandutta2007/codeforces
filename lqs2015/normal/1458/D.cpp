#include<bits/stdc++.h>
using namespace std;
int n,m,ls[1111111],rs[1111111],sz[1111111],rt,l,r,rt1,rt2,rt3,rt4,tag1[1111111],tag2[1111111];
int mx[1111111],mn[1111111],sum[1111111],val[1111111],test,ans[1111111],cur,rd[1111111];
char s[555555];
int Get(int x)
{
	return ((rand()<<13)+rand())%x+1;
}
void pushup(int node)
{
	sz[node]=sz[ls[node]]+sz[rs[node]]+1;
	mx[node]=max(max(mx[ls[node]],sum[ls[node]]+val[node]),sum[ls[node]]+val[node]+mx[rs[node]]);
	mn[node]=min(min(mn[ls[node]],sum[ls[node]]+val[node]),sum[ls[node]]+val[node]+mn[rs[node]]);
	sum[node]=sum[ls[node]]+val[node]+sum[rs[node]];
}
void push1(int x)
{
	int m=-mx[x];
	mx[x]=-mn[x];
	mn[x]=m;
	sum[x]=-sum[x];
	val[x]=-val[x];
	tag1[x]^=1;
}
void push2(int x)
{
	int m=mx[x];
	mx[x]=sum[x]-mn[x];
	mn[x]=sum[x]-m;
	swap(ls[x],rs[x]);
	tag2[x]^=1;
}
void pushdown(int x)
{
	if (tag1[x])
	{
		if (ls[x]) push1(ls[x]);
		if (rs[x]) push1(rs[x]);
		tag1[x]=0;
	}
	if (tag2[x])
	{
		if (ls[x]) push2(ls[x]);
		if (rs[x]) push2(rs[x]);
		tag2[x]=0;
	}
}
int merge(int x,int y)
{
	if (!x || !y) return x^y;
	pushdown(x);pushdown(y);
	if (rd[x]<=rd[y])
	{
		rs[x]=merge(rs[x],y);
		pushup(x);
		return x;
	}
	else
	{
		ls[y]=merge(x,ls[y]);
		pushup(y);
		return y;
	}
}
void split(int x,int &rt1,int &rt2,int y)
{
	if (!x) 
	{
		rt1=rt2=0;
		return;
	}
	pushdown(x);
	if (y<=sz[ls[x]])
	{
		rt2=x;
		split(ls[x],rt1,ls[rt2],y);
		pushup(x);
	}
	else
	{
		rt1=x;
		split(rs[x],rs[rt1],rt2,y-sz[ls[x]]-1);
		pushup(x);
	}
}
int query()
{
	int pos=rt;pushdown(pos);
	while(ls[pos])
	{
		pos=ls[pos];
		pushdown(pos);
	}
	return val[pos];
}
void split2(int x,int &rt1,int &rt2,int y)
{
	if (!x) 
	{
		rt1=rt2=0;
		return;
	}
	pushdown(x);
	if (mn[ls[x]]+y<0)
	{
		rt2=x;
		split2(ls[x],rt1,ls[rt2],y);
		pushup(x);
	}
	else
	{
		rt1=x;
		split2(rs[x],rs[rt1],rt2,y+sum[ls[x]]+val[x]);
		pushup(x);
	}
}
void split3(int x,int &rt1,int &rt2,int y)
{
	if (!x) 
	{
		rt1=rt2=0;
		return;
	}
	pushdown(x);
	if (mn[ls[x]]+y<=1 && mx[ls[x]]+y>=1)
	{
		rt2=x;
		split3(ls[x],rt1,ls[rt2],y);
		pushup(x);
	}
	else
	{
		rt1=x;
		split3(rs[x],rs[rt1],rt2,y+sum[ls[x]]+val[x]);
		pushup(x);
	}
}
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%s",s);
		n=strlen(s);
		for (int i=1;i<=n;i++)
		{
			ls[i]=rs[i]=0;
			sz[i]=1;sum[i]=val[i]=(s[i-1]=='0' ? -1 : 1);
			mx[i]=max(0,val[i]);
			mn[i]=min(0,val[i]);
		}
		for (int i=1;i<=n;i++) rd[i]=i;
		random_shuffle(rd+1,rd+n+1);
		rt=0;
		for (int i=1;i<=n;i++) rt=merge(rt,i);
		for (int i=1;i<=n;i++)
		{
			cur=query();
			if (cur==-1) 
			{
				ans[i]=0;
				split(rt,rt1,rt2,1);
				rt=rt2;
			}
			else
			{
				split2(rt,rt1,rt2,0);	
				if (rt2)
				{
					split3(rt2,rt3,rt4,0);
					if (sum[rt3]==1)
					{
						rt2=merge(rt1,rt3);
						push1(rt2);push2(rt2);
						rt=merge(rt2,rt4);
					}
					else 
					{
						rt=merge(rt1,merge(rt3,rt4));
					}
				}
				else rt=rt1;
				if (query()==-1) ans[i]=0;
				else ans[i]=1;
				split(rt,rt1,rt2,1);
				rt=rt2;
			}
		}
		for (int i=1;i<=n;i++) putchar('0'+ans[i]);
		printf("\n");
	}
	return 0;
}