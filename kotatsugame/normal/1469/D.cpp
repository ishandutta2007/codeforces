#include<cstdio>
#include<vector>
using namespace std;
int T,N;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		vector<pair<int,int> >ans;
		int AN=N;
		for(int i=N-1;i>1;i--)
		{
			if(AN>2&&(AN+i-1-1)/(i-1)>i-1)
			{
				ans.push_back(make_pair(N,i));
				AN=(AN+i-1)/i;
			}
			int t=i;
			while(t!=1)
			{
				ans.push_back(make_pair(i,N));
				t=(t+AN-1)/AN;
			}
		}
		printf("%d\n",(int)ans.size());
		for(pair<int,int>p:ans)printf("%d %d\n",p.first,p.second);
	}
}