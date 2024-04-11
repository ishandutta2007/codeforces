#include<iostream>
#include<queue>
using namespace std;
int N,K;
string S[1000];
bool ans[1000][1000];
queue<pair<int,int> >Q[2000];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N>>K;
		for(int i=0;i<N;i++)cin>>S[i];
		for(int i=0;i<N;i++)for(int j=0;j<N;j++)ans[i][j]=false;
		for(int i=0;i<2*N-1;i++)
		{
			while(!Q[i].empty())Q[i].pop();
			if(i<N)
			{
				int sz=i+1;
				if(sz<=K-1)
				{
					for(int j=0;j<sz;j++)
					{
						ans[j][j+(N-1-i)]=true;
					}
				}
				else
				{
					for(int j=0;j<sz;j++)
					{
						if(S[j][j+(N-1-i)]=='0')Q[i].push(make_pair(j,j+(N-1-i)));
					}
				}
			}
			else
			{
				int sz=2*N-1-i;
				if(sz<=K-1)
				{
					for(int j=0;j<sz;j++)
					{
						ans[j+(i-N+1)][j]=true;
					}
				}
				else
				{
					for(int j=0;j<sz;j++)
					{
						if(S[j+(i-N+1)][j]=='0')Q[i].push(make_pair(j+(i-N+1),j));
					}
				}
			}
		}
		bool ok=true;
		for(int p=0;p<K-1;p++)
		{
			int x=p,y=(N-1)-(K-2-p);
			int tx=(N-1)-(K-2-p),ty=p;
			int lj=K-1,rj=2*N-1-K;
			for(int j=lj-1;j<=rj;j++)
			{
				if(y<0)
				{
					ok=false;
					break;
				}
				ans[x][y]=true;
				if(!Q[j].empty()&&Q[j].front()==make_pair(x,y))Q[j].pop();
				if(x<tx)
				{
					int nx=x+1,ny=y;
					bool tok=true;
					for(int nj=j+1;nj<=rj;nj++)if(!Q[nj].empty())
					{
						pair<int,int>q=Q[nj].front();
						if(q.first<nx)
						{
							tok=false;
							break;
						}
					}
					if(tok)x++;
					else y--;
				}
				else y--;
			}
		}
		for(int i=0;i<2*N-1;i++)
		{
			if(!Q[i].empty())ok=false;
		}
		if(ok)
		{
			cout<<"YES\n";
			for(int i=0;i<N;i++)
			{
				for(int j=0;j<N;j++)cout<<(ans[i][j]?'1':'0');
				cout<<"\n";
			}
			continue;
		}
		else cout<<"NO\n";
	}
}