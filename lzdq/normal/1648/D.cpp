#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
#define mkp make_pair
const int MAXN=5e5+5;
const ll INF=1ll<<60;
int n,q,a[MAXN][3];
ll s1[MAXN],s2[MAXN],s3[MAXN],f[MAXN];
vector<pr> b[MAXN];
ll mx1[MAXN],mx2[MAXN];
inline void add(ll *a,int x,ll y){
	for(int i=x; i; i&=i-1)
		a[i]=max(a[i],y);
}
inline ll query(ll *a,int x){
	ll res=-INF;
	if(!x) x++;
	for(int i=x; i<=n; i+=i&-i)
		res=max(res,a[i]);
	return res;
}
struct Matrix{
	ll a[3][3];
	ll* operator [](int x){
		return a[x];
	}
};
struct node{
	Matrix a;
	ll b,mx;
}val[MAXN<<2];
#define lc k<<1
#define rc k<<1|1
#define ls lc,l,mid
#define rs rc,mid+1,r
Matrix operator *(Matrix a,Matrix b){
	static Matrix c;
	for(int i=0; i<3; i++)
		for(int j=i; j<3; j++){
			c[i][j]=-INF;
			for(int k=i; k<=j; k++)
				c[i][j]=max(c[i][j],a[i][k]+b[k][j]);
		}
	return c;
}
node operator +(node x,node y){
	return node{
		x.a*y.a, max(x.b+y.a[1][1],y.b), max(max(x.mx+y.a[2][2],y.mx),x.b+y.a[1][2])
	};
}
inline void pushup(int k){
	val[k]=val[lc]+val[rc];
}
void Build(int k,int l,int r){
	if(l==r){
		for(int i=0; i<3; i++){
			ll s=0;
			for(int j=i; j<3; j++){
				s+=a[l][j];
				val[k].a[i][j]=s;
			}
		}
		val[k].b=f[l-1]+a[l][1];
		val[k].mx=f[l-1]+a[l][1]+a[l][2];
		return ;
	}
	int mid=l+r>>1;
	Build(ls);
	Build(rs);
	pushup(k);
	return ;
}
node Query(int k,int l,int r,int x,int y){
	if(x<=l&&r<=y) return val[k];
	int mid=l+r>>1;
	if(x<=mid&&mid<y) return Query(ls,x,y)+Query(rs,x,y);
	if(x<=mid) return Query(ls,x,y);
	return Query(rs,x,y);
}
ll ans=-INF;
int main(){
	//freopen("in2.txt","r",stdin);
	scanf("%d%d",&n,&q);
	for(int i=0; i<3; i++)
		for(int j=1; j<=n; j++)
			scanf("%d",a[j]+i);
	while(q--){
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		b[r].push_back(mkp(l,k));
	}
	memset(mx1,0xc0,sizeof(mx1));
	memset(mx2,0xc0,sizeof(mx2));
	for(int i=1; i<=n; i++){
		s1[i]=s1[i-1]+a[i][0];
		s2[i]=s2[i-1]+a[i][1];
	}
	for(int i=n; i; i--)
		s3[i]=s3[i+1]+a[i][2];
	memset(f,0xc0,sizeof(f));
	for(int i=1; i<=n; i++){
		add(mx1,i,s1[i]-s2[i-1]);
		for(pr j:b[i]){
			int l=j.first,k=j.second;
			f[i]=max(f[i],max(query(mx1,l),query(mx2,l-1))+s2[i]-k);
		}
		if(f[i]>-INF) add(mx2,i,f[i]-s2[i]);
	}
	Build(1,1,n);
	for(int i=1; i<=n; i++)
		for(pr j:b[i]){
			int l=j.first,k=j.second;
			node t(Query(1,1,n,l,i));
			ans=max(ans,max(t.mx,t.a[0][2]+s1[l-1])+s3[i+1]-k);
		}
	printf("%lld\n",ans);
	return 0;
}