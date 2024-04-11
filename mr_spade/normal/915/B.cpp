#include<cstdio>
inline int abs(int x)
{
	return x<0?-x:x;
}
signed main()
{
	int n,pos,l,r;
	int ans=0;
	scanf("%d%d%d%d",&n,&pos,&l,&r);
	if(l==1&&r==n)
		return puts("0"),0;
	if(l==1)
	{
		ans++;
		ans+=abs(r-pos);
		printf("%d\n",ans);
		return 0;
	}
	if(r==n)
	{
		ans=abs(pos-l)+1;
		printf("%d\n",ans);
		return 0;
	}
	if(pos<l)
	{
		printf("%d\n",r-pos+2);
		return 0;
	}
	else if(pos>=l&&pos<=r)
	{
		if(pos-l<=r-pos)
			printf("%d\n",pos-l+r-l+2);
		else
			printf("%d\n",r-pos+r-l+2);
		return 0;
	}
	else
	{
		printf("%d\n",pos-l+2);
		return 0;
	}
}