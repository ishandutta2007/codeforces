#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=2e5+5;
typedef long long ll;
const ll INF=1ll<<62;
int n,p[MAXN],a[MAXN],q[MAXN];
ll b[MAXN];
#define lc k<<1
#define rc k<<1|1
#define ls lc,l,mid
#define rs rc,mid+1,r
ll tag[MAXN<<2],mi[MAXN<<2];
ll ans=INF;
inline void add(int k,ll v){
	mi[k]+=v;
	tag[k]+=v;
}
inline void pushdwn(int k){
	add(lc,tag[k]);
	add(rc,tag[k]);
	tag[k]=0;
}
inline void pushup(int k){
	mi[k]=min(mi[lc],mi[rc]);
}
void Build(int k,int l,int r){
	if(l==r){
		mi[k]=-b[l];
		return ;
	}
	int mid=l+r>>1;
	Build(ls);
	Build(rs);
	pushup(k);
	return ;
}
void Modify(int k,int l,int r,int qx,int qy,ll qv){
	if(qx<=l&&r<=qy) return add(k,qv);
	pushdwn(k);
	int mid=l+r>>1;
	if(qx<=mid) Modify(ls,qx,qy,qv);
	if(mid<qy) Modify(rs,qx,qy,qv);
	pushup(k);
	return ;
}
ll Query(int k,int l,int r,int qx,int qy){
	if(qx<=l&&r<=qy) return mi[k];
	pushdwn(k);
	int mid=l+r>>1;
	ll res=INF;
	if(qx<=mid) res=min(res,Query(ls,qx,qy));
	if(mid<qy) res=min(res,Query(rs,qx,qy));
	return res;
}
int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d",p+i),q[p[i]]=i;
	for(int i=1; i<=n; i++)
		scanf("%d",a+i);
	for(int i=n;i;i--)
		b[i]=b[i+1]+a[i];
	ll uns=b[1];
	Build(1,1,n);
	ans=uns+Query(1,1,n,2,n);
	for(int i=1; i<=n; i++){
		uns-=a[q[i]];
		Modify(1,1,n,1,q[i],2ll*a[q[i]]);
		ans=min(ans,uns+Query(1,1,n,2,n));
		//printf("i %d %I64d\n",i,ans);
	}
	printf("%I64d\n",ans);
	return 0;
}