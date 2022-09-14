#include<cstdio>
#include<algorithm>
using namespace std;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int N,A[3<<17];
const int LIM=1.5e7;
int pr[LIM+1];
int cnt[LIM+1];
main()
{
	for(int i=2;i<=LIM;i++)if(pr[i]==0)
	{
		pr[i]=i;
		for(int j=i+i;j<=LIM;j+=i)pr[j]=i;
	}
	scanf("%d",&N);
	int g=0;
	for(int i=0;i<N;i++)
	{
		scanf("%d",&A[i]);
		g=gcd(g,A[i]);
	}
	for(int i=0;i<N;i++)A[i]/=g;
	sort(A,A+N);
	int mx=0;
	for(int i=0;i<N;)
	{
		int t=A[i];
		int j=i;
		while(j<N&&A[j]==t)j++;
		int now=j-i;
		i=j;
		while(pr[t])
		{
			int p=pr[t];
			cnt[p]+=now;
			mx=max(mx,cnt[p]);
			while(t%p==0)t/=p;
		}
	}
	printf("%d\n",mx==0?-1:N-mx);
}