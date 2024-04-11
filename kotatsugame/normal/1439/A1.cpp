#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int T;
int N,M;
string s[100];
struct dat{
	int x1,y1,x2,y2,x3,y3;
	void disp(){
		printf("%d %d %d %d %d %d\n",x1+1,y1+1,x2+1,y2+1,x3+1,y3+1);
	}
};
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>N>>M;
		for(int i=0;i<N;i++)cin>>s[i];
		vector<dat>ans;
		for(int i=0;i<N-2;i++)
		{
			for(int j=0;j<M-2;j++)if(s[i][j]=='1')
			{
				ans.push_back(dat());
				s[i][j]^=1;
				s[i+1][j]^=1;
				s[i+1][j+1]^=1;
				ans.back().x1=i;
				ans.back().x2=i+1;
				ans.back().x3=i+1;
				ans.back().y1=j;
				ans.back().y2=j;
				ans.back().y3=j+1;
			}
			if(s[i][M-2]=='1'||s[i][M-1]=='1')
			{
				ans.push_back(dat());
				if(s[i][M-2]=='1'&&s[i][M-1]=='1')
				{
					ans.back().x1=i;
					ans.back().x2=i;
					ans.back().x3=i+1;
					ans.back().y1=M-2;
					ans.back().y2=M-1;
					ans.back().y3=M-2;
				}
				else if(s[i][M-2]=='1')
				{
					ans.back().x1=i;
					ans.back().x2=i+1;
					ans.back().x3=i+1;
					ans.back().y1=M-2;
					ans.back().y2=M-2;
					ans.back().y3=M-1;
				}
				else
				{
					ans.back().x1=i;
					ans.back().x2=i+1;
					ans.back().x3=i+1;
					ans.back().y1=M-1;
					ans.back().y2=M-2;
					ans.back().y3=M-1;
				}
				s[ans.back().x1][ans.back().y1]^=1;
				s[ans.back().x2][ans.back().y2]^=1;
				s[ans.back().x3][ans.back().y3]^=1;
			}
		}
		for(int j=0;j<M-2;j++)if(s[N-2][j]=='1'||s[N-1][j]=='1')
		{
			ans.push_back(dat());
			if(s[N-2][j]=='1'&&s[N-1][j]=='1')
			{
				ans.back().x1=N-2;
				ans.back().x2=N-1;
				ans.back().x3=N-2;
				ans.back().y1=j;
				ans.back().y2=j;
				ans.back().y3=j+1;
			}
			else if(s[N-2][j]=='1')
			{
				ans.back().x1=N-2;
				ans.back().x2=N-2;
				ans.back().x3=N-1;
				ans.back().y1=j;
				ans.back().y2=j+1;
				ans.back().y3=j+1;
			}
			else
			{
				ans.back().x1=N-1;
				ans.back().x2=N-2;
				ans.back().x3=N-1;
				ans.back().y1=j;
				ans.back().y2=j+1;
				ans.back().y3=j+1;
			}
			s[ans.back().x1][ans.back().y1]^=1;
			s[ans.back().x2][ans.back().y2]^=1;
			s[ans.back().x3][ans.back().y3]^=1;
		}
		while(true)
		{
			vector<pair<int,int> >one,zero;
			for(int i=N-2;i<N;i++)for(int j=M-2;j<M;j++)
			{
				if(s[i][j]=='1')one.push_back(make_pair(i,j));
				else zero.push_back(make_pair(i,j));
			}
			if(one.size()==0)break;
			dat now;
			if(one.size()>=3)
			{
				now.x1=one[0].first;
				now.y1=one[0].second;
				now.x2=one[1].first;
				now.y2=one[1].second;
				now.x3=one[2].first;
				now.y3=one[2].second;
			}
			else
			{
				now.x1=one[0].first;
				now.y1=one[0].second;
				now.x2=zero[0].first;
				now.y2=zero[0].second;
				now.x3=zero[1].first;
				now.y3=zero[1].second;
			}
			s[now.x1][now.y1]^=1;
			s[now.x2][now.y2]^=1;
			s[now.x3][now.y3]^=1;
			ans.push_back(now);
		}
		printf("%d\n",(int)ans.size());
		for(int i=0;i<ans.size();i++)ans[i].disp();
	}
}