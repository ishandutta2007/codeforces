#include<iostream>
#include<algorithm>
using namespace std;
int N,M;
string S[500];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N>>M;
		int cnt=0;
		for(int i=0;i<N;i++)
		{
			cin>>S[i];
			for(int j=0;j<M;j++)if(S[i][j]=='1')cnt++;
		}
		if(cnt==0)
		{
			cout<<"0\n";
			continue;
		}
		int mx=3;
		for(int i=0;i<N;i++)for(int j=0;j<M;j++)
		{
			int m=S[i][j]-'0';
			int a=i+1<N?S[i+1][j]-'0':1e9;
			int b=i>0?S[i-1][j]-'0':1e9;
			int c=j+1<M?S[i][j+1]-'0':1e9;
			int d=j>0?S[i][j-1]-'0':1e9;
			if(m+a+c>0)mx=min(mx,m+a+c);
			if(m+a+d>0)mx=min(mx,m+a+d);
			if(m+b+c>0)mx=min(mx,m+b+c);
			if(m+b+d>0)mx=min(mx,m+b+d);
		}
		cout<<cnt-mx+1<<"\n";
	}
}