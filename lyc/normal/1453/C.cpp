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
#define int ll
#define N 2005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int T,n,a[N][N],b[3][3][N][10],ans;
string st;
signed main()
{	
	cin>>T;
	while (T--)
	{
		cin>>n;
		memset(b[0],0x3f,sizeof(b[0]));
		memset(b[1],0,sizeof(b[1]));
		for (int i=1;i<=n;i++)
		{
			cin>>st;
			for (int j=1;j<=st.length();j++)
			{
				a[i][j-1]=(int)(st[j-1]-'0'),b[0][0][i][a[i][j-1]]=min(b[0][0][i][a[i][j-1]],j),b[0][1][j][a[i][j-1]]=min(b[0][1][j][a[i][j-1]],i)
				,b[1][0][i][a[i][j-1]]=max(b[1][0][i][a[i][j-1]],j),b[1][1][j][a[i][j-1]]=max(b[1][1][j][a[i][j-1]],i);
				b[0][0][0][a[i][j-1]]=min(b[0][0][0][a[i][j-1]],j);
				b[1][0][0][a[i][j-1]]=max(b[1][0][0][a[i][j-1]],j);
				b[0][1][0][a[i][j-1]]=min(b[0][1][0][a[i][j-1]],i);
				b[1][1][0][a[i][j-1]]=max(b[1][1][0][a[i][j-1]],i);
			}
		}
		for (int d=0;d<10;d++)
		{
			ans=0;
			for (int i=1;i<=n;i++)
			{
				if (b[0][0][i][d]!=0x3f3f3f3f3f3f3f3f) ans=max(ans,(b[1][0][i][d]-b[0][0][i][d])*(n-i));
//				cout<<i<<" "<<ans<<" 1"<<endl;
//				cout<<b[0][0][i][d]<<" "<<b[1][0][i][d]<<endl;
				if (b[0][1][0][d]!=0x3f3f3f3f3f3f3f3f&&b[0][0][i][d]!=0x3f3f3f3f3f3f3f3f) ans=max(ans,max(b[1][0][i][d]-1,n-b[0][0][i][d])*max(abs(b[1][1][0][d]-i),abs(i-b[0][1][0][d])));
//				cout<<b[1][1][0][d]<<" "<<b[0][1][0][d]<<" "<<max(b[1][0][i][d]-1,n-b[0][0][i][d])<<endl;
			}
			for (int i=1;i<=n;i++)
			{
				if (b[0][1][i][d]!=0x3f3f3f3f3f3f3f3f) ans=max(ans,(b[1][1][i][d]-b[0][1][i][d])*(n-i));
//				cout<<i<<" "<<ans<<" 0"<<endl;
				if (b[0][0][0][d]!=0x3f3f3f3f3f3f3f3f&&b[0][1][i][d]!=0x3f3f3f3f3f3f3f3f) ans=max(ans,max(b[1][1][i][d]-1,n-b[0][1][i][d])*max(abs(b[1][0][0][d]-i),abs(i-b[0][0][0][d])));
			}
			writesp(ans);
		}
		putchar('\n');
	}
			
		
}
/*

*/