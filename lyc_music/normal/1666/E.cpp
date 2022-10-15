//~~
#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N 100005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int r,n,a[N];
int g[N];
int len;
int ansl,ansr;
int chk(int x)
{
	int lstr=0,nowr=0;
	for (int i=1;i<=n;i++)
	{
		nowr+=x;
		if (nowr>a[i+1]) return 0;
		nowr=max(nowr,a[i]);
	}
	return 1;
}
int chk1(int x)
{
	int lstr=0,nowr=0;
	for (int i=1;i<=n;i++)
	{
		nowr+=x;
		if (nowr<a[i]) return 0;
		if (i!=n)
			nowr=min(nowr,a[i+1]);
	}
	if (nowr<len) return 0;
	return 1;
}
int chk(int x,int l,int r,int L,int R)
{
	int lstr=0,nowr=0;
	for (int i=l;i<=r;i++)
	{
		nowr+=x;
		if (i==r)
		{
			if (nowr>R-L) return 0;
		}
		else
		{
			if (nowr>a[i+1]-L) return 0;
		}
		nowr=max(nowr,a[i]-L);
	}
	return 1;
}
int chk1(int x,int l,int r,int L,int R)
{
	int lstr=0,nowr=0;
	for (int i=l;i<=r;i++)
	{
		nowr+=x;
		if (nowr<a[i]-L) return 0;
		if (i!=r)
			nowr=min(nowr,a[i+1]-L);
	}
	if (nowr<R-L) return 0;
	return 1;
}
void solve(int l,int r,int L,int R)
{
	if (l==r)
	{
		cout<<L<<" "<<R<<endl;
		return;
	}
	if (l+1==r)
	{
		int pl=a[l],pr=a[l+1];
		while (pl<=pr)
		{
			int mid=pl+(pr-pl)/2;
			// cout<<"!!!"<<mid<<endl;
			if (mid-L<ansl||R-mid>ansr)
			{
				pl=mid+1;
			} else
			if (mid-L>ansr||R-mid<ansl)
			{
				pr=mid-1;
			}
			else
			{
				cout<<L<<" "<<mid<<endl;
				cout<<mid<<" "<<R<<endl;
				return;
			}
		}
		return;
	}
	for (int i=l;i<=r;i++) g[i-l+1]=a[i];
	g[0]=L,g[r-l+1+1]=R;
	int mid=(r+l)/2-l+1;
	int pl=g[mid-1],pr=g[mid];
	// cout<<"????"<<pl<<" "<<pr<<endl;
	int spl=0,spr=0;
	while (pl<=pr)
	{
		int midd=pl+(pr-pl)/2;
		// cout<<"!!"<<midd<<" "<<chk(ansl,l,l+mid-1-1,L,midd)<<" "<<chk1(ansr,l,l+mid-1,L,midd)<<endl;
		if (!chk(ansl,l,l+mid-1-1,L,midd))
		{
			pl=midd+1;
		} 
		else
		{
			if (!chk1(ansr,l,l+mid-1-1,L,midd))
			{
				pr=midd-1;
			} 
			else
			{
				// cout<<"!"<<midd<<endl;
				if (midd+ansr<g[mid])
				{
					pl=midd+1;
				}
				else
				if (midd+ansl>g[mid+1])
				{
					pr=midd-1;
				} else
				{
					int ppl=midd+ansl,ppr=midd+ansr;
					ppl=max(ppl,g[mid]);
					ppr=min(ppr,g[mid+1]);
					// cout<<","<<ppl<<" "<<ppr<<endl;
					if (!chk(ansl,l+mid,r,ppl,R))
					{
						pr=midd-1;
						continue;
					}
					if (!chk1(ansr,l+mid,r,ppr,R))
					{
						pl=midd+1;
						continue;
					}
					while (ppl<=ppr)
					{
						int mm=ppl+(ppr-ppl)/2;
						if (!chk(ansl,l+mid,r,mm,R))
						{
							ppr=mm-1;
						} else
						if (!chk1(ansr,l+mid,r,mm,R))
						{
							ppl=mm+1;
						}
						else
						{
							spl=midd,spr=mm;
							break;
						}
					}
					break;
				}
			}		
		}
	}
	assert(spl!=0);
	assert(spl<=a[l+mid-1]&&a[l+mid-1]<=spr);
	solve(l,l+mid-1-1,L,spl);
	cout<<spl<<" "<<spr<<endl;
	solve(l+mid,r,spr,R);
}
void BellaKira()
{
	int l=1,r=0;
	r=read(),n=read();
	len=r;
	if (n==1) return cout<<0<<" "<<len<<endl,void();
	for (int i=1;i<=n;i++) a[i]=read();
	cout<<endl;
	a[n+1]=len;
	
	ansl=0,ansr=0;
	while (l<=r)
	{
		int mid=l+(r-l)/2;
		if (chk(mid))
		{
			ansl=mid;
			l=mid+1;
		} else r=mid-1;
	}
	l=1,r=len;
	while (l<=r)
	{
		int mid=l+(r-l)/2;
		if (chk1(mid))
		{
			ansr=mid;
			r=mid-1;
		} else 
			l=mid+1;
	}
	// cout<<ansl<<" "<<ansr<<endl;
	solve(1,n,0,len);
}
signed main()
{
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}
/*

*/