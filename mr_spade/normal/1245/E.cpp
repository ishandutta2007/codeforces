#include<cstdio>
const int N=105;
inline int no(int x,int y)
{
	if(!(x&1))
		return x*10+y;
	else
		return x*10+9-y;
}
int trans[N];
double ex[N],tex[N];
signed main()
{
	int x;
	register int i,j;
	for(i=0;i<10;i++)
		for(j=0;j<10;j++)
		{
			scanf("%d",&x);
			if(x)
				trans[no(i,j)]=no(i-x,j);
			else
				trans[no(i,j)]=-1;
		}
	for(i=1;i<6;i++)
	{
		for(j=0;j<i;j++)
			tex[i]+=(1.0/i)*(ex[j]+6.0/i);
		ex[i]=tex[i];
	}
	for(i=6;i<100;i++)
	{
		for(j=1;j<=6;j++)
			tex[i]+=(1.0/6)*(ex[i-j]+1);
		if(trans[i]!=-1&&tex[trans[i]]<tex[i])
			ex[i]=tex[trans[i]];
		else
			ex[i]=tex[i];
	}
	printf("%.12lf\n",ex[99]);
	return 0;
}