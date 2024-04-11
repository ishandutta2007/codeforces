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
#define pb push_back
#define f first
#define s second
#define endl '\n'
#define mt make_tuple
#define mp make_pair
#define pii pair<int, int>
#define t3i tuple<int, int, int>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define debug(x) {cerr <<#x<<" = " <<x<<"\n"; }
#define debug2(x, y) {cerr << #x << " = " << x <<", "<<#y <<" = " <<y <<"\n";}
#define debug3(x, y, z) {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<", "<<#z<<" = "<<z<<"\n";}
#define len(x) ((int)x.size())
#define inf 1000000005
#define mod 1000000007
#define pii pair<int, int>
#define int ll
//#define N
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll a){if(a<0){a=-a; putchar('-');}write(a); putchar(' ');}
inline void writeln(ll a){if(a<0){a=-a; putchar('-');}write(a); puts("");}
 
void fast()
{
    ios::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
 
struct Info
{
    int sum = 0;
    int ma = 0;
};
 
vector<int> mas;
vector<Info> t;
int n;
 
inline void build(int v, int cl, int cr)
{
    if (cl == cr)
    {
        t[v].sum = mas[cl];
        t[v].ma = mas[cl];
        return;
    }
    int mid = (cl + cr) / 2;
    build(v * 2, cl, mid);
    build(v * 2 + 1, mid + 1, cr);
    t[v].sum = t[v * 2].sum + t[v * 2 + 1].sum;
    t[v].ma = max(t[v * 2].ma, t[v * 2 + 1].ma);
}
 
inline void modify(int v, int cl, int cr, int num, int a)
{
    if (cr < num || cl > num)
        return;
    if (cr == cl)
    {
        t[v].sum = a;
        t[v].ma = a;
        return;
    }
    int mid = (cl + cr) / 2;
    modify(v * 2, cl, mid, num, a);
    modify(v * 2 + 1, mid + 1, cr, num, a);
    t[v].sum = t[v * 2].sum + t[v * 2 + 1].sum;
    t[v].ma = max(t[v * 2].ma, t[v * 2 + 1].ma);
}
 
inline int getmax(int v, int cl, int cr, int nl, int nr)
{
    if (cl >= nl && cr <= nr)
        return t[v].ma;
    if (cl > nr || cr < nl)
        return -1;
    int mid = (cl + cr) / 2;
    int ansl = getmax(v * 2, cl, mid, nl, nr);
    int ansr = getmax(v * 2 + 1, mid + 1, cr, nl, nr);
    return max(ansl, ansr);
}
 
int INF = 1e9;
 
inline pii fp(int v, int cl, int cr, int sum, int re)
{
    if (cr <= re || t[v].ma < sum)
        return {INF, INF};
    if (cl == cr)
    {
        if (t[v].sum < sum)
            return {INF, INF};
        return {cl, t[v].sum};
    }
    int mid = (cl + cr) / 2;
    pii ansl = fp(v * 2, cl, mid, sum, re);
    if (ansl.first != INF)
        return ansl;
    pii ansr = fp(v * 2 + 1, mid + 1, cr, sum, re);
    return min(ansl, ansr);
 
}
 
inline int getsum(int v, int cl, int cr, int nl, int nr)
{
    if (cl >= nl && cr <= nr)
        return t[v].sum;
    if (cr < nl || cl > nr)
        return 0;
    int mid = (cl + cr) / 2;
    int ansl = getsum(v * 2, cl, mid, nl, nr);
    int ansr = getsum(v * 2 + 1, mid + 1, cr, nl, nr);
    return ansl + ansr;
}
 
signed main()
{
    int z, i, j, k, a, b;
    n=read(),z=read();
    mas.resize(n);
    t.resize(n * 4 + 5);
    for (i = 0 ; i < n; i++)
        mas[i]=read();
    build(1, 0, n - 1);
    while (z--)
    {
        int re, sum, pos, val, val2, pos2;
        pos=read(),val=read();
        modify(1, 0, n - 1, pos - 1, val);
        re = 0;
        sum = getsum(1, 0, n - 1, 0, 0);
        int olsum = getsum(1, 0, n - 1, 0, n - 1);
        if (sum == 0)
        {
            writeln(1);
            continue;
        }
        bool gotit = false;
        while (true)
        {
            if (sum == olsum)
                break;
            tie(pos2, val2) = fp(1, 0, n - 1, sum, re);
            if (val2 == INF)
                break;
            if (val2 == getsum(1, 0, n - 1, 0, pos2 - 1))
            {
                writeln(pos2+1);
                gotit = true;
                break;
            }
            else
            {
                sum = getsum(1, 0, n - 1, 0, pos2);
                re = pos2;
            }
            if (re == n - 1)
                break;
        }
        if (!gotit)
            writeln(-1);
    }
    return 0;
}