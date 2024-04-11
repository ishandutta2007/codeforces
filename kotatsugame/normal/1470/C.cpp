#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
int N,K,cnt;
int ask(int pos)
{
	if(cnt++==1000)
	{
		exit(1);
	}
	printf("? %d\n",pos+1);
	fflush(stdout);
	int T;
	scanf("%d",&T);
	return T;
}
main()
{
	scanf("%d%d",&N,&K);
	ask(0);
	int pos=0,val,add=0;
	while(true)
	{
		val=ask(pos);
		if(val!=K)break;
		pos++;
		pos%=N;
		val=ask(pos);
		if(val!=K)break;
		add+=4;
		add%=N;
		pos+=add;
		pos%=N;
	}
	int ans;
	if(val<K)
	{
		int L=pos,R=pos+N/2;
		while(R-L>1)
		{
			int mid=(L+R)/2;
			if(ask(mid%N)<K)L=mid;
			else R=mid;
		}
		ans=R%N;
	}
	else
	{
		int L=pos-N/2,R=pos;
		while(R-L>1)
		{
			int mid=(L+R)/2;
			if(ask((mid%N+N)%N)>K)R=mid;
			else L=mid;
		}
		ans=(L%N+N)%N;
	}
	printf("! %d\n",ans+1);
	return 0;
}