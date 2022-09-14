#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int x,A[3];
		cin>>x>>A[0]>>A[1]>>A[2];
		int op=1<<x-1;
		for(int _=0;_<3;_++)
		{
			for(int i=0;i<3;i++)if(op>>i&1)
			{
				if(A[i]>0)op|=1<<A[i]-1;
			}
		}
		cout<<(op==7?"YES\n":"NO\n");
	}
}