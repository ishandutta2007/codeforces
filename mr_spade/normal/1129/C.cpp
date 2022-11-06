#pragma GCC optimize("Ofast","inline")
#include<cstdio>
#include<deque>
#include<unordered_map>
using std::deque;
using std::unordered_map;
typedef unsigned long long ull;
const int mod=1e9+7;
inline int add(int a,int b)
{
	return (a+=b)>=mod?a-mod:a;
}
inline int sub(int a,int b)
{
	return (a-=b)<0?a+mod:a;
}
const int N=3005,M=1e7+5;
const int base=31;
int n,ans;
int dp[N][N];
ull h[N],powb[N];
struct hash_table
{
	int tot;
	ull key[M];
	int key2[M];
	int first[M],next[M];
	inline int h(ull x)
	{
		return (x*48271+98087)%10000000;
	}
	inline void insert(ull k,int k2)
	{
		int c=h(k);
		key[++tot]=k;key2[tot]=k2;
		next[tot]=first[c];first[c]=tot;
	}
	inline int find(ull k)
	{
		int c=first[h(k)];
		for(;c;c=next[c])
			if(key[c]==k)
				return key2[c];
		return -1;
	}
}H;
inline ull hash(int l,int r)
{
	return h[r]-powb[r-l+1]*h[l-1];
}
signed main()
{
	int x;
	register int i,j,k;
//	printf("%llu\n",1ull*base*base*base+1ull*base*base+2ull*base+2ull);
//	printf("%llu\n",1ull*base*base*base+2ull*base*base+1ull*base+2ull);
//	printf("%llu\n",2ull*base*base*base+2ull*base*base+2ull*base+1ull);
//	printf("%llu\n",2ull*base*base*base+2ull*base*base+2ull*base+2ull);
	scanf("%d",&n);
	powb[0]=1;
	for(i=1;i<=n;i++)
		powb[i]=powb[i-1]*base;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		h[i]=h[i-1]*base+x+1;
		dp[i][i-1]=1;
		for(j=1;j<=i;j++)
			if(H.find(hash(j,i))==-1)
			{
				for(k=1;k<=4&&i-k>=j-1;k++)
					if(k<4||(hash(i-k+1,i)!=30816&&hash(i-k+1,i)!=31746&&hash(i-k+1,i)!=61567&&hash(i-k+1,i)!=61568))
						dp[j][i]=add(dp[j][i],dp[j][i-k]);
				ans=add(ans,dp[j][i]);
				H.insert(hash(j,i),dp[j][i]);
			}
			else
				dp[j][i]=H.find(hash(j,i));
		printf("%d\n",ans);
	}
	return 0;
}