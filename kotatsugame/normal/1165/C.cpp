#include<iostream>
using namespace std;
main()
{
	int N;string S;
	cin>>N>>S;
	string ans="";
	for(char c:S)
	{
		if(ans.size()%2==0||ans.back()!=c)ans+=c;
	}
	if(ans.size()%2)ans.pop_back();
	cout<<N-ans.size()<<endl<<ans<<endl;
}