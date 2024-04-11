#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N,M;
string S[500];
int d[5]={0,1,0,-1};
vector<int>G[250000];
int col[250000];
main()
{
	cin>>N>>M;
	for(int i=0;i<N;i++)cin>>S[i];
	for(int i=0;i<N;i++)for(int j=0;j<M;j++)if(S[i][j]=='X')
	{
		vector<int>op;
		for(int r=0;r<4;r++)
		{
			int x=i+d[r],y=j+d[r+1];
			if(S[x][y]=='.')op.push_back(x*M+y);
		}
		if(op.size()%2)
		{
			cout<<"NO"<<endl;
			return 0;
		}
		for(int r=0;r<op.size();r++)
		{
			int u=op[r],v=op[(r+1)%op.size()];
			G[u].push_back(v);
			G[v].push_back(u);
		}
		col[i*M+j]=op.size()/2*5;
	}
	for(int i=0;i<N;i++)for(int j=0;j<M;j++)if(S[i][j]=='.'&&col[i*M+j]==0)
	{
		col[i*M+j]=1;
		queue<int>P;
		P.push(i*M+j);
		while(!P.empty())
		{
			int u=P.front();
			P.pop();
			for(int v:G[u])
			{
				if(!col[v])
				{
					col[v]=5-col[u];
					P.push(v);
				}
				if(col[v]==col[u])
				{
					cout<<"NO"<<endl;
					return 0;
				}
			}
		}
	}
	cout<<"YES\n";
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			cout<<col[i*M+j]<<(j+1==M?'\n':' ');
		}
	}
}