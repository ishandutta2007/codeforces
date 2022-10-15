//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define re register
#define inf 1e18
#define mod 998244353
#define int ll
//#define N
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int a[5];
int x,y,X,Y;
int check(int x)
{
	cout<<"? 1 "<<x<<endl;
	int res;
	cin>>res;
	return (res+(x-1)==a[1]);
}
signed main()
{
	cout<<"? 1 1"<<endl;
	cin>>a[1];
	cout<<"? 1 1000000000"<<endl;
	cin>>a[2];
	cout<<"? 1000000000 1"<<endl;
	cin>>a[3];
	int l=2,r=min(1000000000ll,a[1]+1);
	while (l<=r)
	{
		int mid=l+(r-l)/2;
		if (check(mid))
		{
			y=mid;l=mid+1;
		} else 
			r=mid-1;
	}
	x=a[1]-y+2;
	X=1e9-(a[3]-y)-1;
	Y=1e9-(a[2]-x)-1;
	cout<<"! "<<x<<" "<<y<<" "<<X<<" "<<Y<<endl; 
	
}
/*

*/