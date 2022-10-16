#include<bits/stdc++.h>
using namespace std;
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
const int N=3e5+7,M=12e5+7;
typedef int ar[N];
int R,to[M],ne[M],t=1,tp,ct,id,r;
ar he,sn,sz,fa,d,p,hd,dfn,low,st,bl,b;
void add(int x,int y){if(x!=r&&y!=r)ne[++t]=he[x],to[t]=y,he[x]=t,ne[++t]=he[y],to[t]=x,he[y]=t;}
basic_string<int>g[N],a,v;
void dfs1(int x,int y){
	sz[x]=1;
	for(int i:g[x])if(i!=y)if(fa[i]=x,d[i]=d[x]+1,dfs1(i,x),sz[x]+=sz[i],sz[i]>sz[sn[x]])sn[x]=i;
}
void dfs2(int x,int y){
	if(hd[x]=y,p[x]=++id,sn[x])dfs2(sn[x],y);
	for(int i:g[x])if(i!=sn[x]&&i!=fa[x])dfs2(i,i);
}
int lca(int x,int y){
	for(;hd[x]!=hd[y];x=fa[hd[x]])if(d[hd[x]]<d[hd[y]])swap(x,y);
	return d[x]<d[y]?x:y;
}
#define _(x) (((x)+R-1)%n+1)
#define S (sort(a.begin(),a.end(),cmp),a.resize(unique(a.begin(),a.end())-a.begin()))
void tar(int x,int z){
	dfn[x]=low[x]=++id,st[++tp]=x;
	for(int i=he[x],j;i;i=ne[i])if(!dfn[j=to[i]])tar(j,i^1),low[x]=min(low[x],low[j]);
	else if(i!=z)low[x]=min(low[x],dfn[j]);
	if(low[x]==dfn[x])for(++ct;bl[st[tp]]=ct,st[tp--]!=x;);
}
bool cmp(int x,int y){return p[x]<p[y];}
int main(){
	int n,m,q,i,j,k;
    cin>>n>>m>>q;
	for(r=n+1;m--;){cin>>i>>j;add(i,j);}
	for(i=1;i<=n;++i)if(!dfn[i])g[r]+=ct+1,g[ct+1]+=r,tar(i,0);
	for(i=1;i<=n;++i)for(j=he[i];j;j=ne[j])if(bl[i]!=bl[to[j]])g[bl[i]]+=bl[to[j]];
	for(i=1,dfs1(r,0),id=0,dfs2(r,r),memcpy(b,bl,N*4),memset(he,0,N*4);i<=q;++i){
        cin>>k>>m;
		for(v={},t=1,id=ct=0;k--;){cin>>j;v+=b[_(j)];}
		for(a=v;m--;){cin>>j>>k;j=b[_(j)],k=b[_(k)],a+=j,a+=k,add(j,k);}
		for(S,k=a.size(),j=1;j<k;++j)a+=lca(a[j-1],a[j]);
		for(S,k=a.size(),j=1;j<k;++j)add(a[j],lca(a[j-1],a[j]));
		for(auto o:a)dfn[o]=0;
		for(auto o:a)if(!dfn[o])tar(o,0);
		k=bl[v[0]];
		for(auto o:v)if(bl[o]!=k){puts("NO");goto gg;}
		puts("YES"),R=(R+i)%n;
		gg:for(auto o:a)he[o]=0;
	}
	return 0;
}