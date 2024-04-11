#include<bits/stdc++.h>
#define re register
std::unordered_map<long long,int>mp;
std::vector<long double>vc[500100];
int gcd(re int a,re int b)
{
	for(;b;)
	{
		a%=b;
		if(!a)return b;
		else b%=a;
	}
	return a;
}
int x[500100],y[500100],vl[500100],qq[500100],nw[500100],k;
long double vk[500100];
inline long double val(re int a)
{
	if(vl[a]<=k-1)
	{
		return (k-vl[a]-1)*(*vc[a].rbegin());
	}
	else
	{
		return vc[a][nw[a]]*(k-vl[a]-1)+vk[a];
	}
}
inline bool cmp(re int a,re int b)
{
	return val(a)<val(b);
}
int main()
{
	re int n,ta=0;
	re long double ans=0;
	scanf("%d%d",&n,&k);
	for(re int i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		if(x[i]==0&&y[i]==0)
		{
			vc[++ta].push_back(0);continue;
		}
		re int g=gcd(abs(x[i]),abs(y[i])),x1=x[i]/g,y1=y[i]/g;
		re long long ky=(long long)2.5e9*x1+y1;
		if(!mp[ky])mp[ky]=++ta;
		vc[mp[ky]].push_back(sqrtl(1ll*x[i]*x[i]+1ll*y[i]*y[i]));
	}
	for(re int i=1;i<=ta;i++)qq[i]=i,std::sort(vc[i].begin(),vc[i].end());
	std::make_heap(qq+1,qq+ta+1,cmp);
	for(re int i=1;i<=k;i++)
	{
		re int x=qq[1];
		std::pop_heap(qq+1,qq+ta+1,cmp);ta--;
		ans+=val(x);
		//if(n==500000&&k==10)printf("****%d %d %d %lf %lf\n",i,x,vl[x],(double)*vc[x].rbegin(),(double)ans); 
		if(vl[x]<=k-1)
		{
			vl[x]+=2;
			vc[x].pop_back();
		}
		else
		{
			vk[x]-=vc[x][nw[x]]*2;nw[x]++;
		}
		if(nw[x]<vc[x].size())
		{
			qq[++ta]=x;
			std::push_heap(qq+1,qq+ta+1,cmp);
		}
	}
	std::cout.precision(20);
	std::cout<<ans;
}