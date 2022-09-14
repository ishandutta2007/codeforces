#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int T,N,X,Y;
int A[1<<17],B[1<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d%d",&N,&X,&Y);
		vector<vector<int> >ids(N+2);
		for(int i=0;i<N;i++)
		{
			scanf("%d",&A[i]);
			B[i]=0;
			ids[A[i]].push_back(i);
		}
		int no=1;
		while(!ids[no].empty())no++;
		int T=(N-X)/2;
		int R=X;
		for(int i=1;i<=N+1;i++)
		{
			while(R>0&&ids[i].size()>T)
			{
				B[ids[i].back()]=i;
				ids[i].pop_back();
				R--;
			}
		}
		for(int i=1;i<=N+1;i++)
		{
			while(R>0&&!ids[i].empty())
			{
				B[ids[i].back()]=i;
				ids[i].pop_back();
				R--;
			}
		}
		vector<int>rest;
		sort(ids.begin(),ids.end(),[](const vector<int>&A,const vector<int>&B){return A.size()>B.size();});
		for(int i=0;i<=N+1;i++)
		{
			for(int id:ids[i])rest.push_back(id);
		}
		for(int i=0;i<rest.size();i++)
		{
			B[rest[i]]=A[rest[(i+T)%rest.size()]];
		}
		int x=0;
		for(int i=0;i<N;i++)if(A[i]==B[i])
		{
			if(x<X)x++;
			else
			{
				B[i]=no;
				Y++;
			}
		}
		for(int i=0;i<N;i++)if(Y<N&&A[i]!=B[i]&&B[i]!=no)
		{
			B[i]=no;
			Y++;
		}
		if(x==X&&Y==N)
		{
			puts("YES");
			for(int i=0;i<N;i++)printf("%d%c",B[i],i+1==N?'\n':' ');
		}
		else puts("NO");
	}
}