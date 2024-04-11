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
int n,k;
struct kit
{
	int a[20];
	inline void prt()
	{
		int ans=0;
		per(i,19,0)ans=ans*k+a[i];
		printf("%d\n",ans);
		fflush(stdout);
	}
};
inline kit operator+(kit a,kit b)
{
	kit c;
	rep0(i,0,20)c.a[i]=(a.a[i]+b.a[i])%k;
	return c;
}
inline kit operator-(kit a,kit b)
{
	kit c;
	rep0(i,0,20)c.a[i]=(a.a[i]+k-b.a[i])%k;
	return c;
}
void sol()
{
	scanf("%d%d",&n,&k);
	kit s;
	rep0(i,0,20)s.a[i]=0;
	rep0(i,0,n)
	{
		int t=i;kit p;
		rep0(j,0,20)p.a[j]=t%k,t/=k;
//		rep0(j,0,20)std::cout<<p.a[j];std::cout<<std::endl;
//		rep0(j,0,20)std::cout<<s.a[j];std::cout<<std::endl;
		if(i&1)p=s-p;else p=s+p;
		p.prt();s=p-s;
		int o;scanf("%d",&o);
		if(o)break;
	}
}
int main()
{
	int T;scanf("%d",&T);
	while(T--)sol();
	return 0;
}