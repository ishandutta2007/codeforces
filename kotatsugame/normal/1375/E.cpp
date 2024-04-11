#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N;
int A[1001];
int T[1001];
main()
{
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&A[i]);
		T[i]=A[i];
	}
	vector<pair<int,int> >ans;
	for(int i=N;i>=1;i--)
	{
		vector<pair<int,int> >X;
		for(int j=1;j<i;j++)if(A[j]>A[i])X.push_back(make_pair(A[j],j));
		sort(X.begin(),X.end());
		for(int j=0;j<X.size();j++)
		{
			int id=X[j].second;
			swap(T[id],T[i]);
			ans.push_back(make_pair(id,i));
		}
	}
	printf("%d\n",(int)ans.size());
	for(pair<int,int>p:ans)printf("%d %d\n",p.first,p.second);
}