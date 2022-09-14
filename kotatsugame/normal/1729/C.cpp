#include<iostream>
#include<vector>
using namespace std;
vector<int>ids[26];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		string S;cin>>S;
		for(int i=0;i<26;i++)ids[i].clear();
		for(int i=0;i<S.size();i++)ids[S[i]-'a'].push_back(i);
		int s=S[0]-'a',t=S.back()-'a';
		vector<int>ans;
		for(int i=s;;i<t?i++:i--)
		{
			for(int id:ids[i])ans.push_back(id);
			if(i==t)break;
		}
		cout<<abs(s-t)<<" "<<ans.size()<<"\n";
		for(int i=0;i<ans.size();i++)cout<<ans[i]+1<<(i+1==ans.size()?"\n":" ");
	}
}