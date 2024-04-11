#include<iostream>
using namespace std;
int N,cnt[55];
main()
{
	cin>>N;
	int mi=99;
	for(int i=0;i<N;i++)
	{
		int a;cin>>a;cnt[a]++;
		if(mi>a)mi=a;
	}
	cout<<(cnt[mi]>N/2?"Bob":"Alice")<<endl;
}