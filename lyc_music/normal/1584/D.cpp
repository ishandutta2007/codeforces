//The Hunting Party - Keys To The Kingdom
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e9
#define mod 998244353
#define int ll
//#define N
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n;
int query(int x,int y)
{
	int res=0;
	cout<<"? "<<x<<" "<<y<<endl;
	cin>>res;
	return res;
}
void LYC_music()
{
	cin>>n;
	int l=1,r=n,x=0;
	while (l<=r)
	{
		int mid=l+(r-l)/2;
		if (query(1,mid)==0)
		{
			x=mid;
			l=mid+1;
		} else
		{
			r=mid-1;
		}
	}
//	x++;
	int y=query(x,n)-query(x+1,n);
	int x1=x+y+1;
	int z=query(x1,n)-query(x1+1,n);
	int x2=x1+z;
	cout<<"! "<<x<<" "<<x1<<" "<<x2<<endl;
	
}
signed main()
{
	int T=1;
	cin>>T;
	while (T--)
	{
		LYC_music();
	}
}
/*

*/