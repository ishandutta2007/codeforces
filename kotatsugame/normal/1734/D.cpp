#include<iostream>
#include<algorithm>
using namespace std;
int N,K;
int A[2<<17];
long long S[2<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N>>K;K--;
		for(int i=0;i<N;i++)cin>>A[i];
		S[0]=0;
		for(int i=0;i<N;i++)S[i+1]=S[i]+A[i];
		int l=K,r=K+1;
		long long L=S[l],R=S[r];
		while(l>0&&r<N)
		{
			if(R-S[l-1]>=0)
			{
				l--;
				L=min(L,S[l]);
			}
			else if(S[r+1]-L>=0)
			{
				r++;
				R=max(R,S[r]);
			}
			else break;
		}
		cout<<(l==0||r==N?"YES\n":"NO\n");
	}
}