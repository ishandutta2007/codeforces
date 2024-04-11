#include<iostream>
using namespace std;
int T;
string S;
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>S;
		if(S.back()!='B')
		{
			cout<<"NO\n";
			continue;
		}
		int cnt=0;
		for(int i=S.size();i--;)
		{
			if(S[i]=='B')cnt++;
			else if(cnt>0)cnt--;
		}
		cout<<(cnt>0?"NO\n":"YES\n");
	}
}