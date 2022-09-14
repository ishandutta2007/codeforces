#include<iostream>
#include<vector>
using namespace std;
string S,T;
int cs[26];
main()
{
	cin>>S>>T;
	vector<int>id;
	for(int i=0;i<S.size();i++)
	{
		if(S[i]=='?')id.push_back(i);
		else cs[S[i]-'a']++;
	}
	while(true)
	{
		bool ok=true;
		for(char c:T)
		{
			if(cs[c-'a']>0)
			{
				cs[c-'a']--;
			}
			else if(!id.empty())
			{
				S[id.back()]=c;
				id.pop_back();
			}
			else
			{
				ok=false;
				break;
			}
		}
		if(!ok)break;
	}
	cout<<S<<endl;
}