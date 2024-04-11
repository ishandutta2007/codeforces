#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int T,N,A[2<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)cin>>A[i];
		sort(A,A+N);
		bool ok=true;
		if(N>=6)
		{
			if(A[1]!=0||A[N-2]!=0)ok=false;
			else
			{
				int t=A[0]+A[N-1];
				int id=lower_bound(A,A+N,t)-A;
				if(id<0||N<=id||A[id]!=t)ok=false;
			}
		}
		else
		{
			for(int i=0;i<N;i++)for(int j=i+1;j<N;j++)for(int k=j+1;k<N;k++)
			{
				long t=A[i]+A[j];
				t+=A[k];
				if(t<A[0]||A[N-1]<t)ok=false;
				else
				{
					int id=lower_bound(A,A+N,(int)t)-A;
					if(id<0||N<=id||A[id]!=t)ok=false;
				}
			}
		}
		cout<<(ok?"YES\n":"NO\n");
	}
}