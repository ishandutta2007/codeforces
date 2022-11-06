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
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int T,n,s[4],B[4];
string ans;
char st[4][400005];
void work1()
{
	int l=1;
	for (int i=1;i<=2*n;i++)
	{
		while (l<=2*n&&st[B[2]][l]=='0') ans+='0',l++;
		if (l>2*n) ans+=st[B[1]][i];
		else
		{
			if (st[B[1]][i]==st[B[2]][l]) l++,ans+=st[B[1]][i];
			else ans+=st[B[1]][i];
		}
	}
	for (int i=l;i<=2*n;i++) ans+=st[B[2]][i];
}
bool Cmp(int x,int y)
{
	return s[x]<s[y];
}
void work2()
{
	int l=1;
	for (int i=1;i<=2*n;i++)
	{
		while (l<=2*n&&st[B[3]][l]=='1') ans+='1',l++;
		if (l>2*n) ans+=st[B[2]][i];
		else
		{
			if (st[B[2]][i]==st[B[3]][l]) l++,ans+=st[B[2]][i];
			else ans+=st[B[2]][i];
		}
	}
	for (int i=l;i<=2*n;i++) ans+=st[B[3]][i];
}
signed main()
{
	T=read();
	while (T--)
	{
		n=read();ans="";
		for (int i=1;i<=3;i++) scanf("%s",st[i]+1),s[i]=0;
		for (int i=1;i<=3;i++)
		{
			for (int j=1;j<=2*n;j++)
			{
				if (st[i][j]=='0') 
				s[i]+=1;
			}
		}
		B[1]=1,B[2]=2,B[3]=3;
		sort(B+1,B+3+1,Cmp);
		if (s[B[2]]<=n)
		{
			work1();
		}else
		{
			work2();
		}
		cout<<ans<<endl;
	}
}
/*

*/