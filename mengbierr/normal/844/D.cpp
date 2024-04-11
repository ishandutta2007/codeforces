#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') {f=f*10+(ch^48);ch=getchar();}
	return f;
}
int rando()
{
	return (rand()<<15)|rand();
}
int main()
{
	srand(2002127);
	int n,start,x,nowlnum=-233,nowlpla,nowlnxt,nowrnum=-233,nowrpla,ans,nxt;
	scanf("%d%d%d",&n,&start,&x);
	
	for(int i=1;i<=1300;i++)
	{
		int now=rando()%n+1;
		printf("? %d\n",now);
		fflush(stdout);
		scanf("%d%d",&ans,&nxt);
		if(ans==x)
		{
			printf("! %d\n",ans);
			return 0;
		}
		else
		{
			if((nowlnum<0&&ans<x)||(nowrnum<0&&ans>x))
			{
				if(ans<x)
				{nowlnum=ans;
				 nowlpla=now;
				 nowlnxt=nxt;
				}
				else
				{
					nowrnum=ans;
					nowrpla=now;
				}
			}
			else if(ans<x&&nowlnum<ans)
			{
				nowlnum=ans;
				 nowlpla=now;
				 nowlnxt=nxt;
			}
			else if(ans>x&&nowrnum>ans)
			{
				nowrnum=ans;
				nowrpla=now;
			}
		}
	}
	if(nowlnum<0)
	{
		nowlnxt=start;
	}
	if(nowlnxt==-1&&nowlnum<x)
	{
		puts("! -1");
		return 0;
	}
	for(int i=1;i<=799;i++)
	{
		printf("? %d\n",nowlnxt);
		fflush(stdout);
		scanf("%d%d",&ans,&nxt);
		if(ans>=x)
		{
			printf("! %d",ans);
			return 0;
		}
		else if(nxt!=-1)
		{
			nowlnxt=nxt;
			nowlnum=ans;
		}
		else if(nxt==-1)
		{
			puts("! -1");
			return 0;
		}
	}
	printf("! %d",nowlnum);
}