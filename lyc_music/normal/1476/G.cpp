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
#define N 200005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int lim,Ans[N],sum,n,m,opt,l,r,x,T_l,L,R,a[N],cnt[N],ccnt[N],From[N],Q_cnt,T_cnt;
pa G[N];
int B=2000;
struct qr
{
	int l,r,k,t,id;
}Q[N];
struct 
{
	int a,b;
}T[N];
bool Cmp(qr x,qr y)
{
	return (From[x.l]^From[y.l])?From[x.l]<From[y.l]:((From[x.r]^From[y.r])?From[x.r]<From[y.r]:x.t<y.t);
}
struct
{
	int l[N],r[N],bg=100000+1;
	void init()
	{
		r[0]=1e5+1;
		l[bg]=0;
	}
	void erase(int x)
	{
		l[r[x]]=l[x];
		r[l[x]]=r[x];
	}
	void insert(int x)
	{
		l[x]=0,r[x]=r[0];
		r[0]=x;
		l[r[x]]=x;
	}
}Lis;
void del(int x)
{
	ccnt[cnt[a[x]]]--;
	if (!ccnt[cnt[a[x]]])
		Lis.erase(cnt[a[x]]);
	
	cnt[a[x]]--;
	if (cnt[a[x]])
	{
		if (!ccnt[cnt[a[x]]])
			Lis.insert(cnt[a[x]]);
		ccnt[cnt[a[x]]]++;
	}
	
}
void ins(int x)
{
	if (cnt[a[x]])
	{
	
		ccnt[cnt[a[x]]]--;
		if (!ccnt[cnt[a[x]]]) 
			Lis.erase(cnt[a[x]]);
	
	}
	
	cnt[a[x]]++;
	
	if (!ccnt[cnt[a[x]]])
			Lis.insert(cnt[a[x]]);
		ccnt[cnt[a[x]]]++;
	
}
void work(int x)
{
	if (l<=T[x].a&&T[x].a<=r) del(T[x].a);
	swap(a[T[x].a],T[x].b);
	
	if (l<=T[x].a&&T[x].a<=r) ins(T[x].a);
}
signed main()
{
	n=read(),m=read();Lis.init();
	memset(Ans,0x3f,sizeof(Ans));
	for (int i=1;i<=n;i++) From[i]=(i-1)/B+1,a[i]=read();
	for (int i=1;i<=m;i++)
	{
		opt=read();
		if (opt==1)
		{
			l=read(),r=read(),x=read();
			Q[++Q_cnt]={l,r,x,T_cnt,Q_cnt};
		}else
		{
			l=read(),x=read();
			T[++T_cnt]={l,x};
		}
	}
	sort(Q+1,Q+Q_cnt+1,Cmp);
	T_l=0;l=1,r=0;
	for (int i=1;i<=Q_cnt;i++)
	{
		while (T_l<Q[i].t)
		{
			work(++T_l);
		}
		while (T_l>Q[i].t)
		{
			work(T_l--);
		}
		
		while (l>Q[i].l)
		{
			ins(--l);
		}
		while (l<Q[i].l)
		{
			del(l++);
		}
		while (r<Q[i].r)
		{
			ins(++r);
		}
		while (r>Q[i].r)
		{
			del(r--);
		}
		int now=0,pp=0;
		while (Lis.r[now]!=1e5+1)
		{
			now=Lis.r[now];
			G[pp++]={now,ccnt[now]};
		}
		sort(G,G+pp);
		L=0,R=-1,sum=0;
		while (R<pp)
		{
			if (sum<Q[i].k)
			{
				R++;if (R<pp) sum+=G[R].se;
			}
			else
			{
				Ans[Q[i].id]=min(Ans[Q[i].id],G[R].fi-G[L].fi);
				sum-=G[L].se;
				L++;
			}
		}
	}
	for (int i=1;i<=Q_cnt;i++)	
		if (Ans[i]==0x3f3f3f3f) puts("-1");
		else writeln(Ans[i]);
}
/*

*/