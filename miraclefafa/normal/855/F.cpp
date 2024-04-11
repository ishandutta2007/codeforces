#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

// hdu 5306 copy from Internet
struct solver {
struct Tree  
{  
    int l,r,num,mx,flag;  
    //num  
    //mx:  
    //flag:   
    ll sum;  
    //sum:   
}tree[100000<<2];  
void makeflag(int k,int flag)  
{  
    if(tree[k].flag!=0&&tree[k].flag<=flag)  
        return;  
    tree[k].flag=flag;  
    tree[k].sum+=ll(tree[k].r-tree[k].l+1-tree[k].num)*flag;  
    //num   
    if(tree[k].num<tree[k].r-tree[k].l+1)  
        tree[k].mx=flag;  
    tree[k].num=tree[k].r-tree[k].l+1;  
    //   
}  
void pushdown(int k)//k   
{  
    if(tree[k].flag==0)  
        return;  
    makeflag(k<<1,tree[k].flag);  
    makeflag(k<<1|1,tree[k].flag);      
}  
void pushup(int k)//k   
{  
    tree[k].mx=max(tree[k<<1].mx,tree[k<<1|1].mx);  
    tree[k].num=tree[k<<1].num+tree[k<<1|1].num;  
    tree[k].sum=tree[k<<1].sum+tree[k<<1|1].sum;  
}  
void build(int l,int r,int k)  
{  
    tree[k].l=l;  
    tree[k].r=r;  
    tree[k].flag=0;  
    if(l==r)  
    {  
        tree[k].flag=1<<30;
        tree[k].num=1;  
        tree[k].mx=tree[k].sum=tree[k].flag;  
        return;  
    }  
    int m=l+r>>1;  
    build(l,m,k<<1);  
    build(m+1,r,k<<1|1);  
    pushup(k);  
}  
void dfs(int k,int flag)  
{  
    if(tree[k].mx<=flag)  
        return;  
    if(tree[k].flag>=flag)  
        tree[k].flag=0;  
    if(tree[k].l==tree[k].r)  
    {  
        tree[k].mx=tree[k].sum=tree[k].flag;  
        tree[k].num=tree[k].flag!=0;  
        return;  
    }  
    pushdown(k);  
    dfs(k<<1,flag);  
    dfs(k<<1|1,flag);  
    pushup(k);  
}  
void update(int l,int r,int flag,int k)  
{  
    if(tree[k].mx<=flag)  
        return;  
    if(l==tree[k].l&&r==tree[k].r)  
    {  
        dfs(k,flag);//   
        makeflag(k,flag);//   
        return;  
    }  
    int m=tree[k].l+tree[k].r>>1;  
    pushdown(k);  
    if(r<=m)  
        update(l,r,flag,k<<1);  
    else if(l>m)  
        update(l,r,flag,k<<1|1);  
    else  
    {  
        update(l,m,flag,k<<1);  
        update(m+1,r,flag,k<<1|1);  
    }  
    pushup(k);  
}  
Tree seek(int l,int r,int k)  
{  
    if(l==tree[k].l&&r==tree[k].r)  
        return tree[k];  
    int m=tree[k].l+tree[k].r>>1;  
    pushdown(k);  
    if(r<=m)  
        return seek(l,r,k<<1);  
    if(l>m)  
        return seek(l,r,k<<1|1);  
    Tree t1=seek(l,m,k<<1);  
    Tree t2=seek(m+1,r,k<<1|1);  
    t1.mx=max(t1.mx,t2.mx);  
    t1.sum+=t2.sum;  
    return t1;  
}  
}T[4][2];

int ty,l,r,k,q,n;
set<int> hs[4];
void gao(int u,int v,int w,int k) {
	while (1) {
		auto t=hs[u].lower_bound(l);
		if (t!=hs[u].end()&&*t<=r) {
			T[u][0].update(*t,*t,0,1);
			T[u][1].update(*t,*t,0,1);
			if (w!=-1) {
				T[w][0].update(*t,*t,0,1);
				T[w][1].update(*t,*t,0,1);				
			}
			hs[u].erase(t);
			hs[v].insert(*t);
		} else break;
	}	
}
int main() {
	scanf("%d",&q);
	n=100000;
	rep(i,0,4) {
		T[i][0].build(1,n,1),T[i][1].build(1,n,1);
	}
	rep(i,1,n) hs[0].insert(i);
	rep(i,0,q) {
		scanf("%d%d%d",&ty,&l,&r);
		--r;
		if (ty==1) {
			scanf("%d",&k);
			if (k>0) {
				rep(j,0,4) T[j][0].update(l,r,k,1);
				gao(0,2,1,k);
				gao(1,3,-1,k);
			} else {
				rep(j,0,4) T[j][1].update(l,r,-k,1);
				gao(0,1,2,-k);
				gao(2,3,-1,-k);				
			}
		}
		if (ty==2) {
			ll ret=0;
			rep(j,0,4) {
				ll w=T[j][0].seek(l,r,1).sum+T[j][1].seek(l,r,1).sum;
				if (j==0||j==3) ret+=w;
				else ret-=w;
			}
			printf("%lld\n",ret);
		}
	}
}