#include<iostream>
#include<algorithm>
using namespace std;
long long gcd(long long a,long long b)
{
	while(b)
	{
		long long t=a%b;
		a=b;
		b=t;
	}
	return a;
}
int T,N,P[200];
string S;
bool vis[200];
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
			cin>>P[i];
			P[i]--;
			vis[i]=false;
		}
		long long ans=1;
		for(int i=0;i<N;i++)if(!vis[i])
		{
			string now="";
			int u=i;
			while(!vis[u])
			{
				now+=S[u];
				vis[u]=true;
				u=P[u];
			}
			int ord=now.size();
			for(int l=1;l*2<=now.size();l++)if(now.size()%l==0)
			{
				bool ok=true;
				for(int j=0;ok&&j<l;j++)
				{
					char c=now[j];
					for(int k=j+l;k<now.size();k+=l)if(c!=now[k])
					{
						ok=false;
						break;
					}
				}
				if(ok)
				{
					ord=l;
					break;
				}
			}
			ans=ans/gcd(ans,ord)*ord;
		}
		cout<<ans<<"\n";
	}
}