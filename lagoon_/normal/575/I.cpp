#include<bits/stdc++.h>
#define re register
int f1[5011][5010],f2[10011][5010],f3[10011][5010],n;
void add1(re int x,re int y,re int a)
{//printf("*1*%d %d %d\n",x,y,a);
	for(;x<=n;x+=x&-x)for(re int i=y;i<=n;i+=i&-i)f1[x][i]+=a;
}
void add2(re int x,re int y,re int a)
{//printf("*2*%d %d %d\n",x,y,a);
	for(;x<=2*n;x+=x&-x)for(re int i=y;i<=n;i+=i&-i)f2[x][i]+=a;
}
void add3(re int x,re int y,re int a)
{
	x=2*n-x;
	//printf("*3*%d %d %d\n",x,y,a);
	for(;x<=2*n;x+=x&-x)for(re int i=y;i<=n;i+=i&-i)f3[x][i]+=a;
}
int qry1(re int x,re int y)
{
	re int ans=0;
	for(;x;x-=x&-x)for(re int i=y;i;i-=i&-i)ans+=f1[x][i];
	return ans;
}
int qry2(re int x,re int y)
{
	re int ans=0;
	for(;x;x-=x&-x)for(re int i=y;i;i-=i&-i)ans+=f2[x][i];
	return ans;
}
int qry3(re int x,re int y)
{
	x=2*n-x;
	re int ans=0;
	for(;x;x-=x&-x)for(re int i=y;i;i-=i&-i)ans+=f3[x][i];
	return ans;
}
int main()
{
	re int q,x,y,len,dir;
	scanf("%d%d",&n,&q);
	for(;q--;)
	{
		scanf("%d",&x);
		if(x==1)
		{
			scanf("%d%d%d%d",&dir,&x,&y,&len);
			if(dir==1)
			{
				add1(x,y,1);
				add2(x+y+len+1,y,-1);
				add2(x+y+len+1,y+len+1,1);
				add1(x,y+len+1,-1);
			}else if(dir==2)
			{
				add3(x-y+n+len,y-len,1);
				add3(x-y+n+len,y+1,-1);
				add1(1,y-len,-1);
				add1(x,y-len,1);
				add1(1,y+1,1);
				add1(x,y+1,-1);
			}else if(dir==3)
			{
				add1(1,y,1);
				add1(x+1,y,-1);
				add3(x-y+n-len-1,y,-1);
				add3(x-y+n-len-1,y+len+1,1);
				add1(1,y+len+1,-1);
				add1(x+1,y+len+1,1);
			}else if(dir==4)
			{
				add2(x+y-len,y-len,1);
				add2(x+y-len,y+1,-1);
				add1(x+1,y-len,-1);
				add1(x+1,y+1,1);
			}
		}else
		{
			scanf("%d%d",&x,&y);
			printf("%d\n",qry1(x,y)+qry2(x+y,y)+qry3(x-y+n,y));
		}//printf("*********%d %d %d\n",qry1(7,7),qry2(14,7),qry3(n,7));
	}
}