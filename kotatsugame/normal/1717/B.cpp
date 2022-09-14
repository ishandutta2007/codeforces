#include<iostream>
using namespace std;
string S[500];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int N,K,R,C;
		cin>>N>>K>>R>>C;
		R--;R%=K;C--;C%=K;
		for(int i=0;i<N;i++)S[i]=string(N,'.');
		for(int i=0;i<K;i++)
		{
			S[(R+i)%K][(C+i)%K]='X';
		}
		for(int i=0;i<K;i++)for(int j=K;j<N;j++)S[i][j]=S[i][j-K];
		for(int i=K;i<N;i++)for(int j=0;j<N;j++)S[i][j]=S[i-K][j];
		for(int i=0;i<N;i++)cout<<S[i]<<"\n";
	}
}