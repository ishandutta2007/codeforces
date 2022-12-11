#include<bits/stdc++.h>
#ifdef memset0
	#define log(...) fprintf(stderr,__VA_ARGS__)
#else
	#define log(...) (void(0))
#endif
template<class T> inline void read(T &x){
	x=0; register char c=getchar(); register bool f=0;
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar(); if(f)x=-x;
}
const int N=1e5+10,mod=1e9+7;
int n,a[N],tmp[N],nxt[N],lst[N],jumpNxt[N][20],jumpLst[N][20];
struct z{
	int x;
	z(int x=0):x(x){}
	friend inline z operator*(z a,z b){return (long long)a.x*b.x%mod;}
	friend inline z operator-(z a,z b){return (a.x-=b.x)<0?a.x+mod:a.x;}
	friend inline z operator+(z a,z b){return (a.x+=b.x)>=mod?a.x-mod:a.x;}
}ans;
inline z fpow(z a,int b){z s=1;for(;b;b>>=1,a=a*a)if(b&1)s=s*a;return s;}
struct node{
	int l,r,mid;
	z sum[6],tagL,tagR;
}p[N<<2];
inline void pushup(int u,z l,z r){
	p[u].sum[0]=p[u].sum[0]+l*p[u].sum[2]+r*p[u].sum[1]+l*r*p[u].sum[5];
	p[u].sum[1]=p[u].sum[1]+l*p[u].sum[5];
	p[u].sum[2]=p[u].sum[2]+r*p[u].sum[5];
	p[u].sum[3]=p[u].sum[3]+r*p[u].sum[4];
	p[u].tagL=p[u].tagL+l;
	p[u].tagR=p[u].tagR+r;
}
inline void pushdown(int u){
	if(p[u].tagL.x||p[u].tagR.x){
		pushup(u<<1,p[u].tagL,p[u].tagR);
		pushup(u<<1|1,p[u].tagL,p[u].tagR);
		p[u].tagL=p[u].tagR=0;
	}
}
inline void maintain(int u){
	for(int i=0;i<4;i++)p[u].sum[i]=p[u<<1].sum[i]+p[u<<1|1].sum[i];
}
void build(int u,int l,int r){
	p[u].l=l,p[u].r=r,p[u].mid=(l+r)>>1;
	if(l==r){
		p[u].sum[4]=l;
		p[u].sum[5]=1;
		return;
	}
	build(u<<1,l,p[u].mid);
	build(u<<1|1,p[u].mid+1,r);	
	maintain(u);
	for(int i=4;i<6;i++)p[u].sum[i]=p[u<<1].sum[i]+p[u<<1|1].sum[i];
}
void modifyL(int u,int l,int r,z x){
	if(u==1)log("modifyL[%d,%d]<%d\n",l,r,x.x);
	// if(p[u].l==p[u].r){
	if(p[u].l==l&&p[u].r==r){
		pushup(u,x,0);
		return;
	}
	pushdown(u);
	if(r<=p[u].mid)modifyL(u<<1,l,r,x);
	else if(l>p[u].mid)modifyL(u<<1|1,l,r,x);
	else modifyL(u<<1,l,p[u].mid,x),modifyL(u<<1|1,p[u].mid+1,r,x);
	maintain(u);
}
void modifyR(int u,int l,int r,z x){
	if(u==1)log("modifyR[%d,%d]<%d\n",l,r,x.x);
	// if(p[u].l==p[u].r){
	if(p[u].l==l&&p[u].r==r){
		pushup(u,0,x);
		return;
	}
	pushdown(u);
	if(r<=p[u].mid)modifyR(u<<1,l,r,x);
	else if(l>p[u].mid)modifyR(u<<1|1,l,r,x);
	else modifyR(u<<1,l,p[u].mid,x),modifyR(u<<1|1,p[u].mid+1,r,x);
	maintain(u);
}
z query(int u,int l,int r,z at){
	if(u==1)log("query[%d,%d]\n",l,r);
	if(p[u].l==l&&p[u].r==r)return z(0)-p[u].sum[0]+p[u].sum[1]*at+p[u].sum[3]-p[u].sum[4]*at;
	pushdown(u);
	if(r<=p[u].mid)return query(u<<1,l,r,at);
	if(l>p[u].mid)return query(u<<1|1,l,r,at);
	return query(u<<1,l,p[u].mid,at)+query(u<<1|1,p[u].mid+1,r,at);
}
struct status{
	int l,r,v;
};
std::vector<status> L,R;
int main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	read(n);
	for(int i=1;i<=n;i++)read(a[i]),tmp[++*tmp]=a[i];
	std::sort(tmp+1,tmp+*tmp+1);
	*tmp=std::unique(tmp+1,tmp+*tmp+1)-tmp-1;
	for(int i=1;i<=n;i++)a[i]=std::lower_bound(tmp+1,tmp+*tmp+1,a[i])-tmp;
	for(int i=1;i<=*tmp;i++)tmp[i]=0;
	for(int i=1;i<=n;i++)lst[i]=tmp[a[i]],tmp[a[i]]=i;
	for(int i=1;i<=*tmp;i++)tmp[i]=n+1;
	for(int i=n;i>=1;i--)nxt[i]=tmp[a[i]],tmp[a[i]]=i;
	lst[0]=n+1,nxt[0]=0;
	for(int i=1;i<=n;i++){
		jumpLst[i][0]=lst[i-1];
		jumpNxt[i][0]=nxt[i-1];
	}
	for(int i=1;i<20;i++)
		for(int j=1;j<=n;j++)if((j-(1<<(i-1)))>0){
			jumpLst[j][i]=std::max(jumpLst[j][i-1],jumpLst[j-(1<<(i-1))][i-1]);
			jumpNxt[j][i]=std::min(jumpNxt[j][i-1],jumpNxt[j-(1<<(i-1))][i-1]);
		}else{
			jumpLst[j][i]=n+1;
			jumpNxt[j][i]=0;
		}
	for(int i=1;i<=n;i++)log("%d%c",lst[i]," \n"[i==n]);
	for(int i=1;i<=n;i++)log("%d%c",nxt[i]," \n"[i==n]);
	status a,b;
	build(1,1,n);
	for(int i=1;i<=n;i++){
		L.push_back({i,i,lst[i]}),modifyL(1,i,i,lst[i]+1); //max
		R.push_back({i,i,nxt[i]}),modifyR(1,i,i,nxt[i]-1); //min
		while(L.size()>1&&(a=L[L.size()-2]).v<=(b=L[L.size()-1]).v){
			if(a.v!=b.v)modifyL(1,a.l,a.r,z(b.v)-a.v);
			L.pop_back(),L.pop_back(),L.push_back({a.l,b.r,b.v});
		}
		while(R.size()>1&&(a=R[R.size()-2]).v>=(b=R[R.size()-1]).v){
			if(a.v!=b.v)modifyR(1,a.l,a.r,z(b.v)-a.v);
			R.pop_back(),R.pop_back(),R.push_back({a.l,b.r,b.v});
		}
		// printf("===%d===\n",i);
		// for(auto x:L)printf("%d,%d,%d  ",x.l,x.r,x.v); putchar('\n');
		// for(auto x:R)printf("%d,%d,%d  ",x.l,x.r,x.v); putchar('\n');
		int j=i,Lst=lst[i],Nxt=nxt[i];
		for(int k=19;k>=0;k--){
			// printf("j=%d k=%d %d %d | %d %d\n",j,k,jumpLst[j][k],jumpNxt[j][k],std::max(jumpLst[j][k],Lst)<(j-(1<<k)),std::min(jumpNxt[j][k],Nxt));
			if(std::max(jumpLst[j][k],Lst)<(j-(1<<k))&&std::min(jumpNxt[j][k],Nxt)>i){
				Lst=std::max(jumpLst[j][k],Lst);
				Nxt=std::min(jumpNxt[j][k],Nxt);
				j-=1<<k;
			}
		}
		ans=ans+query(1,j,i,i);
	}
	printf("%d\n",ans.x);
}