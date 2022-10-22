#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1005,MOD=1000000007;
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
void reduce(int &x){(x>=MOD)&&(x-=MOD);}
int n,m,f[N],C[N][N],ans=1;
long long mask[N];
char s[N];
int main()
{
	read(n,m);
	F(i,0,m)
	{
		scanf("%s",s);
		F(j,0,n)mask[j]|=(long long)(s[j]^'0')<<i;
	}
	F(i,0,n+1)C[i][0]=1;
	F(i,1,n+1)F(j,1,i+1)reduce(C[i][j]=C[i-1][j]+C[i-1][j-1]);
	F(i,f[0]=1,n+1)F(j,1,i+1)f[i]=int((f[i]+(long long)C[i-1][j-1]*f[i-j])%MOD);;
	sort(mask,mask+n);
	mask[n]=-1;
	for(int i=0,j=0;i<n;i=j)
	{
		while(mask[i]==mask[j])++j;
		ans=int((long long)ans*f[j-i]%MOD);
	}
	printf("%d\n",ans);
	return 0;
}