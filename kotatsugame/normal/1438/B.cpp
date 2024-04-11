#include<cstdio>
#include<set>
using namespace std;
int T,N;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		set<int>S;
		bool flag=false;
		for(int i=0;i<N;i++)
		{
			int A;scanf("%d",&A);
			if(S.find(A)!=S.end())flag=true;
			S.insert(A);
		}
		puts(flag?"YES":"NO");
	}
}