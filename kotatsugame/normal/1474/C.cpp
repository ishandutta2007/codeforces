#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
int T,N;
int A[2020];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<2*N;i++)scanf("%d",A+i);
		sort(A,A+2*N);
		bool fn=false;
		for(int i=0;i<2*N-1;i++)
		{
			multiset<int>S(A,A+2*N);
			vector<pair<int,int> >ans;ans.reserve(N);
			int T=A[2*N-1]+A[i];
			int init=T;
			while(!S.empty())
			{
				auto it=S.end();
				it--;
				int U=*it;
				S.erase(it);
				int V=T-U;
				it=S.find(V);
				if(it==S.end())break;
				S.erase(it);
				ans.push_back(make_pair(V,U));
				T=U;
			}
			if(S.empty())
			{
				puts("YES");
				printf("%d\n",init);
				for(pair<int,int>p:ans)printf("%d %d\n",p.first,p.second);
				fn=true;
				break;
			}
		}
		if(!fn)puts("NO");
	}
}