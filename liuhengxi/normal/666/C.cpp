#include<cstdio>
#include<cstring>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5,L=350,MOD=1000000007;
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
int fac[N],invfac[N],p25[N];
int pow(int aa,int b)
{
	long long a=aa,c=1;
	for(;b;b>>=1,(a*=a)%=MOD)if(b&1)(c*=a)%=MOD;
	return (int)c;
}
int C(int n,int m){return (int)((long long)fac[n]*invfac[m]%MOD*invfac[n-m]%MOD);}
void calc(int x,int *ans)
{
	ans[0]=0;
	F(i,1,N)
	{
		ans[i]=(int)(ans[i-1]*26ll%MOD);
		if(i>=x)ans[i]=(int)((ans[i]+C(i-1,x-1)*(long long)p25[i-x])%MOD);
	}
}
int m,ans[L][N],tmp[N],k,*cur;
char str[N];
int main()
{
	F(i,p25[0]=1,N)p25[i]=(int)(p25[i-1]*25ll%MOD);
	F(i,fac[0]=1,N)fac[i]=(int)((long long)fac[i-1]*i%MOD);
	invfac[N-1]=pow(fac[N-1],MOD-2);
	for(int i=N;--i;)invfac[i-1]=(int)((long long)invfac[i]*i%MOD);
	F(i,1,L)calc(i,ans[i]);
	read(m);
	scanf("%s",str);
	k=(int)strlen(str);
	if(k<L)cur=ans[k];else calc(k,cur=tmp);
	while(m--)
	{
		int op;read(op);
		if(op==1)
		{
			scanf("%s",str);
			k=(int)strlen(str);
			if(k<L)cur=ans[k];else calc(k,cur=tmp);
		}
		if(op==2)
		{
			int n;read(n);
			printf("%d\n",cur[n]);
		}
	}
	return 0;
}