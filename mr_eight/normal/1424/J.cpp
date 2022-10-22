#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#define int long long

using namespace std;

int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}

const int N=1e6+5;
int t,n,prime[N],vis[N],tot;

inline int getsum(int x);

signed main()
{
	for(int i=2;i<=1000000;++i)
	{
		if(!vis[i])
		{
			vis[i]=1;
			prime[++tot]=i;
		}
		for(int j=1;j<=tot&&prime[j]*i<=1000000;++j)
		{
			vis[i*prime[j]]=1;
            if(i%prime[j]==0) break;
		}
	}
	t=read();
	while(t--)
	{
		n=read();
		printf("%lld ",getsum(n)-getsum((int)sqrt(n))+1);
					
	}
	return 0;
}

inline int getsum(int x)
{
	return upper_bound(prime+1,prime+1+tot,x)-prime-1;
}