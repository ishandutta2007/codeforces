#include<iostream>
#include<vector>
using namespace std;
int H,W;
string S[50];
int dx[8]={0,1,0,-1,1,1,-1,-1};
int dy[8]={1,0,-1,0,1,-1,1,-1};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>H>>W;
		for(int i=0;i<H;i++)
		{
			cin>>S[i];
		}
		bool ok=true;
		for(int i=0;i<H;i++)for(int j=0;j<W;j++)if(S[i][j]=='*')
		{
			vector<pair<int,int> >now;
			now.push_back(make_pair(i,j));
			S[i][j]='.';
			if(j+1<W&&S[i][j+1]=='*')
			{
				S[i][j+1]='.';
				now.push_back(make_pair(i,j+1));
				if(i+1<H&&S[i+1][j]=='*')
				{
					S[i+1][j]='.';
					now.push_back(make_pair(i+1,j));
				}
				else if(i+1<H&&S[i+1][j+1]=='*')
				{
					S[i+1][j+1]='.';
					now.push_back(make_pair(i+1,j+1));
				}
				else ok=false;
			}
			else if(i+1<H&&S[i+1][j]=='*')
			{
				S[i+1][j]='.';
				now.push_back(make_pair(i+1,j));
				if(j>0&&S[i+1][j-1]=='*')
				{
					S[i+1][j-1]='.';
					now.push_back(make_pair(i+1,j-1));
				}
				else if(j+1<W&&S[i+1][j+1]=='*')
				{
					S[i+1][j+1]='.';
					now.push_back(make_pair(i+1,j+1));
				}
				else ok=false;
			}
			else ok=false;
			for(pair<int,int>p:now)
			{
				int x=p.first,y=p.second;
				for(int r=0;r<8;r++)
				{
					int tx=x+dx[r],ty=y+dy[r];
					if(tx>=0&&ty>=0&&tx<H&&ty<W&&S[tx][ty]=='*')ok=false;
				}
			}
		}
		cout<<(ok?"YES\n":"NO\n");
	}
}