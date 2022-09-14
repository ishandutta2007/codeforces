#include<iostream>
#include<vector>
using namespace std;
int N;
vector<int>ids[3];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N;
	for(int i=0;i<N;i++)
	{
		int a;cin>>a;
		ids[a%3].push_back(i);
	}
	int Z=-1;
	string ans;
	if(ids[0].size()<=N/2)
	{
		Z=0;
		ans=string(N,'1');
		for(int id:ids[0])ans[id]='0';
		int c=ids[0].size();
		for(int i=0;i<ids[1].size()&&c<N/2;i++,c++)ans[ids[1][i]]='0';
		for(int i=0;i<ids[2].size()&&c<N/2;i++,c++)ans[ids[2][i]]='0';
	}
	else
	{
		Z=2;
		ans=string(N,'1');
		for(int i=0;i<N/2;i++)ans[ids[0][i]]='0';
	}
	cout<<Z<<"\n"<<ans<<"\n";
}