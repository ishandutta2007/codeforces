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
//#define int ll
#define N 5000005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int T,n,m,a[N],l[N],r[N],sum[N],tag[N],p,ans;
string st,st1;
inline void pushdown(int k,int l,int r)
{
	if (!tag[k]) return;
//	if (k<<1|1==11) cout<<"???"<<" "<<k<<endl;
	sum[k<<1]=tag[k]%2*(l+(r-l)/2-l+1);
	sum[k<<1|1]=tag[k]%2*(r-(l+(r-l)/2));
	tag[k<<1]=tag[k];
	tag[k<<1|1]=tag[k];
	tag[k]=0;
}
inline void pushup(int k)
{
	sum[k]=sum[k<<1]+sum[k<<1|1];
}
inline void build(int k,int l,int r)
{
	if (l==r) sum[k]=a[l],tag[k]=0;
//	cout<<l<<","<<r<<" "<<sum[k]<<" "<<k<<endl;
	else 
	{
		build(k<<1,l,l+(r-l)/2);
		build(k<<1|1,l+(r-l)/2+1,r);
		tag[k]=0;
		sum[k]=0;
		pushup(k);
	}
}
inline void update(int k,int l,int r,int l1,int r1,int val)
{
//	if (l==5&&r==5) cout<<l<<" "<<r<<","<<sum[k]<<" "<<k<<endl;
	if (l>=l1&&r<=r1)
	{
//		cout<<"/"<<l<<" "<<r<<endl;
		sum[k]=val%2*(r-l+1);
		tag[k]=val;
		return;
	}
	pushdown(k,l,r);
	if (l1<=l+(r-l)/2) update(k<<1,l,l+(r-l)/2,l1,r1,val);
	if (r1>l+(r-l)/2) update(k<<1|1,l+(r-l)/2+1,r,l1,r1,val);
	pushup(k);
}
inline int query(int k,int l,int r,int l1,int r1)
{
	if (l>=l1&&r<=r1) {return sum[k];}
	int res=0;
	pushdown(k,l,r);
	if (l1<=l+(r-l)/2) res+=query(k<<1,l,l+(r-l)/2,l1,r1);
	if (r1>l+(r-l)/2) res+=query(k<<1|1,l+(r-l)/2+1,r,l1,r1);
	pushup(k);
	return res;
}
signed main()
{
//	T=read();
	cin>>T;
	while (T--)
	{
		cin>>n>>m;
		cin>>st>>st1;ans=0;
		for (int i=1;i<=st1.length();i++)
		{
			a[i]=st1[i-1]-'0';
		}
		build(1,1,n);
//		cout<<"?"<<query(1,1,n,5,5)<<endl;
		for (int i=1;i<=m;i++)
		{
			l[i]=read(),r[i]=read();
		}
		for (int i=m;i>=1;i--)
		{
			p=query(1,1,n,l[i],r[i]);
			if (p>(r[i]-l[i]+1)*1.0/2.0)
			{
				update(1,1,n,l[i],r[i],1);
			} else 
			if (p<(r[i]-l[i]+1)*1.0/2.0)
			{
				update(1,1,n,l[i],r[i],2);
			} else 
			ans=1;
		}
		if (ans) 
		{
			puts("NO");continue;
		}
		for (int i=1;i<=n;i++)
			if (query(1,1,n,i,i)!=(st[i-1]-'0')) ans=1;
//			cout<<query(1,1,n,i,i)<<" "<<i<<endl;
		if (ans) 
		{
			puts("NO");continue;
		}
		puts("YES");
	}
}
/*
124124
7 9
0101111
0101110
5 7
4 6
5 6
1 1
2 2
5 6
2 2
2 2
6 6
8 9
00111010
00111000
4 5
5 5
5 5
8 8
6 6
2 2
5 7
3 3
3 6
5 8
00001
00001
3 4
5 5
2 4
5 5
3 3
3 4
1 3
4 4
5 9
11000
11001
5 5
5 5
5 5
1 2
5 5
4 5
3 4
4 5
5 5
9 6
100111110
100111100
8 8
7 8
8 8
7 8
4 8
7 7
5 8
11011
11001
4 4
2 2
4 5
5 5
3 3
3 3
4 5
3 4
9 6
111110101
111110101
3 5
5 5
8 8
5 5
6 6
3 4
*/