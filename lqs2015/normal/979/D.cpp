#include<iostream>
#include<cstdio>
using namespace std;
int q,tp,x,k,s,bit[222222][111],sz,ans,l,r,cur,fl,anss;
bool f[111111];
void update(int p,int x)
{
	while(p<=sz)
	{
		bit[p][x]++;
		p+=p&(-p);
	}
}
int query(int p,int x)
{
	int res=0;
	while(p>=1)
	{
		res+=bit[p][x];
		p-=p&(-p);
	}
	return res;
}
int main()
{
	sz=1<<17;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&tp);
		if (tp==1)
		{
			scanf("%d",&x);
			f[x]=1;
			for (int i=1;i<=100;i++)
			{
				if (x%i==0) update(x,i);
			}
		}
		else
		{
			scanf("%d%d%d",&x,&k,&s);
			ans=-1e9;anss=-1e9;
			if (k>100)
			{
				for (int i=k;i<=100000;i+=k)
				{
					if (f[i] && x+i<=s)
					{
						if ((x^i)>anss) 
						{
							anss=x^i;
							ans=i;
						}
					}
				}
			}
			else
			{
				cur=0;
				for (int i=16;i>=0;i--)
				{
					if (x&(1<<i)) fl=0;
					else fl=1;
					l=cur+(fl<<i);r=l+(1<<i)-1;
					if (l+x>s || s<x) 
					{
						fl=!fl;
						cur|=(fl<<i);
						continue;
					}
					r=min(r,s-x);
					if (query(r,k)!=query(l-1,k)) cur|=(fl<<i);
					else
					{
						fl=!fl;
						cur|=(fl<<i);
					}
				}
				if ((x^cur)==0 && (!f[cur] || cur%k!=0 || cur+x>s));
				else ans=cur;
			}
			if (x%k!=0 || ans<0 || s<x) printf("-1\n");
			else printf("%d\n",ans);
		}
	}
	return 0;
}