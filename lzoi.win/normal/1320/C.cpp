#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=2e5+5,INF=0x7fffffff;
int n,m,p;
struct node{
	int a,c;
	node(int x=0){
		a=x,c=0;
	}
}wp[MAXN],ar[MAXN];
bool operator <(node a,node b){
	return a.a<b.a;
}
struct node2{
	int x,y,z;
}mon[MAXN];
bool operator <(node2 a,node2 b){
	return a.x<b.x;
}
int ans=-INF;
#define lc k<<1
#define rc k<<1|1
#define ls lc,l,mid
#define rs rc,mid+1,r
int mx[MAXN<<2],tag[MAXN<<2];
inline void add(int k,int v){
	mx[k]+=v;
	tag[k]+=v;
}
inline void pushup(int k){
	mx[k]=max(mx[lc],mx[rc]);
}
inline void pushdwn(int k){
	add(lc,tag[k]);
	add(rc,tag[k]);
	tag[k]=0;
}
void Build(int k,int l,int r){
	if(l==r){
		mx[k]=-ar[l].c;
		return ;
	}
	int mid=l+r>>1;
	Build(ls);
	Build(rs);
	pushup(k);
	return ;
}
void Modify(int k,int l,int r,int qx,int qy,int qv){
	if(qx<=l&&r<=qy) return add(k,qv);
	pushdwn(k);
	int mid=l+r>>1;
	if(qx<=mid) Modify(ls,qx,qy,qv);
	if(mid<qy) Modify(rs,qx,qy,qv);
	pushup(k);
	return ;
}
int main(){
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1; i<=n; i++)
		scanf("%d%d",&wp[i].a,&wp[i].c);
	for(int i=1; i<=m; i++)
		scanf("%d%d",&ar[i].a,&ar[i].c);
	sort(wp+1,wp+n+1);
	sort(ar+1,ar+m+1);
	for(int i=1; i<=p; i++)
		scanf("%d%d%d",&mon[i].x,&mon[i].y,&mon[i].z);
	sort(mon+1,mon+p+1);
	Build(1,1,m);
	for(int i=1,s1=0; i<=n; i++){
		while(s1<p&&mon[s1+1].x<wp[i].a){
			s1++;
			int w=upper_bound(ar+1,ar+m+1,node(mon[s1].y))-ar;
			if(w<=m) Modify(1,1,m,w,m,mon[s1].z);
		}
		ans=max(ans,mx[1]-wp[i].c);
	}
	printf("%d\n",ans);
	return 0;
}