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
#define N 2000005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
//#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m,k,d,p;
int to[N],f[N],now,ans[N],P[N],lans[N],b[N],PP[N],cnt,PPP[N];
bool vis[N];
		char lst1[N/2];
char st[N/2];
vector<int>G[N];
int pd(int x,int y)
{
	int p=k-1,l=n-1;
	p=max(p,x);
	l=min(l,x+k-1);
	return l-p+1;
}
signed main()
{
	scanf("%s",st);
	m=read();
	n=strlen(st);
	for (int i=0;i<n;i++) lans[i]=i;
	memset(f,-1,sizeof(f));
	while (m--)
	{
		k=read(),d=read();
		p=0;
		for (int i=0;i<d;i++)
			for (int j=i;j<k;j+=d)
			{
				f[p+k-1]=j+k;
				p++;
			}
		
		now=k-1;p=0;
		b[0]=-1;
		while (~now)
		{
			now=f[now];
			if (now==-1) break;
			vis[now]=1;
			p++;
			P[now-k]=p;
			b[p]=now-k;
		}
		for (int i=k;i<k+k;i++)
			if (!vis[i])
			{
				now=i;p=0;
				++cnt;
				do
				{
					vis[now]=1;
					PP[now-k]=p;
					PPP[now-k]=cnt;
					G[cnt].push_back(now-k);
					p++;
					now=f[now];
				}while (now!=i);
			}
		for (int i=0;i<k;i++)
		{
			int rnd=min(n-k+1,P[i]);
			if (!P[i]) 
			{
				rnd=n-k+1;
				ans[rnd-2+max(1,i-k+1)+G[PPP[i]][(PP[i]-rnd%G[PPP[i]].size()+G[PPP[i]].size())%G[PPP[i]].size()]+1]=i;
			}
			else
			{
				ans[rnd+b[P[i]-rnd]]=i;
			}
		}
		
		for (int i=k;i<n;i++)
		{
			int rnd=min(n-i,P[k-1]);
			if (!P[k-1]) ans[n-k+i+1]=i;
			else
			{
				ans[rnd+max(1,i-k+2)+b[P[k-1]-rnd]-1]=i;
			}
		}
		for (int i=0;i<n;i++)  lst1[i]=st[ans[i]];
		printf("%s\n",lst1);
		for (int i=0;i<n;i++) st[i]=lst1[i];
		for (int i=1;i<=cnt;i++) G[i].clear();cnt=0;
		for (int i=0;i<=k+k;i++) P[i]=b[i]=vis[i]=PP[i]=PPP[i]=0,f[i]=-1;
	}
}
/*
SxMxmXrvdWttWbChHqIDDtq6yq5LcPHgvs5Cv86J1C4IMKwA7Ug6KINwZvBZRyxgvZNeXELQlINjWtBosI1C55HH3mPVXWFDst4d
1
92 88


SxMxmXrvdWttWbChHqIDDtq6yq5LcPHgvs5Cv86J1C4IMKwA7Ug6KINwZvBZRyxgvZNeXELQlINjWtBosI1C55HH3mPVXWFDst4d
100
92 88
2 1
45 4
70 3
87 7
63 7
54 46
66 4
89 2
66 6
61 4
17 12
2 1
65 3
82 8
20 5
98 9
57 54
76 6
97 3
49 21
15 3
46 21
46 3
76 69
14 8
5 3
43 35
77 68
76 1
37 1
70 4
75 10
48 2
87 3
93 3
1 1
31 3
51 24
21 4
28 27
36 10
30 4
95 9
12 1
7 1
13 3
31 7
30 5
8 3
95 7
98 6
33 5
68 2
29 14
73 8
26 5
22 11
26 24
77 34
44 6
59 43
6 2
34 21
28 1
65 38
90 2
27 5
62 4
93 9
54 6
69 64
77 7
1 1
40 9
28 4
30 3
27 9
79 9
88 6
48 7
61 50
21 9
3 1
69 24
91 1
85 66
88 4
21 5
49 5
100 40
50 15
52 42
41 28
60 5
95 5
5 2
83 7
83 45
22 4

*/