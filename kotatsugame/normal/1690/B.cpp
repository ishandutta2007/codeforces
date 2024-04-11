#include<iostream>
using namespace std;
int T,N;
int A[50000],B[50000];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)cin>>A[i];
		for(int i=0;i<N;i++)cin>>B[i];
		int mx=0;
		bool fn=false;
		for(int i=0;i<N;i++)
		{
			if(A[i]<B[i])fn=true;
			else mx=max(mx,A[i]-B[i]);
		}
		if(fn)
		{
			cout<<"NO\n";
			continue;
		}
		for(int i=0;i<N;i++)
		{
			A[i]-=mx;
			if(A[i]<0)A[i]=0;
			if(A[i]!=B[i])fn=true;
		}
		cout<<(fn?"NO\n":"YES\n");
	}
}