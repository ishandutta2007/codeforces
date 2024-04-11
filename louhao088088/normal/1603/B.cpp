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
int T,n,a[maxn],ans,b[maxn],tot=0,m;
void solve()
{
	n=read();m=read();
	int y=m/n;
	int x=n*y;
	if(n>m)
	{
		cout<<n+m<<endl;
	}
	else
	{
		cout<<(x+m)/2<<endl;
	}
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout)
	T=read();
	while(T--)solve(); 
 	return 0;
}