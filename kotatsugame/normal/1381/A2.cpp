#include<cstdio>
#include<vector>
using namespace std;
int t,N;
char S[1<<17],T[1<<17];
main()
{
	scanf("%d\n",&t);
	for(;t--;)
	{
		scanf("%d\n%s\n%s\n",&N,S,T);
		vector<int>ans;
		int w=0;
		int L=0,R=N-1;
		for(int i=N;i--;)
		{
			if((N-i)%2==1)
			{
				if((S[L]^w)==T[i])
				{
					ans.push_back(1);
				}
				ans.push_back(i+1);
				L++;
			}
			else
			{
				if((S[R]^w)==T[i])
				{
					ans.push_back(1);
				}
				ans.push_back(i+1);
				R--;
			}
			w^=1;
		}
		printf("%d",(int)ans.size());
		for(int v:ans)printf(" %d",v);
		puts("");
	}
}