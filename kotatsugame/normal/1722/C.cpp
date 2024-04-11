#include<iostream>
#include<map>
using namespace std;
map<string,int>cnt;
int N;
string S[3][1000];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N;
		cnt.clear();
		for(int i=0;i<3;i++)for(int j=0;j<N;j++)
		{
			cin>>S[i][j];
			cnt[S[i][j]]++;
		}
		for(int i=0;i<3;i++)
		{
			int ans=0;
			for(int j=0;j<N;j++)
			{
				int c=cnt[S[i][j]];
				ans+=c==1?3:c==2?1:0;
			}
			cout<<ans<<(i==2?"\n":" ");
		}
	}
}