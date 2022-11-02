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
#define lowbit (x&-x)
#define int long long
const int maxn=1e5+5,M=34005;
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
int T,n,m,a[maxn],b[maxn],l,r,x,res,y;
void solve()
{
	n=read();
	l=2,r=n;
	while(l<=r)
	{
		int mid=l+r>>1;
		cout<<"? 1"<<" "<<mid<<endl;cout.flush();
		x=read();int t=sqrt(x*2);
		if(x==0)l=mid+1;
		else r=mid-1,res=mid;
	}
	l=res-1;
	cout<<"? "<<l<<" "<<n<<endl;
	cout.flush();
	x=read();
	cout<<"? "<<l+1<<" "<<n<<endl;
	y=read();cout.flush();
	res=x-y+l+1;
	cout<<"? "<<res<<" "<<n<<endl;
	cout.flush();
	x=read();int t=sqrt(x*2);r=res+t;
	cout<<"! "<<l<<" "<<res<<" "<<r<<endl;
	return;
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
    : 2021-11-14 14:06
*********************************************************************/