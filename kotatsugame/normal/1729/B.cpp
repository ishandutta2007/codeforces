#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int N;
		string s,t;
		cin>>N>>s;
		for(int i=N-1;i>=0;)
		{
			int v;
			if(s[i]=='0')
			{
				v=(s[i-2]-'0')*10+(s[i-1]-'0');
				i-=3;
			}
			else v=s[i--]-'0';
			t+='a'+v-1;
		}
		reverse(t.begin(),t.end());
		cout<<t<<"\n";
	}
}