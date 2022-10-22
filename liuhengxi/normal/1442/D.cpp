#include<cstdio>
#include<cstring>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
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
constexpr int N=3005,ST=1e6+5;
int aa[ST],*cur=aa;
int n,k,t[N],*a[N];
long long s[N],f[13][N],ans;
void solve(int dep,int l,int r,int ll,int rr)
{
	int mid=(l+r)>>1;
	long long *ff=f[dep];
	if(dep)memcpy(ff,f[dep-1],sizeof(long long)*(k+1));
	F(i,ll,rr)for(int j=k;j>=t[i];--j)ff[j]=max(ff[j],ff[j-t[i]]+s[i]);
	if(r-l==1)
	{
		long long ss=0;
		F(i,0,min(t[l],k)+1)
		{
			ans=max(ans,ss+ff[k-i]);
			if(i<k)ss+=a[l][i];
		}
		return;
	}
	solve(dep+1,l,mid,mid,r);
	solve(dep+1,mid,r,l,mid);
}
int main()
{
	read(n,k);
	F(i,0,n)
	{
		a[i]=cur;
		cur+=read(t[i]);
		F(j,0,t[i])s[i]+=read(a[i][j]);
	}
	solve(0,0,n,0,0);
	printf("%lld\n",ans);
	return 0;
}