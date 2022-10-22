#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
int n,m,a[MAXN];
struct node{
	int l,r;
};
vector<node> vec[MAXN];
int d[MAXN];
ll ans;
#define lc k<<1
#define rc k<<1|1
#define ls lc,l,mid
#define rs rc,mid+1,r
int s[MAXN<<2][2],tag[MAXN<<2];
void Build(int k,int l,int r){
	s[k][0]=r-l+1;
	if(l==r) return ;
	int mid=l+r>>1;
	Build(ls);
	Build(rs);
	return ;
}
inline void pushup(int k){
	s[k][0]=s[lc][0]+s[rc][0];
	s[k][1]=s[lc][1]+s[rc][1];
}
inline void Rev(int k){
	swap(s[k][0],s[k][1]);
	tag[k]^=1;
}
inline void pushdwn(int k){
	if(tag[k]){
		Rev(lc);
		Rev(rc);
		tag[k]=0;
	}
}
void Modify(int k,int l,int r,int x,int y){
	if(x<=l&&r<=y) return Rev(k);
	pushdwn(k);
	int mid=l+r>>1;
	if(x<=mid) Modify(ls,x,y);
	if(mid<y) Modify(rs,x,y);
	pushup(k);
	return ;
}
int Query(int k,int l,int r,int x,int y,int v){
	if(x<=l&&r<=y) return s[k][v];
	pushdwn(k);
	int mid=l+r>>1,res=0;
	if(x<=mid) res+=Query(ls,x,y,v);
	if(mid<y) res+=Query(rs,x,y,v);
	return res;
}
int main(){
	//freopen("in","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
	while(m--){
		int x,y;
		scanf("%d%d",&x,&y);
		x=lower_bound(a+1,a+n+1,x)-a;
		y=upper_bound(a+1,a+n+1,y)-a-1;
		if(x>y) continue;
		vec[x].push_back((node){x,y});
		vec[y+1].push_back((node){x,y});
	}
	Build(1,1,n);
	ans=n*(n-1ll)*(n-2)/6;
	for(int i=1; i<=n; i++){
		for(node j:vec[i])
			Modify(1,1,n,j.l,j.r);
		if(i>1) d[i]+=Query(1,1,n,1,i-1,0);
		if(i<n) d[i]+=Query(1,1,n,i+1,n,1);
		//printf("d %d\n",d[i]);
		ans-=d[i]*(d[i]-1ll)/2;
	}
	printf("%lld\n",ans);
	return 0;
}