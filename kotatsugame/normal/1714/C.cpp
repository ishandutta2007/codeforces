#include<iostream>
using namespace std;
string ans[46];
int num[46];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for(int t=1;t<1<<9;t++)
	{
		int s=0;
		string now="";
		int tx=0;
		for(int j=1;j<=9;j++)if(t>>j-1&1)
		{
			s+=j;
			now+=j+'0';
			tx=tx*10+j;
		}
		if(num[s]==0||num[s]>tx)
		{
			num[s]=tx;
			ans[s]=now;
		}
	}
	int T;cin>>T;
	for(;T--;)
	{
		int s;cin>>s;
		cout<<ans[s]<<"\n";
	}
}