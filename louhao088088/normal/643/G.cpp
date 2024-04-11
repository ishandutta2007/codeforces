#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ls (x<<1)
#define rs (x<<1|1)
#define mid ((l+r)>>1)
#define lowbit(x) (x&-x)
const int maxn=2e5+5,M=34005;
inline int read(){
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
inline void print(int x){
    static int a[55];int top=0;
    if(x<0) putchar('-'),x=-x;
    do{a[top++]=x%10,x/=10;}while(x);
    while(top) putchar(a[--top]+48);
}
int n,m,q,a[maxn],x,l,r,op,k,p,tag[maxn*4];
struct node{
	pi a[7];
}sum[maxn*4];
void print(node a){
	for(int i=1;i<=k;i++)cout<<a.a[i].fi<<" "<<a.a[i].se<<endl;
	puts("");
}bool cmp(pi a,pi b){if(a.se==b.se)return a.fi<b.fi;return a.se>b.se;}
node add(node x,node y){
	for(int i=k;i>=1;i--){
		if(!x.a[i].fi)continue;int F=0;
		for(int j=1;j<=k;j++)
			if(x.a[i].fi==y.a[j].fi){F=1;y.a[j].se+=x.a[i].se;break;}
		if(!F){
			if(y.a[k].se<x.a[i].se){swap(y.a[k],x.a[i]);}
			for(int j=1;j<=k;j++)y.a[j].se-=x.a[i].se;
		}
		sort(y.a+1,y.a+k+1,cmp);
	}return y;
}
void pushup(int x){sum[x]=add(sum[ls],sum[rs]);}
void pushx(int x,int num,int s){tag[x]=num;for(int i=1;i<=k;i++)sum[x].a[i]=mp(0,0);sum[x].a[1]=mp(num,s);}
void push(int x,int l,int r){if(tag[x]){pushx(ls,tag[x],mid-l+1),pushx(rs,tag[x],r-mid);tag[x]=0;}}
void change(int x,int l,int r,int L,int R,int num){
	if(l>R||r<L)return;
	if(l>=L&&r<=R){pushx(x,num,r-l+1);return;}push(x,l,r);
	change(ls,l,mid,L,R,num),change(rs,mid+1,r,L,R,num);pushup(x);
}
node query(int x,int l,int r,int L,int R){
	if(l>=L&&r<=R)return sum[x];push(x,l,r);
	if(L>mid)return query(rs,mid+1,r,L,R);
	if(mid>=R)return query(ls,l,mid,L,R);
	return add(query(ls,l,mid,L,R),query(rs,mid+1,r,L,R));
}
void build(int x,int l,int r){
	if(l==r){sum[x].a[1]=mp(a[l],1);return;}
	build(ls,l,mid),build(rs,mid+1,r);pushup(x);
}
signed main(){
	//freopen("1.in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read(),p=read();k=100/p;
	for(int i=1;i<=n;i++)a[i]=read();build(1,1,n);
	for(int i=1;i<=m;i++){
		op=read();l=read(),r=read();
		if(op==1)x=read(),change(1,1,n,l,r,x);
		else {
			node p=query(1,1,n,l,r);
		//	print(p);
			printf("%d ",k);
			
			for(int i=1;i<=k;i++){
				if(p.a[i].fi)printf("%d ",p.a[i].fi);
				else printf("100 ");
			}puts("");
		}
	}
 	return 0;
}