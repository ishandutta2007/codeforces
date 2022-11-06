#include<cstdio>
#include<vector>
#define int long long
using std::vector;
int pow21[1000];
int x,d;
int n;
vector<int> V;
signed main()
{
	scanf("%lld%lld",&x,&d);
	n=x;
	pow21[1]=1;
	for(int i=2;i<=300;i++)
	{
		pow21[i]=pow21[i-1]*2+1;
		if(pow21[i]>10000000000LL)
			break;
	}
	int now,base=1;
	while(true)
	{
		if(n==0)
			break;
		if(n==1)
		{
			V.push_back(base);
			break;
		}
		for(int i=1;i<=300;i++)
		{
			if(n-pow21[i]<0)
			{
				now=i-1;
				break;
			}
		}
		for(int i=1;i<=now;i++)
			V.push_back(base);
		n=n-pow21[now];
		base+=d+1;
	}
	printf("%lld\n",(int)V.size());
	for(int i=0;i<(int)V.size();i++)
		printf("%lld ",V[i]);
	putchar('\n');
	return 0;
}