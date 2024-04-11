#include<cstdio>
#include<utility>
using namespace std;
const long long L=1e12;
const long long L2=2250000000000;
int N;
int X[1<<17],Y[1<<17];
int ans[1<<17];
pair<int,int>f(int id,int x,int y,int z,int w)
{
	if(id==N)
	{
		if((long long)(x+z)*(x+z)+(long long)(y+w)*(y+w)<=L2)return make_pair(1,1);
		else if((long long)(x-z)*(x-z)+(long long)(y-w)*(y-w)<=L2)return make_pair(1,-1);
		else
		{
			puts("ERROR");
			return make_pair(2,2);
		}
	}
	long long nx[3]={x,z,X[id]};
	long long ny[3]={y,w,Y[id]};
	for(int i=0;i<3;i++)for(int j=i+1;j<3;j++)
	{
		long long dx=nx[i]+nx[j],dy=ny[i]+ny[j];
		if(dx*dx+dy*dy<=L)
		{
			pair<int,int>p=f(id+1,dx,dy,nx[3^i^j],ny[3^i^j]);
			if((3^i^j)==0)
			{
				ans[id]=p.first;
				return make_pair(p.second,p.first);
			}
			else if((3^i^j)==1)
			{
				ans[id]=p.first;
				return make_pair(p.first,p.second);
			}
			else
			{
				ans[id]=p.second;
				return make_pair(p.first,p.first);
			}
		}
		dx=nx[i]-nx[j],dy=ny[i]-ny[j];
		if(dx*dx+dy*dy<=L)
		{
			pair<int,int>p=f(id+1,dx,dy,nx[3^i^j],ny[3^i^j]);
			if((3^i^j)==0)
			{
				ans[id]=-p.first;
				return make_pair(p.second,p.first);
			}
			else if((3^i^j)==1)
			{
				ans[id]=-p.first;
				return make_pair(p.first,p.second);
			}
			else
			{
				ans[id]=p.second;
				return make_pair(p.first,-p.first);
			}
		}
	}
}
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d%d",&X[i],&Y[i]);
	}
	if(N>1)
	{
		pair<int,int>p=f(2,X[0],Y[0],X[1],Y[1]);
		ans[0]=p.first;
		ans[1]=p.second;
	}
	else ans[0]=1;
	for(int i=0;i<N;i++)printf("%d%c",ans[i],i+1==N?10:32);
}