#include<iostream>
#include<vector>
using namespace std;
vector<int>id[26];
string S,T;
main()
{
	int N;cin>>N;
	for(;N--;)
	{
		for(int i=0;i<26;i++)id[i].clear();
		cin>>S>>T;
		for(int i=0;i<S.size();i++)id[S[i]-'A'].push_back(i);
		bool ok=true;
		int lst=S.size();
		for(int i=T.size();i--;)
		{
			int j=T[i]-'A';
			if(id[j].empty())ok=false;
			else if(id[j].back()>=lst)ok=false;
			else
			{
				lst=id[j].back();
				id[j].pop_back();
			}
		}
		cout<<(ok?"YES\n":"NO\n");
	}
}