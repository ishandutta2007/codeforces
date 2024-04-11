#include<cstdio>
#include<cstdlib>
int n,start,x;
int vs,nexts;
inline int Rand(int l,int r)
{
	return (rand()<<15|rand())%(r-l+1)+l;
}
signed main()
{
	srand(13);
	int k,v,next;
	scanf("%d%d%d",&n,&start,&x);
	printf("? %d\n",start);
	fflush(stdout);
	scanf("%d%d",&vs,&nexts);
	if(vs>=x)
	{
		printf("! %d\n",vs);
		return 0;
	}
	while(true)
	{
		k=Rand(1,n);
		printf("? %d\n",k);
		fflush(stdout);
		scanf("%d%d",&v,&next);
		if(v>vs&&v<x)
			start=k,vs=v,nexts=next;
		else
		{
			if(nexts==-1)
			{
				puts("! -1");
				return 0;
			}
			printf("? %d\n",nexts);
			fflush(stdout);
			scanf("%d%d",&v,&next);
			if(v>=x)
			{
				printf("! %d\n",v);
				return 0;
			}
			else
				start=nexts,vs=v,nexts=next;
		}
	}
	return 0;
}