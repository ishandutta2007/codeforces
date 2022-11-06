#include<bits/stdc++.h>
using namespace std;
#define re register
long long nk,nb;
long long qx[300100],qy[300100],ta,nw;
bool cj(re long long x1,re long long y1,re long long x2,re long long y2)
{
	return (long double)x1*y2<=(long double)x2*y1;
}
bool dl()
{
	return cj(qx[ta]-qx[ta-1],qy[ta]-qy[ta-1],qx[ta-2]-qx[ta-1],qy[ta-2]-qy[ta-1]);
}
bool dl1()
{
	return (qx[ta]-1)*nk+nb+qy[ta]>=(qx[ta-1]-1)*nk+nb+qy[ta-1];
}
int main()
{
	re int m,op,k,b;
	scanf("%lld%d",&nw,&m);
	qx[ta=1]=1;
	for(re int i=1;i<=m;i++)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d",&k);
			qx[ta=1]=1;qy[1]=0;nw+=k;nk=nb=0;
			puts("1 0");
		}if(op==2)
		{
			scanf("%d",&k);
			if((qx[ta]-1)*nk+nb+qy[ta]>0)
			{
				qx[++ta]=nw+1;
				qy[ta]=-(qx[ta]-1)*nk-nb;
			}nw+=k;
			while(ta>2&&dl())qx[ta-1]=qx[ta],qy[ta-1]=qy[ta],ta--;
			printf("%lld 0\n",qx[ta]);
		}
		if(op==3)
		{
			scanf("%d%d",&b,&k);nk+=k;nb+=b;
			while(ta>1&&dl1())ta--;
			printf("%lld %lld\n",qx[ta],(qx[ta]-1)*nk+nb+qy[ta]);
		}
	}
}