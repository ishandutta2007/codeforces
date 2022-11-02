#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid (l+r>>1)
#define lowbit(x) (x&-x)
#define int long long
#define get(x) __builtin_popcount(x)
const int maxn=3e6+5,M=34005;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
inline void print(int x)
{
    static int a[55];int top=0;
    if(x<0) putchar('-'),x=-x;
    do{a[top++]=x%10,x/=10;}while(x);
    while(top) putchar(a[--top]+48);
}
int n,m,a[maxn],b[maxn],x,y;
char g[maxn];
void fwt(int *a,int f){
	for(int k=1;k<n;k=k*2)
		for(int len=k*2,i=0;i<n;i+=len)
			for(int j=0;j<k;j++)
				if(f)a[i+j+k]=(a[i+j]+a[i+j+k]);
				else a[i+j+k]=(a[i+j+k]-a[i+j]);
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();n=(1<<n);scanf("%s",g);
	for(int i=0;i<n;i++)a[i]=g[i]-'0',a[i]=a[i]<<(get(i)*2);scanf("%s",g);
	for(int i=0;i<n;i++)b[i]=g[i]-'0',b[i]=b[i]<<(get(i)*2);
	fwt(a,1),fwt(b,1);for(int i=0;i<n;i++)a[i]=a[i]*b[i];
	fwt(a,0);for(int i=0;i<n;i++)printf("%lld",(a[i]>>(get(i)*2))&3);
 	return 0;
}


/*********************************************************************
    :louhao088
    : 2022-04-19 18:11
*********************************************************************/