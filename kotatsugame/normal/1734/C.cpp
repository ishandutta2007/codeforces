#include<iostream>
using namespace std;
string t;
bool vis[1<<20];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int N;cin>>N>>t;
		for(int i=1;i<=N;i++)vis[i]=false;
		long long ans=0;
		for(int i=1;i<=N;i++)
		{
			for(int j=i;j<=N;j+=i)
			{
				if(t[j-1]=='1')break;
				if(!vis[j])
				{
					vis[j]=true;
					ans+=i;
				}
			}
		}
		cout<<ans<<"\n";
	}
}