#include<iostream>
#include<vector>
using namespace std;
int N;
long long K;
long long A[2<<17];
main()
{
	cin>>N>>K;
	vector<int>iA(N);
	for(int i=0;i<N;i++)
	{
		cin>>iA[i];
		if(iA[i]>=K)
		{
			cout<<0<<endl;
			return 0;
		}
	}
	int id=0;
	while(iA[id]==0)id++;
	for(int j=id;j<N;j++)A[j-id]=iA[j];
	if(N-id==2)
	{
		long long a=A[0],b=A[1];
		long long i=(K-b+a-1)/a;
		cout<<i<<endl;
	}
	else if(N-id==3)
	{
		long long a=A[0],b=A[1],c=A[2];
		K-=c;
		long long L=0,R=1e18;
		while(R-L>1)
		{
			long long mid=(L+R)/2;
			if(b>K/mid)R=mid;
			else
			{
				long long k=K-b*mid;
				k=(k+a-1)/a;
				k*=2;
				k-=mid;
				if(k<0||mid>k/mid||mid*mid>=k)R=mid;
				else L=mid;
			}
		}
		cout<<R<<endl;
	}
	else
	{
		for(int tm=1;;tm++)
		{
			for(int i=1;i<N-id;i++)
			{
				A[i]+=A[i-1];
				if(A[i]>=K)
				{
					cout<<tm<<endl;
					return 0;
				}
			}
		}
	}
}