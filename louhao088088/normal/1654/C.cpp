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
#define lowbit (x&-x)
#define int long long
const int maxn=2e5+5,M=34005;
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
int n,m,T,s[255],id;
map<int,int>f;
int a[maxn],s1,s2,x,y,sum;
void solve()
{
	n=read();sum=0;f.clear();
	for(int i=1;i<=n;i++)a[i]=read(),sum+=a[i],f[a[i]]++;
	s1=1,s2=0;
	while(sum!=1)
	{
		x=min(s1,f[sum]);s1-=x,f[sum]-=x;
		y=min(s2,f[sum+1]);s2-=y,f[sum+1]-=y;
		if(sum&1)s2=s2*2+s1;
		else s1=s1*2+s2;
		sum/=2;
	}
	int tmp=min(s2,f[2]);s2-=tmp;f[2]-=tmp;s1+=2*s2;
	if(s1==f[1])puts("YES");
	else puts("NO");
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	T=read();
	while(T--)
	{
		solve();
	}
 	return 0;
}