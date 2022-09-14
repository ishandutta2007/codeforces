#include<iostream>
#include<vector>
using namespace std;
string S[100];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int H,W;
		cin>>H>>W;
		for(int i=0;i<H;i++)cin>>S[i];
		if(S[0][0]=='1')
		{
			cout<<"-1\n";
			continue;
		}
		vector<pair<int,int> >ans;
		for(int i=H;i--;)for(int j=W;j--;)if(S[i][j]=='1')
		{
			ans.push_back(make_pair(i,j));
		}
		cout<<ans.size()<<"\n";
		for(pair<int,int>p:ans)
		{
			int x=p.first+1,y=p.second+1;
			if(x>1)cout<<x-1<<" "<<y<<" "<<x<<" "<<y<<"\n";
			else cout<<x<<" "<<y-1<<" "<<x<<" "<<y<<"\n";
		}
	}
}