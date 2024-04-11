//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define N 100005
#define int long long

using namespace std;

inline int read(){
    int x = 0; char ch = getchar(); bool positive = 1;
    for (; !isdigit(ch); ch = getchar())    if (ch == '-')  positive = 0;
    for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
    return positive ? x : -x;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writesp(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
    printf(" ");
}
inline void writeln(int a){
    if(a<0){
        a=-a; putchar('-');
    }
    write(a); puts("");
}

int T,n,cnt,ans,ans1,dp[N],siz[N],head[N],dp1[N],dep[N],x,y,ff[N];

struct
{
    int to,nx;
}e[N<<1];

void ad(int x,int y)
{
    e[++cnt].to=y;
    e[cnt].nx=head[x];
    head[x]=cnt;
}

inline void dfs(int now,int fa)
{
    siz[now]=1;dep[now]=dep[fa]+1;ff[now]=fa; 
    dp[now]=0;
    for(int i=head[now];i;i=e[i].nx)
    {
        int t=e[i].to;
        if(t==fa) continue;
        dfs(t,now);
        siz[now]+=siz[t];
        dp[now]=max(dp[now],siz[t]);
    }
    dp[now]=max(dp[now],n-siz[now]);
}

int dfs1(int k,int fa)
{
    for (int i=head[k];i;i=e[i].nx)
      if (e[i].to!=fa)
        return dfs1(e[i].to,k);
    return k;
}   

signed main()
{
    T=read();
    while (T--)
    {
        n=read();cnt=ans=ans1=0;dp[0]=INT_MAX;
        for (int i=1;i<=n;i++) head[i]=0,ff[i]=0;
        for (int i=1;i<n;i++)
        {
            x=read(),y=read();
            ad(x,y);
            ad(y,x);
        }
        dfs(1,0);
        int MIN=INT_MAX;
        for(int i=1;i<=n;++i)
        {
            MIN=min(MIN,dp[i]);
        }
        for (int i=1;i<=n;i++)
          if (dp[i]==MIN&&ans==0) ans=i; else 
          if (dp[i]==MIN) ans1=i;
        if (dep[ans]>dep[ans1]||ans1==0) swap(ans1,ans);
        if (ans!=0)
        {
        writesp(ff[dfs1(ans1,ff[ans1])]),writeln(dfs1(ans1,ff[ans1]));
        writesp(ans),writeln(dfs1(ans1,ff[ans1]));}
        else 
        {
            writesp(1),writeln(e[head[1]].to);
            writesp(1),writeln(e[head[1]].to);
            }
    }
}