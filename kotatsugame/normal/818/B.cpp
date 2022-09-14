#include<iostream>
#include<vector>
using namespace std;
int N,M;
int L[101];
main()
{
	cin>>N>>M;
	for(int i=0;i<M;i++)cin>>L[i];
	vector<int>ans(N,-1),ex(N);
	for(int i=1;i<M;i++)
	{
		int u=L[i-1]-1,v=L[i]-1;
		int d=(v-u+N)%N;
		if(d==0)d=N;
		if(ans[u]==-1)
		{
			if(ex[d-1])
			{
				cout<<-1<<endl;
				return 0;
			}
			ex[d-1]=1;
			ans[u]=d;
		}
		else if(ans[u]!=d)
		{
			cout<<-1<<endl;
			return 0;
		}
	}
	int id=0;
	for(int i=0;i<N;i++)if(ans[i]==-1)
	{
		while(ex[id])id++;
		ans[i]=id+1;
		ex[id]=1;
	}
	for(int i=0;i<N;i++)cout<<ans[i]<<(i+1==N?"\n":" ");
}