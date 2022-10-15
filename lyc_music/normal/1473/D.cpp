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
//#define N
using namespace std;
#define SIZE 1000010
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
int n,m,x,y;
int q,a[SIZE],s[SIZE],l,r,T,smin[SIZE],smax[SIZE];
string st;
struct SegmentTree{
    int sum,lmax,rmax,dat,lmin,rmin;
}tr[SIZE<<2];

inline void Update(int p){
    tr[p].sum=tr[p<<1].sum+tr[p<<1|1].sum;
    tr[p].lmax=max(tr[p<<1].lmax,tr[p<<1].sum+tr[p<<1|1].lmax);
    tr[p].rmax=max(tr[p<<1|1].rmax,tr[p<<1|1].sum+tr[p<<1].rmax);
    tr[p].lmin=min(tr[p<<1].lmin,tr[p<<1].sum+tr[p<<1|1].lmin);
    tr[p].rmin=min(tr[p<<1|1].rmin,tr[p<<1|1].sum+tr[p<<1].rmin);
}
inline void Build(int p,int l,int r){
    if(l==r){tr[p].dat=tr[p].sum=tr[p].lmax=tr[p].rmax=tr[p].lmin=tr[p].rmin=a[l]; 
//	cout<<p<<" "<<l<<" "<<r<<" "<<tr[p].lmax<<" "<<tr[p].lmin<<endl;
	return;}
    int mid=(l+r)>>1;
    Build(lson); Build(rson);
    Update(p);
}
inline SegmentTree Query(int p,int l,int r,int ql,int qr){
    if(ql<=l&&qr>=r) return tr[p];
    int mid=(l+r)>>1;
    if(ql>mid) return Query(rson,ql,qr);
    if(qr<=mid) return Query(lson,ql,qr);
    else{
        SegmentTree ans,a,b;
        a=Query(lson,ql,qr); b=Query(rson,ql,qr);
        ans.sum=a.sum+b.sum;
        ans.lmax=max(a.lmax,a.sum+b.lmax);
        ans.rmax=max(b.rmax,b.sum+a.rmax);
        ans.lmin=min(a.lmin,a.sum+b.lmin);
        return ans;
    }
}
inline SegmentTree Query1(int p,int l,int r,int ql,int qr){
    if(ql<=l&&qr>=r) return tr[p];
    int mid=(l+r)>>1;
    if(ql>mid) return Query(rson,ql,qr);
    if(qr<=mid) return Query(lson,ql,qr);
    else{
        SegmentTree ans,a,b;
        a=Query(lson,ql,qr); b=Query(rson,ql,qr);
        ans.sum=a.sum+b.sum;
        ans.dat=min(a.dat,a.rmin+b.lmin),ans.dat=min(ans.dat,b.dat);
        ans.lmin=min(a.lmin,a.sum+b.lmin);
        ans.rmin=min(b.rmin,b.sum+a.rmin);
        return ans;
    }
}

inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
signed main()
{
	cin>>T;
	while (T--)
	{
		cin>>n>>q;
		cin>>st;
		for (int i=1;i<=n+3;i++) a[i]=0;
		s[0]=0;
		smin[0]=0;
		smax[0]=0;
		for (int i=0;i<st.length();i++)
		{
			if (st[i]=='+') a[i+1]=1; else a[i+1]=-1;
			s[i+1]=s[i]+a[i+1];
			smin[i+1]=min(smin[i],s[i+1]);
			smax[i+1]=max(smax[i],s[i+1]);
		}
		Build(1,1,n+3);
		for (int i=1;i<=q;i++)
		{
			cin>>l>>r;
//			r--;
			SegmentTree nmsl=Query(1,1,n+3,r+1,n+3);
//			cout<<nmsl.lmax<<" "<<nmsl.lmin<<" "<<smax[l-1]<<" "<<smin[l-1]<<" "<<l<<endl;
			cout<<max(smax[l-1],nmsl.lmax+s[l-1])-min(smin[l-1],nmsl.lmin+s[l-1])+1<<endl;
		}
	}
			
		
}
/*

*/