#include<iostream>
#include<bitset>
using namespace std;
int N,K;
string tmp[10]={"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
int bin[10];
int S[2000];
int to[2000][10];
bitset<2001>OK[2001];
main()
{
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<tmp[i].size();j++)bin[i]=bin[i]*2+tmp[i][j]-'0';
	}
	cin>>N>>K;
	for(int i=0;i<N;i++)
	{
		string s;
		cin>>s;
		for(int j=0;j<s.size();j++)S[i]=S[i]*2+s[j]-'0';
		for(int j=0;j<10;j++)
		{
			if(!(~bin[j]&S[i]))to[i][j]=__builtin_popcount(bin[j]&~S[i]);
			else to[i][j]=-1;
		}
	}
	OK[N][0]=1;
	for(int i=N;i--;)
	{
		for(int j=0;j<10;j++)if(to[i][j]!=-1)OK[i]|=OK[i+1]<<to[i][j];
	}
	if(OK[0][K]==0)
	{
		cout<<-1<<endl;
		return 0;
	}
	string ans="";
	for(int i=0;i<N;i++)
	{
		for(int j=10;j--;)
		{
			if(to[i][j]==-1)continue;
			if(K>=to[i][j]&&OK[i+1][K-to[i][j]]==1)
			{
				ans+=j+'0';
				K-=to[i][j];
				break;
			}
		}
	}
	cout<<ans<<endl;
}