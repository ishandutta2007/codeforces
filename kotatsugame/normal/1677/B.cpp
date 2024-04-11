#include<iostream>
using namespace std;
int T,N,M;
string S;
int a1[1<<20],a2[1<<20];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N>>M>>S;
		for(int i=0;i<N*M;i++)a1[i]=a2[i]=0;
		{
			int cnt=0;
			for(int i=0;i<N*M;i++)
			{
				cnt+=S[i]-'0';
				if(i>=M)cnt-=S[i-M]-'0';
				if(cnt>0)a1[i]++;
			}
			for(int i=0;i+M<N*M;i++)a1[i+M]+=a1[i];
		}
		for(int j=0;j<M;j++)
		{
			int i;
			for(i=j;i<N*M;i+=M)if(S[i]=='1')break;
			if(i>=N*M)continue;
			a2[i]++;
		}
		for(int i=0;i+1<N*M;i++)a2[i+1]+=a2[i];
		for(int i=0;i<N*M;i++)cout<<a1[i]+a2[i]<<(i+1==N*M?"\n":" ");
	}
}