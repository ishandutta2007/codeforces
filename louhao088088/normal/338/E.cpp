// LUOGU_RID: 90783634
#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid ((l+r)>>1)
#define lowbit(x) (x&-x)
const int maxn=2e5+5,M=2e5+5,mod=998244353;
inline int read(){
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1){x=-x;}return x;
}
void print(int x){
    static int a[55];int top=0;
    if(x<0) putchar('-'),x=-x;
    do{a[top++]=x%10,x/=10;}while(x);
    while(top) putchar(a[--top]+48);
}
int n,m,x,y,z,mx[maxn*4],tag[maxn*4],a[maxn],b[maxn],res=0,h;
void pushx(int rt,int x){mx[rt]+=x;tag[rt]+=x;}
void push(int rt){if(tag[rt]){pushx(ls,tag[rt]),pushx(rs,tag[rt]);}tag[rt]=0;}
void build(int rt,int l,int r){
	if(l==r){mx[rt]=m-l+1;return;}
	build(ls,l,mid),build(rs,mid+1,r);
	mx[rt]=max(mx[ls],mx[rs]);
}
void add(int rt,int l,int r,int L,int R,int x){
	if(l>R||r<L)return ;
	if(l>=L&&r<=R){pushx(rt,x);return;}push(rt);
	add(ls,l,mid,L,R,x),add(rs,mid+1,r,L,R,x);
	mx[rt]=max(mx[ls],mx[rs]);
}
signed main(){
	//freopen("1.in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read(),h=read();
	for(int i=1;i<=m;i++)b[i]=h-read();
	sort(b+1,b+m+1);
	for(int i=1;i<=n;i++)a[i]=read(),a[i]=upper_bound(b+1,b+m+1,a[i])-b-1;
	build(1,1,m);
	for(int i=1;i<=m;i++)add(1,1,m,1,a[i],-1);
	if(mx[1]<=0)res++;
	for(int i=m+1;i<=n;i++){
		add(1,1,m,1,a[i-m],1);
		add(1,1,m,1,a[i],-1);
		if(mx[1]<=0)res++;
	//	cout<<mx[1]<<" "<<a[i]<<endl;
	}cout<<res<<endl;
 	return 0;
}