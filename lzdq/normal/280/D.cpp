#include<cstdio>
#include<algorithm>
#include<cstring>
typedef long long ll;
using namespace std;
const int MAXN=1e5+5;
int n,q,a[MAXN];
#define lc k<<1
#define rc k<<1|1
#define ls lc,l,mid
#define rs rc,mid+1,r
struct Range{
	int l,r,s;
};
Range operator +(Range a,Range b){
	return (Range){a.l,b.r,a.s+b.s};
}
bool operator <(Range a,Range b){
	return a.s<b.s;
}
struct Node{
	Range s,mx,sl,sr;
}s1[MAXN<<2],s2[MAXN<<2];
Node operator +(Node a,Node b){
	return (Node){a.s+b.s,max(max(a.mx,b.mx),a.sr+b.sl),max(a.sl,a.s+b.sl),max(b.sr,a.sr+b.s)};
}
inline void pushup(int k){
	s1[k]=s1[lc]+s1[rc];
	s2[k]=s2[lc]+s2[rc];
}
void Build(int k,int l,int r){
	if(l==r){
		s1[k]=(Node){(Range){l,r,a[l]},(Range){l,r,a[l]},(Range){l,r,a[l]},(Range){l,r,a[l]}};
		s2[k]=(Node){(Range){l,r,-a[l]},(Range){l,r,-a[l]},(Range){l,r,-a[l]},(Range){l,r,-a[l]}};
		return ;
	}
	int mid=l+r>>1;
	Build(ls);
	Build(rs);
	pushup(k);
	return ;
}
void Modify(int k,int l,int r,int w){
	if(l==r){
		s1[k]=(Node){(Range){l,r,a[l]},(Range){l,r,a[l]},(Range){l,r,a[l]},(Range){l,r,a[l]}};
		s2[k]=(Node){(Range){l,r,-a[l]},(Range){l,r,-a[l]},(Range){l,r,-a[l]},(Range){l,r,-a[l]}};
		return ;
	}
	int mid=l+r>>1;
	if(w<=mid) Modify(ls,w);
	else Modify(rs,w);
	pushup(k);
	return ;
}
Node *qs;
Node Query(int k,int l,int r,int x,int y){
	if(x<=l&&r<=y) return qs[k];
	int mid=l+r>>1;
	if(x<=mid&&mid<y) return Query(ls,x,y)+Query(rs,x,y);
	if(x<=mid) return Query(ls,x,y);
	return Query(rs,x,y);
}
int ans;
int rg[100][2];
int main(){
	//freopen("in","r",stdin);
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d",a+i);
	Build(1,1,n);
	scanf("%d",&q);
	while(q--){
		int op,l,r,k;
		scanf("%d%d%d",&op,&l,&r);
		if(op==0){
			a[l]=r;
			Modify(1,1,n,l);
			continue;
		}
		scanf("%d",&k);
		qs=s1;
		Range t(Query(1,1,n,l,r).mx);
		if(t.s<=0){
			puts("0");
			continue;
		}
		ans=t.s;
		rg[1][0]=t.l;
		rg[1][1]=t.r;
		for(int m=1; m<k; m++){
			Range mx({0,0,-1});
			qs=s1;
			if(l<rg[1][0]) mx=max(mx,Query(1,1,n,l,rg[1][0]-1).mx);
			for(int i=1; i<m; i++)
				if(rg[i][1]+1<rg[i+1][0]) mx=max(mx,Query(1,1,n,rg[i][1]+1,rg[i+1][0]-1).mx);
			if(rg[m][1]<r) mx=max(mx,Query(1,1,n,rg[m][1]+1,r).mx);
			int tmp=mx.s;
			//printf("mx %d %d %d\n",mx.l,mx.r,mx.s);
			qs=s2;
			for(int i=1; i<=m; i++)
				mx=max(mx,Query(1,1,n,rg[i][0],rg[i][1]).mx);
			if(mx.s<=0) break;
			ans+=mx.s;
			if(mx.s==tmp){	// outside
				rg[m+1][0]=mx.l;
				rg[m+1][1]=mx.r;
			}else{	// inside
				int w=0;
				for(int i=1; i<=m; i++)
					if(rg[i][1]>=mx.r){
						w=i;
						break;
					}
				if(!w) puts("fuck");
				rg[m+1][0]=mx.r+1;
				rg[m+1][1]=rg[w][1];
				rg[w][1]=mx.l-1;
			}
			for(int i=m+1; i>1&&rg[i][0]<rg[i-1][0]; i--)
				swap(rg[i][0],rg[i-1][0]),swap(rg[i][1],rg[i-1][1]);
		}
		printf("%d\n",ans);
		//for(int i=1; i<=k; i++) printf("l %d r %d\n",rg[i][0],rg[i][1]);
	}
	return 0;
}