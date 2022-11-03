// luogu-judger-enable-o2
// luogu-judger-enable-o2
// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n,m,k;
int block;
int a[N],b[N],belong[N],cnt[20*N];
ll s[N];
struct ask{
    int l,r,id;
}q[N];
inline int read(){
    register int s=0;register char ch=getchar();
    while(!isdigit(ch)) ch=getchar();
    while(isdigit(ch)) s=s*10+ch-48,ch=getchar();
    return s;
}
inline bool cmp(const ask &a,const ask &b){
    return belong[a.l]^belong[b.l]?belong[a.l]<belong[b.l]:belong[a.l]&1?a.r<b.r:a.r>b.r;
}
ll ans=0;
inline void add(int x){ans+=cnt[x^k],cnt[x]++;}
inline void del(int x){cnt[x]--,ans-=cnt[x^k];}
int main(){
    n=read(),m=read(),k=read();
    block=max((int)(n/sqrt(m)),1);
    for(register int i=1;i<=n;i++) a[i]=read()^a[i-1],belong[i]=(i-1)/block+1;
    for(register int i=1;i<=m;i++) q[i].l=read(),q[i].r=read(),q[i].id=i;
    sort(q+1,q+m+1,cmp);
    int l=1,r=0;cnt[0]=1;
    for(register int i=1;i<=m;i++){
        for (;r<q[i].r;r++) add(a[r+1]);
        for (;r>q[i].r;r--) del(a[r]);
        for (;l<q[i].l;l++) del(a[l-1]);
        for (;l>q[i].l;l--) add(a[l-2]);
        s[q[i].id]=ans;
    }
    for(register int i=1;i<=m;i++) printf("%I64d\n",s[i]);
    return 0;
}
/*
50 1 0

0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

17 35

*/