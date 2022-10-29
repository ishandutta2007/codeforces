#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 510000;
const int mod  = 998244353;

int pw(int x,int k)
{
	int re=1;
	for(;k;k>>=1,x=1ll*x*x%mod) if(k&1)
		re=1ll*re*x%mod;
	return re;
}
int inv(int x){ return pw(x,mod-2); }

int n;
int a[maxn];
int f[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	
	int Tcase; cin>>Tcase;
	while(Tcase--)
	{
		int l=0,r=0;
		cin>>n;
		for(int i=1;i<=n;i++) 
		{
			cin>>a[i];
			if(a[i]==0) l++;
			else r++;
		}
		
		int k=0;
		for(int i=1;i<=l;i++) if(a[i]==1) k++;
		
		f[0]=0;
		for(int i=1;i<=k;i++)
		{
			int q= 1ll*n*(n-1)/2%mod;
			int p1= 1ll*i*i%mod;
			
			f[i]= (f[i-1]+ 1ll*q*inv(p1)%mod)%mod;
		}
		
		cout<<f[k]<<endl;
	}
	
	
	return 0;
}