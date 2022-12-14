// Lynkcat.
// Problem: A. Product Oriented Recurrence
// Contest: Codeforces - 10.9
// URL: https://codeforces.com/gym/403061/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms

#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e9
#define mod 1000000007
#define mod1 1000000006
#define int ll
// #define N 
using namespace std;
int n,f[5],c;
struct mat
{
    vector<poly>a;
    void resz(int n,int m)
    {
        a=vector<poly>(n,poly(m,0));
    }
};
int quickPower(int x,int y)
{
	int res=1;
	while (y)
	{
		if (y&1) res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
mat mul(mat &x,mat &y)
{
    mat res;
    res.resz(x.a.size(),y.a[0].size());
    for (auto &u:res.a)
        for (auto &v:u) v=0;
    for (int i=0;i<x.a.size();i++)
        for (int j=0;j<y.a[0].size();j++)
            for (int k=0;k<x.a[0].size();k++)
            {
                int v=x.a[i][k]*y.a[k][j]%mod1;
                res.a[i][j]=(res.a[i][j]+v>=mod1)?res.a[i][j]+v-mod1:res.a[i][j]+v;
            }
    return res;
}
void BellaKira()
{
	cin>>n>>f[1]>>f[2]>>f[3]>>c;
	mat now;
	now.resz(9,9);
	n-=3;
	for (int i=3;i<9;i++)
		now.a[i][i-3]=1;
	for (int i=0;i<9;i++)
		now.a[i][6+i%3]=1;
	mat ans;
	ans.resz(1,9);
	ans.a[0][0]=1;
	ans.a[0][4]=1;
	ans.a[0][8]=1;
	int nn=n+3;
	while (n)
	{
		if (n&1) ans=mul(ans,now);
		now=mul(now,now);
		n>>=1;
	}
	f[1]=f[1]*c%mod;
	f[2]=f[2]*c%mod*c%mod;
	f[3]=f[3]*c%mod*c%mod*c%mod;
	int Ans=1;
	for (int i=6;i<9;i++)
	{
		Ans=Ans*quickPower(f[i%3+1],ans.a[0][i])%mod;
	}
	// for (int i=0;i<9;i++)
		// cout<<ans.a[0][i]<<" ";
	// cout<<endl;
	// cout<<f[1]<<" "<<f[2]<<" "<<f[3]<<endl;
	// cout<<"?"<<Ans<<endl;
	cout<<Ans*quickPower(quickPower(c,nn),mod-2)%mod<<'\n';
}
signed main()
{
	IOS;
	cin.tie(0);
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}