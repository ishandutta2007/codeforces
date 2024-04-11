//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N 200005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int a[N];
int n;
pa que(int l,int r)
{
	int x=0,y=0;
	cout<<"? "<<l<<" "<<r<<endl;
	cin>>x;
	if (x==-1) exit(3);
	cin>>y;
	return {x,y};
}
void work(int l,int r)
{
	if (l>r) return;
	pa u=que(l,r);
	int y=l+u.se-1,x=r-u.se+1;
	if (x<=y)
	{
		for (int i=x;i<=y;i++) a[i]=u.fi;
		work(l,x-1);
		work(y+1,r);
	} else
	{
		int mid=l+(r-l)/2;
		work(l,mid);
		work(mid+1,r);
	}
}
signed main()
{
	cin>>n;
	work(1,n);
	cout<<"! ";
	for (int i=1;i<=n;i++) cout<<a[i]<<" ";
}
/*

*/