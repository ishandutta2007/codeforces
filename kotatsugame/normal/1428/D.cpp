#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
int N;
int A[1<<17];
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	vector<pair<int,int> >ans;
	int row=N;
	queue<pair<int,int> >ONE;
	int thp=-1;
	for(int i=N;i--;)
	{
		if(A[i]==1)
		{
			ans.push_back(make_pair(row,i+1));
			ONE.push(make_pair(row,i+1));
			row--;
		}
		else if(A[i]==2)
		{
			if(ONE.empty())
			{
				puts("-1");
				return 0;
			}
			int r=ONE.front().first;
			ONE.pop();
			if(thp==-1)thp=i+1;
			ans.push_back(make_pair(r,i+1));
		}
		else if(A[i]==3)
		{
			if(thp==-1)
			{
				if(ONE.empty())
				{
					puts("-1");
					return 0;
				}
				thp=ONE.front().second;
				ONE.pop();
			}
			ans.push_back(make_pair(row,thp));
			ans.push_back(make_pair(row,i+1));
			thp=i+1;
			row--;
		}
	}
	printf("%d\n",(int)ans.size());
	for(pair<int,int>p:ans)printf("%d %d\n",p.first,p.second);
}