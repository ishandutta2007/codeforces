#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int T,Q;
char S[1<<20];
int cnt[1<<20];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%s",S);
		cnt[0]=0;
		int N=strlen(S);
		for(int i=0;i<N;i++)
		{
			cnt[i+1]=cnt[i];
			if(S[i]=='['||S[i]==']')cnt[i+1]+=i%2==0?1:-1;
		}
		scanf("%d",&Q);
		for(;Q--;)
		{
			int l,r;scanf("%d%d",&l,&r);
			int now=cnt[r]-cnt[l-1];
			printf("%d\n",abs(now));
		}
	}
}