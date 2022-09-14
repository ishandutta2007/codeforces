#include<iostream>
#include<vector>
using namespace std;
int cnt[2<<17],cnt2[2<<17];
vector<int>add[2<<17],add2[2<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int L,R;
		cin>>L>>R;
		long long d=R-L+1;
		long long ans=d*(d-1)*(d-2)/6;
		{//i|k && j|k
			for(int i=L;i<=R;i++)cnt[i]=0;
			for(int i=L;i<=R;i++)for(int j=i;j<=R;j+=i)cnt[j]++;
			for(int k=L;k<=R;k++)
			{
				long long c=cnt[k]-1;//k
				ans-=c*(c-1)/2;
			}
		}
		for(int i=L;i<=R;i++)
		{
			cnt[i]=0,cnt2[i]=0;
			add[i].clear();
			add2[i].clear();
		}
		for(int j=L;j<=R;j++)
		{
			for(int nk=j;nk<=2*R;nk+=j)if(nk%2==0)
			{
				int k=nk/2;
				if(j<k)
				{
					if(k%j==0)ans-=cnt[k];
					else
					{
						ans-=cnt2[k];
						if(k-j<j)cnt[k]++;
						else add[k-j].push_back(k);
					}
					if(k-j<j)cnt2[k]++;
					else add2[k-j].push_back(k);
				}
			}
			for(int k:add[j])cnt[k]++;
			for(int k:add2[j])cnt2[k]++;
		}
		cout<<ans<<"\n";
	}
}