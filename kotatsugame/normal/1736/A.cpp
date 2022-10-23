#include<iostream>
using namespace std;
int N,A[100],B[100];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N;
		int a[2]={},b[2]={};
		for(int i=0;i<N;i++)
		{
			cin>>A[i];
			a[A[i]%2]++;
		}
		for(int i=0;i<N;i++)
		{
			cin>>B[i];
			b[B[i]%2]++;
		}
		int ans=0;
		for(int i=0;i<N;i++)if(A[i]!=B[i])ans++;
		ans=min(ans,abs(a[0]-b[0])+1);
		cout<<ans<<"\n";
	}
}