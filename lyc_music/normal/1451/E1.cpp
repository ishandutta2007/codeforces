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
int nxx,bl,n,x,b[1ll<<17][20],ans[1ll<<17][20],tot[1ll<<17],lg[1ll<<17],b11[1ll<<17],b1[1ll<<17];
signed main()
{
	cin>>n;
	lg[0]=0;
	memset(b11,-1,sizeof(b11));
	for (int i=1;i<=n;i++) lg[i]=lg[i/2]+1;
	for (int i=1;i<n;i++)
	{
		printf("XOR 1 %d\n",i+1);
			fflush(stdout);
		cin>>x;
		for (int j=0;j<lg[n-1];j++)
			if (!(x&(1ll<<j)))
				b[i][j]=1,b1[i]+=(1ll<<j),tot[i]++;
	}
//	cout<<lg[n-1]<<endl;
	b11[(1ll<<lg[n-1])-1]=0;
	for (int i=1;i<n;i++)
	{
		if (~b11[b1[i]])
		{
			bl=1;
			printf("OR %d %d\n",b11[b1[i]]+1,i+1);
			fflush(stdout);
			cin>>x;
			for (int j=0;j<lg[n-1];j++)
					ans[0][j]=b[i][j]^1^((x&(1ll<<j))>0);
			break;
		} else b11[b1[i]]=i;
//		cout<<b1[i]<<endl;
	}
	if (!bl)
	{
		bl=0;
	for (int i=1;i<n;i++)
	{
		if ((tot[i]==lg[n-1]-1)&&bl<2)
		{
			bl++;
			printf("OR %d %d\n",0+1,i+1);
			fflush(stdout);
			cin>>x;
			for (int j=0;j<lg[n-1];j++)
				if (b[i][j])
					ans[0][j]=((x&(1ll<<j))>0);
					nxx=i;
		}
	}
		if (bl==1)
		{
			for (int i=1;i<n;i++)
			if ((tot[i]==lg[n-1]-2)&&bl<2)
			{
				bl++;
				printf("OR %d %d\n",nxx+1,i+1);
			fflush(stdout);
				cin>>x;
				for (int j=0;j<lg[n-1];j++)
					if (b[i][j]&&b[nxx][j])
						ans[0][j]=b[i][j]^1^((x&(1ll<<j))>0);
			}
		}
	}
	cout<<"! ";
	x=0;
	for (int j=0;j<lg[n-1];j++)
		if (ans[0][j]) x+=(1ll<<j);
	printf("%d ",x);
	for (int i=1;i<n;i++)
	{
		x=0;
		for (int j=0;j<lg[n-1];j++)
			x+=(1ll<<j)*(1^b[i][j]^ans[0][j]);
		printf("%d ",x);
	}
	fflush(stdout);
		
}
/*
4
0
2
3
0



*/