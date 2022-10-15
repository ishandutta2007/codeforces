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
#define N 100005
#define M 12
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,k;
struct sp
{
	int mx[M],mn[M],sz;
}s[N];
bool mg;
map<int,sp>MP;
signed main()
{
	n=read();k=read();
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<k;j++)
		{
			s[i].mx[j]=read();
			s[i].mn[j]=s[i].mx[j];
		}
		s[i].sz=1;
	}
	for(int i=0;i<n;i++)
	{
		MP[s[i].mn[0]]=s[i];
		auto it=MP.find(s[i].mn[0]),nit=it;
		++nit;
		while(nit!=MP.end())
		{
			mg=0;
			for(int j=0;j<k;j++)
			{
				if(nit->second.mn[j]<it->second.mx[j])
				{
					mg=1;
					break;
				}
			}
			if(mg)
			{
				for(int j=0;j<k;j++)
				{
					it->second.mn[j]=min(it->second.mn[j],nit->second.mn[j]);
					it->second.mx[j]=max(it->second.mx[j],nit->second.mx[j]);
				}
				it->second.sz+=nit->second.sz;
				nit=MP.erase(nit);
			}
			else break;
		}
		nit=it;
		while(nit!=MP.begin())
		{
			--nit;
			mg=0;
			for(int j=0;j<k;j++)
			{
				if(nit->second.mx[j]>it->second.mn[j])
				{
					mg=1;
					break;
				}
			}
			if(mg)
			{
				for(int j=0;j<k;j++)
				{
					it->second.mn[j]=min(it->second.mn[j],nit->second.mn[j]);
					it->second.mx[j]=max(it->second.mx[j],nit->second.mx[j]);
				}
				it->second.sz+=nit->second.sz;
				nit=MP.erase(nit);
			}
			else break;
		}
		writeln(MP.rbegin()->second.sz);
	}
}
/*

*/