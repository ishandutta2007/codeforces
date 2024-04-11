#include<iostream>
using namespace std;
int N,K,cnt[101];
main()
{
	cin>>N>>K;
	for(int i=0;i<N;i++)
	{
		int a;cin>>a;
		cnt[a]++;
	}
	int tm=0,se=0;
	for(int i=1;i<=100;i++)if(cnt[i])
	{
		se++;
		if(tm<(cnt[i]+K-1)/K)tm=(cnt[i]+K-1)/K;
	}
	cout<<tm*se*K-N<<endl;
}