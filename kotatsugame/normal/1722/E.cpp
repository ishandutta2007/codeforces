#include<iostream>
using namespace std;
long long S[1000][1000];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		for(int i=0;i<1000;i++)for(int j=0;j<1000;j++)S[i][j]=0;
		int N,Q;
		cin>>N>>Q;
		for(int i=0;i<N;i++)
		{
			int h,w;cin>>h>>w;
			S[h-1][w-1]+=h*w;
		}
		for(int i=0;i<1000;i++)for(int j=0;j<999;j++)S[i][j+1]+=S[i][j];
		for(int i=0;i<999;i++)for(int j=0;j<1000;j++)S[i+1][j]+=S[i][j];
		for(int i=0;i<Q;i++)
		{
			int a,b,c,d;cin>>a>>b>>c>>d;
			cout<<S[c-2][d-2]-S[c-2][b-1]-S[a-1][d-2]+S[a-1][b-1]<<"\n";
		}
	}
}