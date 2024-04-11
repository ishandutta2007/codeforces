#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
#define int long long
const int maxn=3e5+5;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
void print(int x)
{
    if(x<0) putchar('-'),x=-x;
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
int T,n,a[maxn],ans,b[maxn],tot=0;
void solve()
{
	n=read();
	int F=0;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		if(i>tot)continue;
		if(a[i]%b[i]==0)F=1;
	}
	if(F)puts("NO");
	else puts("YES");
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	b[1]=2;
	for(int i=2;i<=1e5;i++)
	{
		b[i]=(i+1)*b[i-1]/__gcd(i+1,b[i-1]);tot=i;
		if(b[i]>1e9)break;
	}
	//cout<<tot<<endl;
	T=read();
	while(T--)solve(); 
 	return 0;
}