#include<cstdio>
using namespace std;
const int mod=1e9+7;
int T,N,M;
char S[2020];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&M);
		bool z=false;
		int ans=1;
		for(int i=0;i<N;i++)
		{
			scanf("%s",S);
			for(int j=0;j<M;j++)
			{
				if(S[j]=='0')z=true;
				else
				{
					ans+=ans;
					if(ans>=mod)ans-=mod;
				}
			}
		}
		if(!z)
		{
			ans+=mod-1;
			if(ans>=mod)ans-=mod;
		}
		printf("%d\n",ans);
	}
}