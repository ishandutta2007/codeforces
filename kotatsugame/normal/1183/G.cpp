#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int Q;
main()
{
	scanf("%d",&Q);
	for(;Q--;)
	{
		int N;
		scanf("%d",&N);
		vector<pair<int,int> >cnt(N,make_pair(0,0));
		for(int i=0;i<N;i++)
		{
			int a,f;scanf("%d%d",&a,&f);
			a--;
			cnt[a].first++;
			cnt[a].second+=f;
		}
		sort(cnt.begin(),cnt.end());
		int A=0,B=0;
		int id=N-1;
		priority_queue<int>P;
		for(int i=N;i;i--)
		{
			while(id>=0&&cnt[id].first>=i)
			{
				P.push(cnt[id].second);
				id--;
			}
			if(!P.empty())
			{
				A+=i;
				B+=min(i,P.top());
				P.pop();
			}
		}
		printf("%d %d\n",A,B);
	}
}