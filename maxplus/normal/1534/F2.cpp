// from #119564378

#include<algorithm>
#include<bitset>
#include<cstring>
#include<cstdio>

#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define as_const
using namespace std;
typedef long long ll;
const int N=4E5+10;
const int inf=1<<30;
int read()
{
    int a=0;
    char c;
    while ((c=getchar())>='0') a = a * 10 + c - '0';
    return a;
}
void write(ll x,char c)
{
    if(x<0)putchar(45),x=-x;
    char a[20],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
    putchar(c);
}
const int n = read(), m = read();
bitset<N>a;
int l[N],r[N],st[N];
template <int* __restrict l>
void dfs(int idx)
{
  constexpr auto& __restrict st = ::st;
  int top = 0;
  const int w = idx / n;
  st[top++] = idx;
  l[idx]=w;
  while (top) {
    int idx = st[--top];
    if(idx/n&&as_const(a)[idx-n]&&l[idx-n]==-1)l[idx-n]=w,st[top++]=idx-n;
    if(idx/n<m-1&&as_const(a)[idx+n]&&l[idx+n]==-1)l[idx+n]=w,st[top++]=idx+n;
    if(idx%n&&as_const(a)[idx-1]&&l[idx-1]==-1)l[idx-1]=w,st[top++]=idx-1;
    if(idx%n<n-1&&l[idx+1]==-1)l[idx+1]=w,st[top++]=idx+1;
  }
}
int main()
{
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            a[i+j*n]=getchar()&1;
            __builtin_prefetch(reinterpret_cast<char*>(&a) + ((i + (j + 4) * n) / 8), 1, 0);
        }
        getchar();
    }
    memset(l, -1, sizeof l);
    memset(r, -1, sizeof r);
    for(int j=0;j<m;++j)
    {
        int i=0;
        while(i<n&&!as_const(a)[i+j*n])++i;
        if(i<n && l[i + j*n] == -1)dfs<l>(i+j*n);
    }
    for(int j=m;j--;)
    {
        int i=0;
        while(i<n&&!as_const(a)[i+j*n])++i;
        if(i<n && r[i + j*n] == -1)dfs<r>(i+j*n);
    }
    for(int j=0;j<m;++j) st[j]=m;
    for(int j=0;j<m;++j)
    {
        int s=read();
        if(!s)continue;
        int idx=n + j * n;
        while(s)
        {
            s -= as_const(a)[--idx];
        }
        st[l[idx]]=min(st[l[idx]],r[idx]);
    }
    int ans=0;
    for(int i=0,j=m;i<m;++i)
    {
        j=min(j,st[i]);
        if(i==j)
        {
            ++ans;
            j=m;
        }
    }
    write(ans,'\n');
}