#include<iostream>
using namespace std;
int N,K;
int A[1<<17];
int sum;
int ans[1<<17];
main()
{
	cin>>N>>K;
	for(int i=0;i<N;i++)
	{
		cin>>A[i];
		sum+=A[i];
	}
	if(sum%K!=0)
	{
		cout<<"No"<<endl;
		return 0;
	}
	sum/=K;
	int sz=0;
	for(int i=0;i<N;)
	{
		int j=i;
		int now=0;
		while(now<sum&&j<N)now+=A[j++];
		if(now!=sum)
		{
			cout<<"No"<<endl;
			return 0;
		}
		ans[sz++]=j-i;
		i=j;
	}
	cout<<"Yes"<<endl;
	for(int i=0;i<K;i++)cout<<ans[i]<<(i+1==K?"\n":" ");
}