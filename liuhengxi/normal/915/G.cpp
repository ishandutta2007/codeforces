#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e6+5,MOD=1000000007;
template<typename T>T& read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
	return x;
}
int n,k,mu[N],pri[N],cnt,f[N],pown[N],t[2*N],ans;
bool vis[N];
int pow(int aa,int b)
{
	long long a=aa,c=1;
	while(b)
	{
		if(b&1)(c*=a)%=MOD;
		b>>=1;(a*=a)%=MOD;
	}
	return c;
}
int main()
{
	read(n);read(k);
	mu[1]=1;pown[1]=1;
	F(i,2,k+1)
	{
		if(!vis[i])mu[pri[cnt++]=i]=-1,pown[i]=pow(i,n);
		F(j,0,cnt)
		{
			int x=i*pri[j];
			if(x>k)break;
			vis[x]=true;pown[x]=pown[i]*(long long)pown[pri[j]]%MOD;
			if(i%pri[j]==0)break;
			mu[x]=-mu[i];
		}
	}
	F(i,0,k+1)f[i]=pown[i];
	F(i,1,k+1)
	{
		F(j,2,k/i+1)
		{
			(t[i*j]+=f[i]*(long long)(MOD+mu[j])%MOD)%=MOD;
			(t[i*j+j]+=f[i]*(long long)(MOD-mu[j])%MOD)%=MOD;
		}
		(f[i]+=t[i])%=MOD;
		(t[i+1]+=t[i])%=MOD;
	}
	#ifdef LOCAL
	F(i,1,k+1)printf("%d\n",f[i]);
	#endif
	F(i,1,k+1)(ans+=f[i]^i)%=MOD;
	printf("%d\n",ans);
	return 0;
}