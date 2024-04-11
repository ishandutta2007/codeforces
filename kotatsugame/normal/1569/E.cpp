#include<iostream>
#include<vector>
#include<set>
using namespace std;
const int mod=998244353;
int k,A,h;
int pA[20];
set<int>S[6][32];
vector<int>cum[32];
int P[32];
bool fn(int i,int h,int PL,int PR)
{
	if(i==0)
	{
		P[PL]=(1<<k-i-1)+1;
		return true;
	}
	int add=0;
	for(int j=0;j<i;j++)
	{
		add=(add+(long long)pA[(1<<k-j-1)+1]*(i-j-2<0?1:1<<i-j-2))%mod;
	}
	add=(long long)add*(1<<i-1)%mod;
	int sub=((pA[(1<<k-i)+1]-pA[k==i?1:(1<<k-i-1)+1])%mod+mod)%mod;
	for(int l=0;l<1<<i-1;l++)
	{
		for(int ls:S[i-1][l])
		{
			for(int r=0;r<1<<i-1;r++)
			{
				int hl=(h+(long long)sub*(l+1)-ls+mod-add+mod)%mod;
				int hr=(h+(long long)sub*((1<<i-1)+r+1)-ls+mod-add+mod)%mod;
				if(S[i-1][r].find(hl)!=S[i-1][r].end())
				{
					fn(i-1,ls,PL,(PL+PR)/2);
					fn(i-1,hl,(PL+PR)/2,PR);
					P[PL+l]=k==i?1:(1<<k-i-1)+1;
					return true;
				}
				if(S[i-1][r].find(hr)!=S[i-1][r].end())
				{
					fn(i-1,ls,PL,(PL+PR)/2);
					fn(i-1,hr,(PL+PR)/2,PR);
					P[PL+(1<<i-1)+r]=k==i?1:(1<<k-i-1)+1;
					return true;
				}
			}
		}
	}
	return false;
}
main()
{
	cin>>k>>A>>h;
	pA[0]=1;
	for(int i=1;i<20;i++)pA[i]=(long long)pA[i-1]*A%mod;
	S[0][0].insert(pA[(1<<k-1)+1]);
	for(int i=1;i<k;i++)
	{
		int add=0;
		for(int j=0;j<i;j++)
		{
			add=(add+(long long)pA[(1<<k-j-1)+1]*(i-j-2<0?1:1<<i-j-2))%mod;
		}
		add=(long long)add*(1<<i-1)%mod;
		int sub=((pA[(1<<k-i)+1]-pA[k==i?1:(1<<k-i-1)+1])%mod+mod)%mod;
		for(int u=0;u<1<<i;u++)cum[u].clear();
		for(int l=0;l<1<<i-1;l++)
		{
			for(int ls:S[i-1][l])
			{
				for(int r=0;r<1<<i-1;r++)
				{
					for(int rs:S[i-1][r])
					{
						int now=((long long)ls+rs+add)%mod;
						cum[l].push_back(((now-(long long)sub*(l+1))%mod+mod)%mod);
						cum[(1<<i-1)+r].push_back(((now-(long long)sub*((1<<i-1)+r+1))%mod+mod)%mod);
						//S[i][l].insert(((now-(long long)sub*(l+1))%mod+mod)%mod);
						//S[i][(1<<i-1)+r].insert(((now-(long long)sub*((1<<i-1)+r+1))%mod+mod)%mod);
					}
				}
			}
		}
		for(int u=0;u<1<<i;u++)S[i][u]=set<int>(cum[u].begin(),cum[u].end());
	}
	if(fn(k,h,0,1<<k))
	{
		for(int i=0;i<1<<k;i++)
		{
			printf("%d%c",P[i],i+1==(1<<k)?10:32);
		}
	}
	else puts("-1");
}