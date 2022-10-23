#include<iostream>
using namespace std;
string S[8];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		for(int i=0;i<8;i++)cin>>S[i];
		bool R=false;
		for(int i=0;i<8;i++)
		{
			bool all=true;
			for(int j=0;j<8;j++)if(S[i][j]!='R')all=false;
			if(all)R=true;
		}
		cout<<(R?"R\n":"B\n");
	}
}