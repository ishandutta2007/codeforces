#include<cstdio>
#include<bits/stdc++.h>
struct IO_Tp {
    const static int _I_Buffer_Size = 2 << 23;
    char _I_Buffer[_I_Buffer_Size], *_I_pos = _I_Buffer;
 
    const static int _O_Buffer_Size = 2 << 23;
    char _O_Buffer[_O_Buffer_Size], *_O_pos = _O_Buffer;
 
    IO_Tp() { fread(_I_Buffer, 1, _I_Buffer_Size, stdin); }
    ~IO_Tp() { fwrite(_O_Buffer, 1, _O_pos - _O_Buffer, stdout); }
    IO_Tp &operator>>(int &res) {
        int f=1;
        while (!isdigit(*_I_pos)&&(*_I_pos)!='-') ++_I_pos;
        if(*_I_pos=='-')f=-1,++_I_pos;
        res = *_I_pos++ - '0';
        while (isdigit(*_I_pos)) res = res * 10 + (*_I_pos++ - '0');
        res*=f;
        return *this;
    }
    IO_Tp &operator<<(int n) {
        if(n<0)*_O_pos++='-',n=-n;
        static char _buf[10];
        char *_pos = _buf;
        do
            *_pos++ = '0' + n % 10;
        while (n /= 10);
        while (_pos != _buf) *_O_pos++ = *--_pos;
        return *this;
    }
    #define int long long
    IO_Tp &operator>>(int &res) {
        int f=1;
        while (!isdigit(*_I_pos)&&(*_I_pos)!='-') ++_I_pos;
        if(*_I_pos=='-')f=-1,++_I_pos;
        res = *_I_pos++ - '0';
        while (isdigit(*_I_pos)) res = res * 10 + (*_I_pos++ - '0');
        res*=f;
        return *this;
    }
    IO_Tp &operator<<(int n) {
        if(n<0)*_O_pos++='-',n=-n;
        static char _buf[10];
        char *_pos = _buf;
        do
            *_pos++ = '0' + n % 10;
        while (n /= 10);
        while (_pos != _buf) *_O_pos++ = *--_pos;
        return *this;
    }
    #undef int
    #define int double
    IO_Tp &operator>>(int &res) {
        int f=1;
        while (!isdigit(*_I_pos)&&(*_I_pos)!='-') ++_I_pos;
        if(*_I_pos=='-')f=-1,++_I_pos;
        res = *_I_pos++ - '0';
        while (isdigit(*_I_pos)) res = res * 10 + (*_I_pos++ - '0');
        res*=f;
        return *this;
    }
    IO_Tp &operator<<(int n) {
        std::cout<<n;
        return *this;
    }
    #undef int
    IO_Tp &operator<<(char ch) {
        *_O_pos++ = ch;
        return *this;
    }
} IO;
#define cin IO
#define cout IO
#define endl '\n'
#define M 200002
#define N 100001
inline void swap(int&x,int&y){int z=x;x=y,y=z;}
int a[N],b[M],c[M],e[N],f[N],g[N],h[N],k[N],n;long long d[N],x;
int find(int u){return k[u]?k[u]=find(k[u]):u;}
void dfs(int u){for(int i=a[e[u]=g[u]=1,h[u]=h[f[u]]+1,u];i;i=b[i])if(c[i]!=f[u])f[c[i]]=u,dfs(c[i]),d[u]+=(long long)(e[u]-g[u])*e[c[i]],e[u]+=e[c[i]];}
inline long long calc(int u){return(long long)g[u]*(g[u]-1)*(n+n-g[u]-2)+g[u]*(d[u]+(long long)(e[u]-g[u])*(n-e[u])<<1);}
int i,m,u,v,w;
int main()
{
    cin>>n;
	for(i=1;i<n;i++){cin>>u>>v;b[i<<1]=a[u],c[a[u]=i<<1]=v,b[i<<1|1]=a[v],c[a[v]=i<<1|1]=u;}
    cin>>m;
	for(i=1,dfs(1);i<=n;i++)x+=calc(i);
    cout<<x<<endl;
	for(i=1;i<=m;i++)
    {cin>>u>>v;
	for(;(u=find(u))!=(v=find(v));)h[u]<h[v]?swap(u,v):void(),x-=calc(u)+calc(w=find(f[u])),e[w]-=e[u],d[w]-=(long long)(e[w]-g[w])*e[u],d[w]+=d[u]+(long long)(e[w]-g[w])*(e[u]-g[u]),e[w]+=e[u],g[w]+=g[u],k[u]=w,x+=calc(w);
	cout<<x<<endl;}
    return 0;
}