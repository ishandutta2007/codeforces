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
void sol()
{
	int n,k,s=0;
	scanf("%d%d",&n,&k);
	rep0(i,0,n)
	{
		printf("%d\n",s^i);
		fflush(stdout);
		s=i;int o;scanf("%d",&o);
		if(o)break;
	}
}
int main()
{
	int T;scanf("%d",&T);
	while(T--)sol();
	return 0;
}