#include <bits/stdc++.h>
#define N 500005
#define ll long long
#define mod 1000000007
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int T;
int n,m;
int fa[N];
int sz[N];
long long bin[N];
int ok[N];
vector<int> v;
int find(int x) {
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
void solve(){
    long long ans=1;
    for(int i=1;i<=m;i++)
    if(find(i)==i) {
        ans*=bin[sz[i]+ok[i]-1];
        ans%=mod;
    }
    printf("%lld %d\n",ans,v.size());

    for(auto i : v) printf("%d ",i);
}
void init(){
    n=read(),m=read();
    for(int i=1;i<=m;i++) fa[i]=i,sz[i]=1;
}
int main()
{
    init();
    bin[0]=1;
    for(int i=1;i<=500003;i++) bin[i]=bin[i-1]*2%mod;
    for(int i=1;i<=n;i++) {
        int k=read();
        if(k==1) {
            int x=read();
            x=find(x);
            if(ok[x]) continue ;
            ok[x]=1;
            v.push_back(i);
        } else {
            int x=read(),y=read();
            x=find(x),y=find(y);
            if(ok[x] && ok[y]) continue ;
            if(x==y) continue ;
            ok[y]|=ok[x];
            fa[x]=y;
            sz[y]+=sz[x];
            v.push_back(i);
        }
    }
    solve();
}