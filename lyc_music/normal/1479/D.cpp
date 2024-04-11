//QwQcOrZ yyds!!!
#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize(2)
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
#define N 1000005
#define B 800
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int dep[N],ST[N][25],vis[N],l,r,m,ol[N],ru[N],chu[N],cnt1,b[N],a[N],x,y,A[N],Ans[N],From[N],lenth,cnt,head[N],n,t1,ans,Cnt[N];
struct 
{
	int bl[N],G[B];
	inline void erase(int x)
	{
		bl[x]=0;
		G[(x-1)/B+1]--;
	}
	inline void insert(int x)
	{
		bl[x]=1;
		G[(x-1)/B+1]++;
	}
	inline int query(int l,int r)
	{
		if ((l-1)/B+1==(r-1)/B+1)
		{
			for (int i=l;i<=r;i++) 
			{
				if (bl[i])
				{
					return i;
				}
			}
			return -1;
		}
		else
		{
			for (int i=l;i<=((l-1)/B+1)*B;i++)
				if (bl[i]) return i;
			for (int i=((l-1)/B+1)+1;i<=(r-1)/B+1-1;i++)
				if (G[i])
				{
					for (int j=(i-1)*B+1;j<=i*B;j++)
						if (bl[j]) return j;
				}
			for (int i=((r-1)/B+1-1)*B+1;i<=r;i++)
				if (bl[i]) return i;
			return -1;
		}
	}
}Se[2];
				
struct
{
	int to,nx;
}e[N<<1];
inline void ad(int x,int y)
{
	e[++cnt].to=y;
	e[cnt].nx=head[x];
	head[x]=cnt;
}
struct node
{
	int l,r,id,bl,lca,l1,r1;
}q[N];
bool Cmp(node x,node y){return (From[x.l]^From[y.l])?From[x.l]<From[y.l]:((From[x.l]&1)?x.r<y.r:x.r>y.r);}
inline void dfs(int k,int fa)
{
	ST[k][0]=fa;dep[k]=dep[fa]+1;
	ol[++cnt1]=k;
	ru[k]=cnt1;
//	cout<<k<<","<<fa<<" "<<cnt1<<endl;
	for (int i=head[k];i;i=e[i].nx)
		if (e[i].to!=fa)
		{
			dfs(e[i].to,k);
		}
	ol[++cnt1]=k;
	chu[k]=cnt1;
}
inline int LCA(int x,int y)
{
	if (dep[x]<dep[y]) swap(x,y);
	for (int i=20;i>=0;i--)
	  if (dep[x]-(1<<i)>=dep[y])
	    x=ST[x][i];
	if (x==y) return x;
	for (register int i=20;i>=0;i--)
	{
		if (!(ST[x][i]==ST[y][i]))
		  x=ST[x][i],y=ST[y][i];
	}
	return ST[x][0];
}
signed main()
{
	n=read();m=read();
	lenth=B;
	for (int i=1;i<=n*2;i++) From[i]=(i-1)/lenth+1;
	for (int i=1;i<=n;i++)
		b[i]=read(),a[i]=b[i],Se[0].insert(a[i]);
	for (int i=1;i<n;i++)
	{
		x=read(),y=read();
//		cout<<x<<" "<<y<<endl;
		ad(x,y);
		ad(y,x);
	}
	dfs(1,0);
	for(re int i=1;(1<<i)<=n;++i)
      for(re int j=1;j<=n;++j)
        ST[j][i]=ST[ST[j][i-1]][i-1];
//	exit(0);
	for (int i=1;i<=n;i++)
	{
		A[ru[i]]=a[i];
		A[chu[i]]=a[i];
	}
	for (int i=1;i<=m;i++)
	{
		l=read(),r=read();
		bool bl=0;
		if (ru[l]>ru[r]) swap(l,r);
		q[i]={(chu[l]>ru[r])?ru[l]:chu[l],ru[r],i,(chu[l]>ru[r])?0:1};
		q[i].lca=LCA(l,r);
		q[i].l1=read(),q[i].r1=read();
	}
	sort(q+1,q+m+1,Cmp);
	l=1,r=0;
	for (int i=1;i<=m;i++)
	{
		while (l>q[i].l)
		{
			l--;
			t1=Cnt[abs(A[l])]%2;
			Cnt[abs(A[l])]+=(vis[ol[l]])?-1:1;
			vis[ol[l]]^=1;
			Se[t1].erase(A[l]);
			Se[t1^1].insert(A[l]);
		}
//		cout<<ans<<"!"<<endl;
		while (r<q[i].r)
		{
			r++;
//			r++;cout<<"!"<<A
			t1=Cnt[abs(A[r])]%2;
			Cnt[abs(A[r])]+=(vis[ol[r]])?-1:1;
			vis[ol[r]]^=1;
			Se[t1].erase(A[r]);
			Se[t1^1].insert(A[r]);
		}
//		cout<<ans<<"!"<<endl;
		while (l<q[i].l)
		{
			t1=Cnt[abs(A[l])]%2;       
			Cnt[abs(A[l])]+=(vis[ol[l]])?-1:1;
			vis[ol[l]]^=1;
			Se[t1].erase(A[l]);
			Se[t1^1].insert(A[l]);
			l++;
//			cout<<l<<" "<<ans<<" "<<ol[l]<<endl;
		}
//		cout<<ans<<"!"<<endl;
		while (r>q[i].r)
		{
			t1=Cnt[abs(A[r])]%2;
			Cnt[abs(A[r])]+=(vis[ol[r]])?-1:1;
			vis[ol[r]]^=1;
			Se[t1].erase(A[r]);
			Se[t1^1].insert(A[r]);
			r--;
		}
//		cout<<ans<<"!"<<endl;
		if (q[i].bl)
		{
		t1=Cnt[abs(a[q[i].lca])]%2;
		Cnt[abs(a[q[i].lca])]+=1;
		Se[t1].erase(a[q[i].lca]);
		Se[t1^1].insert(a[q[i].lca]);
		}
		Ans[q[i].id]=Se[1].query(q[i].l1,q[i].r1);
		if (q[i].bl)
		{
		t1=Cnt[abs(a[q[i].lca])]%2;
		Cnt[abs(a[q[i].lca])]-=1;
		Se[t1].erase(a[q[i].lca]);
		Se[t1^1].insert(a[q[i].lca]);
		}
	}
	for (int i=1;i<=m;i++) writeln(Ans[i]);
}
/*

*/