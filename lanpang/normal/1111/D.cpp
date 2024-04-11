#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

typedef long long LL;
const int maxn = 1e5+10;
const int inf = 0x3f3f3f3f;
const LL mod = 1e9+7;

LL fac[maxn] , inv[maxn];
LL fast_mod(LL a,LL n,LL Mod)
{
    LL ans=1;
    a%=Mod;
    while(n)
    {
        if(n&1) ans=(ans*a)%Mod;
        a=(a*a)%Mod;
        n>>=1;
    }
    return ans;
}
void init()
{
    fac[0]=1;
    for(int i=1;i<maxn;i++)
        fac[i]=(fac[i-1]*i)%mod;
    inv[maxn-1]=fast_mod(fac[maxn-1],mod-2,mod);
    for(int i=maxn-2;i>=0;i--)
        inv[i]=(inv[i+1]*(i+1))%mod;
}

int n , q;
LL dp[60][maxn] , f[2][maxn] , ori;
char c[maxn];
map<char,int> mp;
map<pair<char,char>,LL> ans;
set<char> st;

LL jisuan(char c1 , char c2)
{
	LL ret = 1;
	int m1 = mp[c1] , m2 = mp[c2];
	for (int i = 0 ; i <= n ; i++)
		f[0][i] = dp[(int)st.size()][i];
	for (int i = 0 ; i <= n ; i++)
	{
		if (i < m1) f[1][i] = f[0][i];
		else f[1][i] = (f[0][i]+mod-f[1][i-m1])%mod;
	}
	if (c1 == c2) return ori*f[1][n/2]%mod;
	else
	{
		for (int i = 0 ; i <= n ; i++)
		{
			if (i < m2) f[0][i] = f[1][i];
			else f[0][i] = (f[1][i]+mod-f[0][i-m2])%mod;
		}
		return ori*f[0][n/2]%mod;
	}
}

int main()
{
	int i , j , x , y;
	init(); 
	cin >> c;
	n = strlen(c);
	for (i = 0 ; i < n ; i++)
	{
		mp[c[i]]++;
		st.insert(c[i]);
	}
	y = 0;
	dp[0][0] = 1;
	ori = fac[n/2]*fac[n/2]%mod*2%mod;
	for (auto i: st)
	{
		x = mp[i];
		ori = ori*inv[x]%mod;
		for (j = 0 ; j <= n ; j++)
			dp[y+1][j] = dp[y][j];
		for (j = 0 ; j+x <= n ; j++)
			dp[y+1][j+x] = (dp[y+1][j+x]+dp[y][j])%mod;
		y++;
	}
	cin >> q;
	for (i = 1 ; i <= q ; i++)
	{
		scanf("%d%d",&x,&y);
		pair<char,char> pcc = make_pair(min(c[x-1],c[y-1]),max(c[x-1],c[y-1]));
		LL ret = ans[pcc];
		if (ret == 0) 
		{
			ret = jisuan(pcc.first,pcc.second);
			ans[pcc] = ret;
		}
		if (ret == -1) printf("0\n");
		else printf("%d\n",ret);
	}
	return 0;
}