#include<bits/stdc++.h>
#define ll long long
#define db double
#define X first
#define Y second
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define fore(i,a) for(int i=0;i<a.size();++i)
inline int rd()
{
	char c=getchar();int x=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-48,c=getchar();
	return x;
}
const db eps=1e-8;
db v;
db dfs(db c,db m,db p,int x)
{
	db res=p*x;
//	printf("%.8f %.8f %.8f %d\n",c,m,p,x);
	if(fabs(c)>eps)
	{
		if(fabs(m)>eps)
		{
			if(c<v+eps)res+=c*dfs(0,m+c*0.5,p+c*0.5,x+1);
			else res+=c*dfs(c-v,m+v*0.5,p+v*0.5,x+1);
		}
		else
		{
			if(c<v+eps)res+=c*dfs(0,0,p+c,x+1);
			else res+=c*dfs(c-v,0,p+v,x+1);
		}
	}
	//m
	if(fabs(m)>eps)
	{
		if(fabs(c)>eps)
		{
			if(m<v+eps)res+=m*dfs(c+m*0.5,0,p+m*0.5,x+1);
			else res+=m*dfs(c+v*0.5,m-v,p+v*0.5,x+1);
		}
		else
		{
			if(m<v+eps)res+=m*dfs(0,0,p+m,x+1);
			else res+=m*dfs(0,m-v,p+v,x+1);
		}
	}
	return res;
}
void sol()
{
	db c,m,p;
	scanf("%lf%lf%lf%lf",&c,&m,&p,&v);
	printf("%.8f\n",dfs(c,m,p,1));
}
int main()
{
	int T;scanf("%d",&T);
	while(T--)sol();
	return 0;
}