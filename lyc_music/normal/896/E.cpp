//QwQcOrZ yyds!!!
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
#define ll long long
#define F(i,a,b) for (int i=(a);i<=(b);i++)
#define R(i,a,b) for (int i=(a);i<(b);i++)
#define D(i,a,b) for (int i=(a);i>=(b);i--)
#define go(i,x) for (int i=head[x];i;i=e[i].nx)
#define mp make_pair
#define pb push_back
#define pa pair < int,int >
#define fi first
#define se second
#define re register
#define be begin()
#define en end()
#define sqr(x) ((x)*(x))
#define ret return puts("-1"),0;
#define put putchar('\n')
#define inf 1000000005
#define mod 998244353
#define Endl endl
//#define int ll
#define N 1000005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int ANS[N],a[N],From[N],P[N],sum[N],tag,mx,L,R,val[N],f[N],n,m,B;
struct
{
	int id,l,r,x;
}q[N];
int gf(int x)
{
	if (x==f[x]) return x;
	return f[x]=gf(f[x]);
}
void merge(int x,int y)
{
	if (!P[y]) {P[y]=P[x],val[P[y]]=y;}
	else
	{
		f[P[x]]=P[y];
	}
	sum[y]+=sum[x];
	P[x]=0,sum[x]=0;
}
signed main()
{
	n=read();m=read();
	B=sqrt(n);
	for (int i=1;i<=n;i++) a[i]=read(),From[i]=(i-1)/B+1;
	for (int i=1;i<=m;i++)
		q[i]={read(),read(),read(),read()};
	for (int i=1;i<=From[n];i++)
	{
		memset(f,0,sizeof(f));
		memset(val,0,sizeof(val));
		memset(sum,0,sizeof(val));
		memset(P,0,sizeof(P));
		L=(i-1)*B+1;R=min(i*B,n);
		tag=0;mx=0;
		for (int j=L;j<=R;j++)
			{
				if (!P[a[j]]) f[j]=j,val[j]=a[j],P[a[j]]=j;
				else f[j]=P[a[j]];
				sum[a[j]]++;
				mx=max(mx,a[j]);
			}
		for (int j=1;j<=m;j++)
		{
			if (q[j].id==1)
			{
				if (q[j].r<L||q[j].l>R) continue;
				if (q[j].l<=L&&q[j].r>=R)
				{
					if (mx-tag>=q[j].x*2) 
					{
						for (int k=tag+1;k<=tag+q[j].x;k++)
							if (P[k])
							{
								merge(k,k+q[j].x);
							}
						tag+=q[j].x;
					} else
					{
						for (int k=mx;k>tag+q[j].x;k--)
							if (P[k])
							{
								merge(k,k-q[j].x);
							}
						if (tag+q[j].x<mx) mx=tag+q[j].x;
					}
				} else 
				{
					for (int k=L;k<=R;k++)
					{
						a[k]=val[gf(k)];
						P[a[k]]=sum[a[k]]=0;
						a[k]-=tag;
					}
					for (int k=L;k<=R;k++) val[k]=0;
					tag=0,mx=0;
					for (int k=max(L,q[j].l);k<=min(R,q[j].r);k++)
						if (a[k]>q[j].x) a[k]-=q[j].x;
					for (int k=L;k<=R;k++)
					{
						if (!P[a[k]])
						{
							P[a[k]]=k;
							f[k]=k;
							val[k]=a[k];
						} else f[k]=P[a[k]];
						sum[a[k]]++;
						mx=max(mx,a[k]);
					}
				}	
			} else
			{
				if (q[j].x+tag>5e5) continue; 
				if (q[j].l<=L&&R<=q[j].r) 
				{
					ANS[j]+=sum[q[j].x+tag];
				}
				else
				{
					int ans=0;
					for (int k=max(L,q[j].l);k<=min(R,q[j].r);k++)
						if (val[gf(k)]-tag==q[j].x) ans++;
						ANS[j]+=ans;
				}
			}
		}
	}
	for (int i=1;i<=m;i++) 
		if (q[i].id==2) writeln(ANS[i]);
			
			
}
/*
8 8
75 85 88 100 105 120 122 128
1 1 8 70
1 3 8 3
1 2 4 10
1 2 7 27
1 3 7 12
1 1 7 4
1 4 8 5
2 1 8 1
*/