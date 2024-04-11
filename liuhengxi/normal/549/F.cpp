#include<cstdio>
#include<algorithm>
#include<vector>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=3e5+5;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
int n,k,a[N],f[N],id[N],sum[N],siz[N];
long long ans;
bool d[N];
vector<int> p[(int)1e6+5];
bool cmp(int u,int v){return a[u]<a[v];}
inline int mod(int x){return (x%k+k)%k;}
inline int mod2(int x){return x>=k?x-k:x;}
int main()
{
	read(n,k);
	F(i,1,n+1)read(a[i]),id[i]=i;
	sort(id+1,id+n+1,cmp);
	F(i,0,n+1)sum[i+1]=(sum[i]+(a[i]%=k))%k;
	F(i,0,n+2)p[sum[i]].emplace_back(i);
	F(i,0,n+2)f[i]=i;
	F(j,1,n+1)
	{
		int u=id[j],v=u+1,pre=f[u-1],nex=f[u+1],l=u-siz[pre],r=v+siz[nex],ms=1,tp=0;
		if(siz[pre]<siz[nex])
		{
			F(i,l,v)
			{
				auto &arr=p[(sum[i]+a[u])%k];
				ans+=(int)(lower_bound(arr.begin(),arr.end(),r+1)-lower_bound(arr.begin(),arr.end(),v));
			}
		}
		else
		{
			F(i,v,r+1)
			{
				auto &arr=p[(sum[i]-a[u]+k)%k];
				ans+=(int)(lower_bound(arr.begin(),arr.end(),v)-lower_bound(arr.begin(),arr.end(),l));
			}
		}
		if(u-l>=ms)ms=u-l,tp=-1;
		if(r-v>=ms)ms=r-v,tp=1;
		if(tp)
		{
			if(~tp)
			{
				F(i,l,v)f[i]=nex;
				siz[nex]+=v-l;
			}
			else
			{
				F(i,u,r)f[i]=pre;
				siz[pre]+=r-u;
			}
		}
		else siz[u]=1;
		--ans;
	}
	printf("%lld\n",ans);
	return 0;
}