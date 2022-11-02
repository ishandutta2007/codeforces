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
const int maxn=2e5+5,M=34005;
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
int T,n,x,a[maxn],num;
map<int,int>s;
void solve()
{
	n=read();x=read();s.clear();num=n;
	for(int i=1;i<=n;i++)a[i]=read(),s[a[i]]++;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		if(s[a[i]]&&s[a[i]*x])num-=2,s[a[i]]--,s[a[i]*x]--;
	printf("%lld\n",num);
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


/*********************************************************************
    :louhao088
    : 2022-02-23 18:10
*********************************************************************/