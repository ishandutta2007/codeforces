#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

const int maxn = 110000;
const int maxk = 110;
const int Mod = 1000000007;

int pw(ll x,int k)
{
    int re=1ll;
    for(;k;k>>=1,x=(ll)x*x%Mod) if(k&1)
        re=(ll)re*x%Mod;
    return re;
}
int s[maxn],inv[maxn];
void pre()
{
    s[0]=1ll; for(int i=1;i<maxn;i++) s[i]=(ll)s[i-1]*(ll)i%Mod;
    inv[maxn-1]=pw(s[maxn-1],Mod-2);
    for(int i=maxn-2;i>=0;i--) inv[i]=(ll)inv[i+1]*(i+1)%Mod;
}
int C(const int n,const int m){ return (ll)s[n]*inv[m]%Mod*inv[n-m]%Mod; }

int n,m;
int a[maxn];
int f[maxn][maxk];
vector<int>p[maxn];
struct node{int i,k;};
vector<node>P[maxn];

int main()
{
    pre();
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
    {
		int l,r,k; scanf("%d%d%d",&l,&r,&k);
		p[l].push_back(k); P[r].push_back((node){l,k});
    }
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<p[i].size();j++)
		{
			int x=p[i][j];
			f[i][x]++;
		}
		for(int j=100;j>=0;j--)
			f[i][j]=((ll)f[i][j]+f[i-1][j]+f[i][j+1])%Mod;
		a[i]=((ll)a[i]+f[i][0])%Mod;
		for(int j=0;j<P[i].size();j++) 
		{
			const node now=P[i][j];
			for(int l=0;l<=now.k;l++) f[i][l]=(f[i][l]-C(i-now.i+now.k-l,now.k-l))%Mod;
		}
	}
    for(int i=1;i<=n;i++) printf("%d ",((ll)a[i]+Mod)%Mod);
    
    return 0;
}