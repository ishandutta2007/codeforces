#include<iostream>
using namespace std;
int N;
int A[2<<17];
string S;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N>>S;
		for(int i=0;i<N;i++)cin>>A[i];
		int ans=0;
		for(int i=0;i<N;)
		{
			if(S[i]=='0')i++;
			else
			{
				int j=i;
				int now=0;
				int mn=2e9;
				while(j<N&&S[j]=='1')
				{
					now+=A[j];
					mn=min(mn,A[j]);
					j++;
				}
				if(i==0)ans+=now;
				else
				{
					now+=A[i-1];
					mn=min(mn,A[i-1]);
					ans+=now-mn;
				}
				i=j;
			}
		}
		cout<<ans<<"\n";
	}
}