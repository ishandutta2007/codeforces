#include<iostream>
using namespace std;
int N,Q;
int A[1<<17];
long long add[2];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N>>Q;
		int c[2]={};
		long long sum=0;
		for(int i=0;i<N;i++)
		{
			cin>>A[i];
			sum+=A[i];
			c[A[i]%2]++;
		}
		add[0]=add[1]=0;
		for(int i=0;i<Q;i++)
		{
			int t,x;cin>>t>>x;
			for(int j=0;j<2;j++)if((add[j]+j)%2==t)
			{
				add[j]+=x;
			}
			long long now=sum;
			now+=add[0]*c[0];
			now+=add[1]*c[1];
			cout<<now<<"\n";
		}
	}
}