#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,cl,ce,v;
int l[1<<17],e[1<<17];
int main()
{
	scanf("%d%d%d%d%d",&n,&m,&cl,&ce,&v);
	for(int i=0;i<cl;i++)scanf("%d",l+i);
	for(int i=0;i<ce;i++)scanf("%d",e+i);
	int q;scanf("%d",&q);
	for(;q--;)
	{
		int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);
		if(b>d)swap(a,c),swap(b,d);
		int ans=2e9;
		if(a==c)ans=min(ans,d-b);
		else
		{
			int*u=lower_bound(l,l+cl,b);
			int*w=lower_bound(e,e+ce,b);
			if(u<l+cl)
			{
				if(*u<=d)ans=min(ans,d-b+abs(a-c));
				else ans=min(ans,2*(*u)-b-d+abs(a-c));
			}
			if(w<e+ce)
			{
				if(*w<=d)ans=min(ans,d-b+(abs(a-c)+v-1)/v);
				else ans=min(ans,2*(*w)-b-d+(abs(a-c)+v-1)/v);
			}
			u--;
			if(u-l>=0)
			{
				ans=min(ans,b+d-2*(*u)+abs(a-c));
			}
			w--;
			if(w-e>=0)
			{
				ans=min(ans,b+d-2*(*w)+(abs(a-c)+v-1)/v);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}