#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N,M;
int A[1010][1010];
vector<int>X[1010],Y[1010];
main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			scanf("%d",&A[i][j]);
			X[i].push_back(A[i][j]);
			Y[j].push_back(A[i][j]);
		}
	}
	for(int i=0;i<N;i++)
	{
		sort(X[i].begin(),X[i].end());
		X[i].erase(unique(X[i].begin(),X[i].end()),X[i].end());
	}
	for(int i=0;i<M;i++)
	{
		sort(Y[i].begin(),Y[i].end());
		Y[i].erase(unique(Y[i].begin(),Y[i].end()),Y[i].end());
	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			int a=A[i][j];
			int x=lower_bound(X[i].begin(),X[i].end(),a)-X[i].begin();
			int y=lower_bound(Y[j].begin(),Y[j].end(),a)-Y[j].begin();
			int L=X[i].size(),R=Y[j].size();
			if(x>=y)R+=x-y;
			else L+=y-x;
			printf("%d%c",max(L,R),j+1==M?'\n':' ');
		}
	}
}