#include<iostream>
#include<stack>
using namespace std;
int N;
int P[1000],ans[1000];
main()
{
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>P[i];
		P[i]--;
		ans[i]=-1;
	}
	for(int i=0;i<N;i++)if(ans[i]==-1)
	{
		int u=i;
		stack<int>S;
		do{
			S.push(u);
			ans[u]=-2;
			u=P[u];
		}while(ans[u]==-1);
		if(ans[u]!=-2)
		{
			while(!S.empty())
			{
				int v=S.top();S.pop();
				ans[v]=ans[u];
			}
		}
		else
		{
			while(!S.empty())
			{
				int v=S.top();S.pop();
				ans[v]=v;
				if(v==u)break;
			}
			while(!S.empty())
			{
				ans[S.top()]=u;
				S.pop();
			}
		}
	}
	for(int i=0;i<N;i++)cout<<ans[i]+1<<(i+1==N?"\n":" ");
}