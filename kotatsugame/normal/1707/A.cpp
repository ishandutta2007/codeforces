#include<iostream>
using namespace std;
int T,N,Q;
int A[1<<17];
bool ans[1<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N>>Q;
		for(int i=0;i<N;i++)cin>>A[i];
		int l=0;
		for(int i=N;i--;)
		{
			if(A[i]<=l)ans[i]=true;
			else
			{
				if(l<Q)
				{
					l++;
					ans[i]=true;
				}
				else ans[i]=false;
			}
		}
		for(int i=0;i<N;i++)cout<<(ans[i]?'1':'0');
		cout<<"\n";
	}
}