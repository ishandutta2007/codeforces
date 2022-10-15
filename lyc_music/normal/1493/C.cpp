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
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int T,n,m,b[N][50],k,now,bl,p;
string st,st1,ST;
signed main()
{
	T=read();
	while (T--)
	{
		n=read(),k=read();bl=0;
		cin>>st;
		ST=st;
		st=' '+st;st1="";
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=26;j++) b[i][j]=b[i-1][j];
			(b[i][st[i]-'a'+1]+=1)%=k;
		}
		int bl1=1;
		for (int j=1;j<=26;j++) if (b[n][j]%k!=0) bl1=0;
		if (bl1) {cout<<ST<<endl;continue;}
		for (int i=n;i>=1;i--)
		{
			if (bl) break;
			for (int j1=st[i]-'a'+2;j1<=26;j1++)
			{
				now=0;
				b[i][st[i]-'a'+1]=(b[i][st[i]-'a'+1]-1+k)%k;
				b[i][j1]=(b[i][j1]+1+k)%k;
				for (int j=1;j<=26;j++)
				{
					if (b[i][j]%k!=0)
					{
						now+=k-b[i][j]%k;
					}
				}
				if (now<=(n-i))
				{
					st1="";
					for (int j=1;j<=26;j++)
					{
						if (b[i][j]%k!=0)
						{
							for (int k1=1;k1<=k-b[i][j]%k;k1++) st1+=(char)j+'a'-1;
						}
					}
					if (((n-i)-st1.length())%k!=0) break;
					while (st1.length()!=n-i) st1="a"+st1;
					st1=(char)((char)j1+'a'-1)+st1;
					for (int j=i-1;j>=1;j--) st1=st[j]+st1;
					cout<<st1<<endl;bl=1;
					break;
				}
				b[i][st[i]-'a'+1]=(b[i][st[i]-'a'+1]+1+k)%k;
				b[i][j1]=(b[i][j1]-1+k)%k;
			}
		}
		if (!bl) puts("-1");
	}			
}
/*
1
2 2
ba
*/