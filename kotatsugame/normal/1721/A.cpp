#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		map<char,int>mp;
		for(int i=0;i<2;i++)
		{
			string s;cin>>s;
			mp[s[0]]++;
			mp[s[1]]++;
		}
		vector<int>t;
		for(pair<char,int>p:mp)t.push_back(p.second);
		sort(t.begin(),t.end());
		reverse(t.begin(),t.end());
		if(t[0]==4)cout<<"0\n";
		else if(t[0]==3)cout<<"1\n";
		else if(t[0]==2)
		{
			if(t.size()==2)cout<<"1\n";
			else cout<<"2\n";
		}
		else cout<<"3\n";
	}
}