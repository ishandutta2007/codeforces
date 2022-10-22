#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=5e4+5;
int n,a[MAXN];
struct node{
	ll s,s1,s2;
	bool mx;
}dat[MAXN<<2];
node operator +(node a,node b){
	return (node){a.s+b.s,min(a.s1,a.s+b.s1),min(b.s2,b.s+a.s2),a.mx||b.mx||(a.s2+b.s1<0)};
}
#define lc k<<1
#define rc k<<1|1
#define ls lc,l,mid
#define rs rc,mid+1,r
inline void pushup(int k){
	dat[k]=dat[lc]+dat[rc];
}
void Build(int k,int l,int r){
	if(l==r){
		dat[k]=(node){a[l],a[l],a[l],0};
		return ;
	}
	int mid=l+r>>1;
	Build(ls);
	Build(rs);
	pushup(k);
	return ;
}
node Query(int k,int l,int r,int x,int y){
	if(x<=l&&r<=y) return dat[k];
	int mid=l+r>>1;
	if(x<=mid&&mid<y) return Query(ls,x,y)+Query(rs,x,y);
	if(x<=mid) return Query(ls,x,y);
	return Query(rs,x,y);
}
int head,tail,que[MAXN];
int f[MAXN];
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			scanf("%d",a+i);
		int x;
		scanf("%d",&x);
		for(int i=1; i<=n; i++)
			a[i]-=x;
		Build(1,1,n);
		head=tail=0;
		for(int i=1,j=1; i<=n; i++){
			while(Query(1,1,n,j,i).mx) j++;
			while(head<tail&&que[head]<j) head++;
			if(head<tail) f[i]=f[max(que[head]-2,0)]-que[head]+i+1;
			else f[i]=f[max(i-2,0)]+1;
			while(head<tail&&f[que[tail-1]-2]-que[tail-1]<=f[max(i-2,0)]-i) tail--;
			que[tail++]=i;
		}
		printf("%d\n",f[n]);
	}
	return 0;
}