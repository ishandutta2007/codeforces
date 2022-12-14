#include<iostream>
#include<cstdio>
using namespace std;
const int sz=1<<19;
int bit[666666],n,m,x,res,cur,p,jz;
bool used[333333];
void add(int p)
{
	while(p<=sz)
	{
		bit[p]++;
		p+=p&(-p);
	}
}
int sum(int p)
{
	if (p>sz) return -1e9;
	int res=0;
	while(p>=1)
	{
		res+=bit[p];
		p-=p&(-p);
	}
	return res;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		x++;
		if (used[x]) continue;
		add(x);used[x]=1;
	}
	scanf("%d",&x);
	while(m--)
	{
		res=0;cur=0;
		for (int i=19;i>=0;i--)
		{
			jz=cur+(x&(1<<i));
			if (sum(jz+(1<<i))-sum(jz)>=(1<<i)) 
			{
				res+=(1<<i);
				if (!(x&(1<<i))) cur|=(1<<i);
			}
			else 
			{
				if (x&(1<<i)) cur|=(1<<i);
			}
		}
		printf("%d\n",res);
		if (!m) break;
		scanf("%d",&p);
		x=x^p;
	}
	return 0;
}