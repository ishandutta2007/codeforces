#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define mid ((l+r)>>1)
#define lowbit(x) (x&-x)
const int maxn=2e5+5,M=34005,mod=1e9+1;
inline int read(){
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1){x=-x;}return x;
}
inline void print(int x){
    static int a[55];int top=0;
    if(x<0) putchar('-'),x=-x;
    do{a[top++]=x%10,x/=10;}while(x);
    while(top) putchar(a[--top]+48);
}
int n,m,ls[maxn*102],rs[maxn*102],mn[maxn*102];
int tag[maxn*102],mx[maxn*102],x,y,ans,k,rt,tot=0;
void pushup(int rt){mn[rt]=min(mn[ls[rt]],mn[rs[rt]]);mx[rt]=max(mx[ls[rt]],mx[rs[rt]]);}
void pushx(int rt,int x){tag[rt]+=x;mx[rt]+=x;mn[rt]+=x;}
void push(int rt,int l,int r){
	if(!ls[rt])ls[rt]=++tot,mx[tot]=mid,mn[tot]=l;
	if(!rs[rt])rs[rt]=++tot,mx[tot]=r,mn[tot]=mid+1;
	pushx(ls[rt],tag[rt]);pushx(rs[rt],tag[rt]);tag[rt]=0;}
void change(int &rt,int l,int r,int num){
	if(!rt){rt=++tot,mx[rt]=r,mn[rt]=l;}
	if(mn[rt]>num){pushx(rt,-1);return;}
	if(mx[rt]<num){pushx(rt,1);return;}
	if(mn[rt]==mx[rt]){return;}push(rt,l,r);
	change(ls[rt],l,mid,num),change(rs[rt],mid+1,r,num);
	pushup(rt);
}
int query(int rt,int l,int r,int x){
	if(l>x||r<x)return 0;
	if(l==r){return mx[rt];}push(rt,l,r);
	return query(ls[rt],l,mid,x)+query(rs[rt],mid+1,r,x);
}
signed main(){
	//freopen("1.in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		x=read();k=read();
		change(rt,0,1e9,x);
		for(int j=1;j<=k;j++){
			x=(read()+ans)%mod;
			ans=query(1,0,1e9,x);
			printf("%d\n",ans);
		}
	}
 	return 0;
}