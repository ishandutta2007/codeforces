#include<iostream>
using namespace std;
int T,N,K;
string S;
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N>>K>>S;
		int r=N-1;
		while(r>=0&&S[r]=='0')r--;
		if(r<0)
		{
			cout<<"0\n";
			continue;
		}
		int l=0;
		while(S[l]=='0')l++;
		if(l==r)
		{
			if(N-r-1<=K)S[r]='0',S[N-1]='1';
			else if(l<=K)S[l]='0',S[0]='1';
		}
		else
		{
			if(N-r-1<=K)S[r]='0',S[N-1]='1',K-=N-r-1;
			if(l<=K)S[l]='0',S[0]='1';
		}
		int ans=0;
		for(int i=0;i<N;i++)if(S[i]=='1')
		{
			if(i==0)ans+=10;
			else if(i==N-1)ans+=1;
			else ans+=11;
		}
		cout<<ans<<"\n";
	}
}