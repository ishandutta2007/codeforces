#include<iostream>
using namespace std;
int N,A[2<<17];
long long M;
long long cost(int id,int k)
{
	int l=A[id+1]-A[id];
	long long q=l/k;
	return q*q*(k-l%k)+(q+1)*(q+1)*(l%k);
}
main()
{
	cin>>N;
	for(int i=1;i<=N;i++)cin>>A[i];
	cin>>M;
	long long dl=1,dr=1e18;
	long long del;
	int ans;
	while(dr-dl>1)
	{
		long long d=(dl+dr)/2;
		long long sum=0;
		int cnt=0;
		for(int i=0;i<N;i++)
		{
			int kl=0,kr=A[i+1]-A[i];
			while(kr-kl>1)
			{
				int mid=(kl+kr)/2;
				if(cost(i,mid)-cost(i,mid+1)>=d)kl=mid;
				else kr=mid;
			}
			sum+=cost(i,kr);
			cnt+=kr-1;
		}
		if(sum<=M)dl=d,del=M-sum,ans=cnt;
		else dr=d;
	}
	cout<<ans-del/dl<<endl;
}