#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N;
bool ex[2000];
long long X[2000],Y[2000];
char S[2020];
long long cross(int i,int j,int k)
{
	long long x1=X[j]-X[i],y1=Y[j]-Y[i];
	long long x2=X[k]-X[i],y2=Y[k]-Y[i];
	return x1*y2-y1*x2;
}
main()
{
	scanf("%d",&N);
	int id=0;
	for(int i=0;i<N;i++)
	{
		ex[i]=true;
		scanf("%lld%lld",&X[i],&Y[i]);
		if(X[i]<X[id]||X[i]==X[id]&&Y[i]<Y[id])id=i;
	}
	scanf("%s",S);
	printf("%d",id+1);
	ex[id]=false;
	for(int tm=0;tm<N-2;tm++)
	{
		int jd=-1;
		if(S[tm]=='L')
		{
			for(int i=0;i<N;i++)if(ex[i])
			{
				if(jd<0||cross(id,jd,i)<0)jd=i;
			}
		}
		else
		{
			for(int i=0;i<N;i++)if(ex[i])
			{
				if(jd<0||cross(id,jd,i)>0)jd=i;
			}
		}
		printf(" %d",jd+1);
		ex[jd]=false;
		id=jd;
	}
	for(int i=0;i<N;i++)if(ex[i])printf(" %d\n",i+1);
}