#include<bits/stdc++.h>
using namespace std;
#define For(i,n) for(int i=1;i<=n;i++)
#define Fork(i,k,n) for(int i=k;i<=n;i++)
#define Rep(i,n) for(int i=0;i<n;i++)
#define ForD(i,n) for(int i=n;i;i--)
#define ForkD(i,k,n) for(int i=n;i>=k;i--)
#define RepD(i,n) for(int i=n;i>=0;i--)
#define Forp(x) for(int p=Pre[x];p;p=Next[p])
#define Forpiter(x) for(int &p=iter[x];p;p=Next[p])  
#define Lson (o<<1)
#define Rson ((o<<1)+1)
#define MEM(a) memset(a,0,sizeof(a));
#define MEMI(a) memset(a,127,sizeof(a));
#define MEMi(a) memset(a,128,sizeof(a));
#define INF (2139062143)
#define F (1000000007)
#define pb push_back
#define mp make_pair 
#define fi first
#define se second
#define vi vector<int> 
#define pi pair<int,int>
#define SI(a) ((a).size())
#define Pr(kcase,ans) printf("Case #%d: %I64d\n",kcase,ans);
#define PRi(a,n) For(i,n-1) cout<<a[i]<<' '; cout<<a[n]<<endl;
#define PRi2D(a,n,m) For(i,n) { \
						For(j,m-1) cout<<a[i][j]<<' ';\
						cout<<a[i][m]<<endl; \
						} 
#pragma comment(linker, "/STACK:102400000,102400000")
#define ALL(x) (x).begin(),(x).end()
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
ll mul(ll a,ll b){return (a*b)%F;}
ll add(ll a,ll b){return (a+b)%F;}
ll sub(ll a,ll b){return ((a-b)%F+F)%F;}
void upd(ll &a,ll b){a=(a%F+b%F)%F;}
int read()
{
	int x=0,f=1; char ch=getchar();
	while(!isdigit(ch)) {if (ch=='-') f=-1; ch=getchar();}
	while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar();}
	return x*f;
} 
#define SZ 210000
#define P 20
int n,m,a[SZ],fst[SZ],vb[SZ],nxt[SZ],as[SZ],M=0,fa[SZ];
void ad_de(int a,int b) {++M; nxt[M]=fst[a]; fst[a]=M; vb[M]=b;}
void adde(int a,int b) {ad_de(a,b); ad_de(b,a);}
int cc=0,st[SZ],ed[SZ],dfx[SZ];
void dfs(int x)
{
    st[x]=++cc; dfx[cc]=x;
    for(int e=fst[x];e;e=nxt[e])
    {
        int b=vb[e]; if(b==fa[x]) continue;
        fa[b]=x; dfs(b);
    }
    ed[x]=++cc; dfx[cc]=x;
}
int cc_=0,app[SZ],dep[SZ],lo2[SZ];
pi pp[SZ],minn[SZ][P];
void dfs_(int x)
{
    ++cc_; app[x]=cc_; pp[cc_]=pi(dep[x],x);
    for(int e=fst[x];e;e=nxt[e])
    {
        int b=vb[e]; if(b==fa[x]) continue;
        dep[b]=dep[x]+1; dfs_(b);
        pp[++cc_]=pi(dep[x],x);
    }
}
void build()
{
    for(int i=1;i<=cc_;i++) minn[i][0]=pp[i];
    for(int i=1;i<=cc_;i++)
    {
        int g=0;
        while((1<<g)<=i) ++g;
        lo2[i]=g-1;
    }
    for(int p=1;p<P;p++)
    {
        for(int i=1;i<=cc_;i++)
        {
            if(i+(1<<p)-1>cc_) break;
            minn[i][p]=min(minn[i][p-1],minn[i+(1<<(p-1))][p-1]);
        }
    }
}
int lca(int a,int b)
{
    a=app[a]; b=app[b];
    if(a>b) swap(a,b);
    int l2=lo2[b-a+1];
    return min(minn[a][l2],minn[b-(1<<l2)+1][l2]).second;
}
int bs,qn=0;
struct query {int l,r,m,id;} qs[SZ];
bool operator < (query a,query b)
{
    if(a.l/bs!=b.l/bs) return a.l/bs<b.l/bs;
    else return a.r<b.r;
}
#define Addq(l_,r_,m_,id_) ++qn, qs[qn].l=l_, qs[qn].r=r_, qs[qn].m=m_, qs[qn].id=id_;
int cov[SZ],coa[SZ][2];
int sex[SZ]={};
ll ans=0,anss[SZ];
void edt(int p,int k)
{
    ans-=coa[a[p]][sex[p]^1]*(cov[p]&1);
    coa[a[p]][sex[p]]-=cov[p]&1;
    cov[p]+=k;
    coa[a[p]][sex[p]]+=cov[p]&1;
    ans+=coa[a[p]][sex[p]^1]*(cov[p]&1);
//	cout<<p<<' '<<k<<' '<<ans<<endl;
}
int main()
{
//	freopen("I.in","r",stdin);
    n=read();
	bs=sqrt(n)+1;
	For(i,n) sex[i]=read();
    For(i,n)
		a[i]=read(),as[i]=a[i];
    sort(as+1,as+1+n); int nn=unique(as+1,as+1+n)-as-1;
    For(i,n) a[i]=lower_bound(as+1,as+1+nn,a[i])-as;
    For(i,n-1)
    {
    	int a=read(),b=read();
        adde(a,b);
    }
    m=read();
    dfs(1); dfs_(1); build();
    for(int i=1;i<=m;i++)
    {
        int a=read(),b=read(),p;
        p=lca(a,b);
        if(st[a]>st[b]) swap(a,b);
        if(p==a) Addq(st[a],st[b],0,i)
        else Addq(ed[a],st[b],p,i)
    }
    sort(qs+1,qs+1+qn);
    int l=1,r=0;
    for(int i=1;i<=qn;i++)
    {
        int ql=qs[i].l,qr=qs[i].r;
        while(l<ql) edt(dfx[l++],-1);
        while(l>ql) edt(dfx[--l],1);
        while(r>qr) edt(dfx[r--],-1);
        while(r<qr) edt(dfx[++r],1);
        if(qs[i].m) edt(qs[i].m,1);
        anss[qs[i].id]=ans;
        if(qs[i].m) edt(qs[i].m,-1);
    }
    
    For(i,m) printf("%I64d\n",anss[i]);
}