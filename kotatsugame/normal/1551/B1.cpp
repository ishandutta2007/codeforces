#include<iostream>
using namespace std;
int T;
main()
{
	cin>>T;
	for(;T--;)
	{
		string S;cin>>S;
		int cnt[26]={};
		int all=0;
		for(char c:S)
		{
			int id=c-'a';
			if(cnt[id]++<2)all++;
		}
		cout<<all/2<<endl;
	}
}