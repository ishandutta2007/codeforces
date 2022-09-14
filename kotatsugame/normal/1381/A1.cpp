#include<cstdio>
#include<vector>
using namespace std;
int t,N;
char S[1010],T[1010];
char tmp[1010];
main()
{
	scanf("%d\n",&t);
	for(;t--;)
	{
		scanf("%d\n%s\n%s\n",&N,S,T);
		vector<int>ans;
		for(int i=N;i--;)
		{
			if(S[0]==T[i])
			{
				ans.push_back(1);
				S[0]^=1;
			}
			ans.push_back(i+1);
			for(int j=0;j<=i;j++)
			{
				tmp[j]=S[j]^1;
			}
			for(int j=0;j<=i;j++)
			{
				S[i-j]=tmp[j];
			}
		}
		printf("%d",(int)ans.size());
		for(int v:ans)printf(" %d",v);
		puts("");
	}
}