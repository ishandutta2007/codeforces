#include<iostream>
#include<vector>
using namespace std;
int inv[2<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int N;cin>>N;
		for(int i=0;i<N;i++)
		{
			int P;cin>>P;
			inv[P]=i;
		}
		long long ans=0;
		int k=0;
		int l=N,r=-1;
		while(k<N)
		{
			l=min(l,inv[k]);
			r=max(r,inv[k]);
			while(k<N&&l<=inv[k]&&inv[k]<=r)k++;
			//2*k>=r-l+1
			int ok=2*k-(r-l+1);
			if(k==N)ans++;
			else if(ok>=0)
			{
				if(inv[k]<l)
				{
					for(int i=0;i<l-inv[k];i++)
					{
						//0<=j<N-r
						//i+j<=ok <=> j<=ok-i
						ans+=max(min(N-r,ok-i+1),0);
					}
				}
				else
				{
					for(int j=0;j<inv[k]-r;j++)
					{
						//0<=i<=l
						//i+j<=ok <=> i<=ok-j
						ans+=max(min(l+1,ok-j+1),0);
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
}