#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5;
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
int n,k;
#ifdef LOCAL
int ans;long long a[N],b[N];
#endif
long long query(int x)
{
	long long res;
	printf("? %d\n",x+1);
	#ifdef LOCAL
	printf("%lld\n",res=a[x]);
	F(i,0,n)b[i]=0;
	if(0==ans)b[1]+=a[0];else b[n-1]+=a[0]>>1,b[1]+=a[0]-(a[0]>>1);
	F(i,1,n-1)if(i==ans)b[i+1]+=a[i];else b[i-1]+=a[i]>>1,b[i+1]+=a[i]-(a[i]>>1);
	if(n-1==ans)b[0]+=a[n-1];else b[n-2]+=a[n-1]>>1,b[0]+=a[n-1]-(a[n-1]>>1);
	F(i,0,n)a[i]=b[i];
	#else
	fflush(stdout);
	read(res);
	#endif
	return res;
}
int main()
{
	read(n,k);
	#ifdef LOCAL
	--read(ans);
	F(i,0,n)a[i]=k;
	#endif
	int l=0,r=0;
	query(0);
	for(int i=0,j=1,lim=(n>>1)-1;;i+=j=min(lim,j+1))
	{
		if(i>n)i=n-1;
		if(query(i)>k)
		{
			l=i-j;
			r=i;
			break;
		}
	}
	while(r-l>1)
	{
		int mid=(l+r)>>1;
		if(query(mid)<=k)l=mid;
		else r=mid;
	}
	printf("! %d\n",(l+n)%n+1);
	#ifdef LOCAL
	puts((l+n)%n==ans?"Correct":"Incorrect");
	#endif
	return 0;
}