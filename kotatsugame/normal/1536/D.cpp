#include<cstdio>
#include<set>
using namespace std;
int T,N;
int b[2<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)scanf("%d",&b[i]);
		set<int>S;
		bool out=false;
		S.insert(b[0]);
		for(int i=1;i<N;i++)
		{
			S.insert(b[i]);
			auto it=S.find(b[i-1]);
			auto jt=it;
			auto kt=it;
			if(*it==b[i]
				||++jt!=S.end()&&*jt==b[i]
				||kt!=S.begin()&&*--kt==b[i]);
			else out=true;
		}
		puts(out?"NO":"YES");
	}
}