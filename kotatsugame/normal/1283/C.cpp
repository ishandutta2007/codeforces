#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int N,F[2<<17];
bool used[2<<17];
main()
{
	scanf("%d",&N);
	vector<int>A,B;
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&F[i]);
		if(F[i]>0)used[F[i]]=true;
		else
		{
			A.push_back(i);
		}
	}
	for(int i=1;i<=N;i++)
	{
		if(!used[i])B.push_back(i);
	}
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	int id=0;
	if(A.size()%2==1)
	{
		vector<int>now(3);
		for(int i=0;i<3;i++)now[i]=B[i];
		do{
			if(now[0]!=A[0]&&now[1]!=A[1]&&now[2]!=A[2])break;
		}while(next_permutation(now.begin(),now.end()));
		for(int i=0;i<3;i++)F[A[i]]=now[i];
		id=3;
	}
	for(;id<A.size();id+=2)
	{
		if(A[id]!=B[id]&&A[id+1]!=B[id+1])
		{
			F[A[id]]=B[id];
			F[A[id+1]]=B[id+1];
		}
		else
		{
			F[A[id]]=B[id+1];
			F[A[id+1]]=B[id];
		}
	}
	for(int i=1;i<=N;i++)printf("%d%c",F[i],i==N?'\n':' ');
}