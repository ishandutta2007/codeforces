#include<iostream>
using namespace std;
const int mod=998244353;
int T,N,S;
int A[2<<17],B[2<<17],invA[2<<17];
bool visB[2<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N>>S;
		for(int i=0;i<N;i++)
		{
			cin>>invA[i];
			invA[i]--;
			A[invA[i]]=i;
			B[i]=-1;
		}
		for(int i=0;i<N;i++)
		{
			int invB;
			cin>>invB;
			if(invB!=-1)
			{
				invB--;
				B[invB]=i;
				visB[i]=true;
			}
			else visB[i]=false;
		}
		long long ans=1;
		int cnt=0,r=0;
		for(int i=0;i<N;i++)
		{
			while(r<=min(i+S,N-1))if(!visB[A[r++]])cnt++;
			if(B[i]==-1)
			{
				if(cnt>0)ans=ans*cnt--%mod;
				else ans=0;
			}
			else if(invA[B[i]]>=r)ans=0;
		}
		cout<<ans<<"\n";
	}
}