#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int isp[1<<20];
int T,N,Q;
main()
{
	for(int i=2;i<1<<20;i++)if(isp[i]==0)
	{
		for(int j=i+i;j<1<<20;j+=i)isp[j]=i;
	}
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		vector<int>A(N);
		for(int i=0;i<N;i++)
		{
			int a;scanf("%d",&a);
			int b=1;
			while(isp[a]!=0)
			{
				int p=isp[a];
				int c=0;
				while(a%p==0)a/=p,c^=1;
				if(c==1)b*=p;
			}
			b*=a;
			A[i]=b;
		}
		sort(A.begin(),A.end());
		int ans[2]={};
		int zeroc=0;
		for(int i=0;i<A.size();)
		{
			int j=i;
			while(j<A.size()&&A[j]==A[i])j++;
			ans[0]=max(ans[0],j-i);
			if((j-i)%2==0||A[i]==1)zeroc+=j-i;
			i=j;
		}
		ans[1]=max(ans[0],zeroc);
		scanf("%d",&Q);
		for(;Q--;)
		{
			long long w;scanf("%lld",&w);
			printf("%d\n",w==0?ans[0]:ans[1]);
		}
	}
}