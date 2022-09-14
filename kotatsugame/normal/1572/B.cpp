#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int T,N;
vector<int>calc(vector<int>A)
{
	vector<int>ans;
	if(A[0]==1)
	{
		int id=0;
		while(id<N&&A[id]==1)id++;
		if(id==N)return{-1};
		if(id%2==1)
		{
			while(id+1<N&&A[id]==A[id+1])
			{
				if(A[id]==0)
				{
					ans.push_back(id);
					A[id]=A[id+1]=1;
				}
				id+=2;
			}
			if(id+1>=N)return{-1};
			ans.push_back(id);
			A[id-1]=A[id]=A[id+1]=0;
			id--;
		}
		for(int k=id;k>0;k-=2)
		{
			ans.push_back(k-1);
			A[k-2]=A[k-1]=0;
		}
	}
	for(int i=1;i<N;i++)if(A[i]==1)
	{
		if(i+1<N&&A[i+1]==1)
		{
			ans.push_back(i);
			A[i]=A[i+1]=0;
		}
		else if(i+2<N&&A[i+2]==1)
		{
			ans.push_back(i+1);
			A[i]=A[i+2]=0;
		}
		else if(i+2<N)
		{
			ans.push_back(i+1);
			A[i+1]=A[i+2]=1;
			ans.push_back(i);
			A[i]=A[i+1]=0;
		}
	}
	for(int i=0;i<N;i++)if(A[i]==1)return{-1};
	return ans;
}
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		vector<int>A(N);
		for(int i=0;i<N;i++)scanf("%d",&A[i]);
		vector<int>X=calc(A);
		if(!X.empty()&&X[0]==-1)puts("NO");
		else
		{
			puts("YES");
			vector<int>ans=X;
			printf("%d\n",ans.size());
			for(int i=0;i<ans.size();i++)printf("%d%c",ans[i],i+1==ans.size()?10:32);
		}
	}
}