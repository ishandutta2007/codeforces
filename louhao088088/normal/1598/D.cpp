#include<bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define int long long
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
const int maxn=2e5+100;
int T,n,x[maxn],y[maxn],f[2],p[maxn],s[maxn],s2[maxn];
int C3(int n)
{
	return n*(n-1)*(n-2)/6;
}
signed main()
{
	T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;i++)s[i]=s2[i]=0;
		for(int i=1;i<=n;i++)
			x[i]=read(),y[i]=read(),s[x[i]]++,s2[y[i]]++;
		int ans=C3(n);
		for(int i=1;i<=n;i++)
			ans-=(s[x[i]]-1)*(s2[y[i]]-1);
		printf("%lld\n",ans);
	}
}