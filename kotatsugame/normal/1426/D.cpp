#include<cstdio>
#include<set>
using namespace std;
int N;
main()
{
	scanf("%d",&N);
	set<long long>S;
	S.insert(0);
	long long now=0;
	int ans=0;
	for(int i=0;i<N;i++)
	{
		int A;scanf("%d",&A);
		now+=A;
		if(S.find(now)!=S.end())
		{
			ans++;
			S.clear();
			S.insert(0);
			now=A;
		}
		S.insert(now);
	}
	printf("%d\n",ans);
}