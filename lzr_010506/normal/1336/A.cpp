#include <cassert>
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
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
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
#define mp make_pair
#define pb push_back
#define left lef
#define right righ
#define rep(i,n) for(long long i=1;i<=n;++i)
#define bit(i) __builtin_popcount(i)
#define x1 gtmsub
#define y1 gtmshb
#define x2 gtmjtjl
#define y2 gtmsf
using namespace std;
int n,k;
vector<int> g[210000];
int dep[210000],son[210000],p[210000],v[210000];
long long ans=0;
void dfs(int x,int pre)
{
    dep[x]=dep[pre]+1;
    son[x]=1;
    for(auto p:g[x])
        if (p!=pre)
        {
            dfs(p,x);
            son[x]+=son[p];
        }
}
bool cmp(int x,int y)
{
    return dep[x]-son[x]>dep[y]-son[y];
}
long long cnt[210000];
void get(int x,int pre)
{
    if (v[x])cnt[x]=1; else cnt[x]=0;
    for(auto p:g[x])
        if (p!=pre)
        {
            get(p,x);
            cnt[x]=cnt[x]+cnt[p];
        }
    if (!v[x])ans=ans+cnt[x];
}
int main()
{
    cin>>n>>k;
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)p[i]=i;
    sort(p+1,p+n+1,cmp);
    for(int i=1;i<=k;i++)v[p[i]]=1;
    get(1,0);
    cout<<ans<<endl;
    return 0;
}