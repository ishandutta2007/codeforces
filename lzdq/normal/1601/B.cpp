#include<cstdio>
#include<algorithm>
#include<cstring>
typedef long long ll;
using namespace std;
const int MAXN=3e5+5,INF=0x3fffffff;
typedef pair<int,int> pr;
#define mkp make_pair
int n,a[MAXN],b[MAXN];
#define lc k<<1
#define rc k<<1|1
#define ls lc,l,mid
#define rs rc,mid+1,r
pr mi[MAXN<<2],f[MAXN];
int g[MAXN];
void Build(int k,int l,int r){
	mi[k]=(l==n?mkp(0,0):mkp(INF,INF));
	if(l==r) return ;
	int mid=l+r>>1;
	Build(ls);
	Build(rs);
	return ;
}
void Modify(int k,int l,int r,int x,int y,pr p){
	if(x<=l&&r<=y){
		mi[k]=min(mi[k],p);
		return ;
	}
	int mid=l+r>>1;
	if(x<=mid) Modify(ls,x,y,p);
	if(mid<y) Modify(rs,x,y,p);
	return ;
}
pr Query(int k,int l,int r,int x){
	if(l==r) return mi[k];
	int mid=l+r>>1;
	pr res=mi[k];
	if(x<=mid) res=min(res,Query(ls,x));
	else res=min(res,Query(rs,x));
	return res;
}
void Print(int u){
	if(u>=n) return ;
	Print(f[u].second);
	printf("%d ",u);
	return ;
}
int main(){
	//freopen("in1.txt","r",stdin);
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d",a+i);
	for(int i=1; i<=n; i++)
		scanf("%d",b+i),g[i]=INF;
	Build(1,0,n);
	for(int i=n; i; i--){
		f[i]=Query(1,0,n,i);
		int x=i+b[i];
		if(g[x]>f[i].first+1)
			Modify(1,0,n,x-a[x],x,mkp(g[x]=f[i].first+1,i));
		//printf("%d first %d second %d\n",i,f[i].first,f[i].second);
	}
	f[0]=Query(1,0,n,0);
	if(f[0].first>=INF) return puts("-1"),0;
	printf("%d\n",f[0].first);
	Print(0);
	puts("");
	return 0;
}