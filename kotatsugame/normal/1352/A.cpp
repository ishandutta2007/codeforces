#include<iostream>
#include<vector>
using namespace std;
int T;
main()
{
	cin>>T;
	for(;T--;)
	{
		string N;cin>>N;
		vector<string>ans;
		for(int i=0;i<N.size();i++)
		{
			for(string&s:ans)s+='0';
			if(N[i]!='0')ans.push_back(N.substr(i,1));
		}
		cout<<ans.size()<<"\n";
		for(int i=0;i<ans.size();i++)cout<<ans[i]<<(i+1==ans.size()?"\n":" ");
	}
}