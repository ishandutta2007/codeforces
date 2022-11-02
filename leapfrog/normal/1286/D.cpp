//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
const int P=998244353;
struct mat
{
	int a[2][2];
	inline int* operator[](int w) {return a[w];}
	inline mat operator*(const mat &b)
	{
		mat rs;
		rs.a[0][0]=(1ll*a[0][0]*b.a[0][0]+1ll*a[0][1]*b.a[1][0])%P;
		rs.a[1][0]=(1ll*a[1][0]*b.a[0][0]+1ll*a[1][1]*b.a[1][0])%P;
		rs.a[0][1]=(1ll*a[0][0]*b.a[0][1]+1ll*a[0][1]*b.a[1][1])%P;
		rs.a[1][1]=(1ll*a[1][0]*b.a[0][1]+1ll*a[1][1]*b.a[1][1])%P;
		return rs;
	}
	mat() {a[0][0]=a[0][1]=a[1][0]=a[1][1]=0;}
}T[400005],a[100005];
struct query
{
	int ds,v,id,a,b;
	inline char operator<(const query &b) {return 1ll*ds*b.v<1ll*v*b.ds;}
}q[200005];int n,qt,X[100005],v[100005],p[100005];
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline void build(int x,int l,int r)
{
	if(l==r) return T[x]=a[l],void();
	build(x<<1,l,(l+r)>>1),build(x<<1|1,((l+r)>>1)+1,r),T[x]=T[x<<1]*T[x<<1|1];
}
inline void updat(int x,int l,int r,int dw)
{
	if(l==r) return T[x]=a[l],void();
	if(dw<=((l+r)>>1)) updat(x<<1,l,(l+r)>>1,dw),T[x]=T[x<<1]*T[x<<1|1];
	else updat(x<<1|1,((l+r)>>1)+1,r,dw),T[x]=T[x<<1]*T[x<<1|1];
}
int main()
{
	read(n);const int iv=ksm(100);int rs=0;
	for(int i=1;i<=n;i++) read(X[i]),read(v[i]),read(p[i]),p[i]=1ll*p[i]*iv%P;
	for(int i=1;i<=n;i++) a[i][0][0]=a[i][1][0]=(P+1-p[i])%P,a[i][0][1]=a[i][1][1]=p[i];
	build(1,1,n);for(int i=2;i<=n;i++) q[++qt]=(query){X[i]-X[i-1],v[i]+v[i-1],i,1,0};
	for(int i=2;i<=n;i++) if(v[i]<v[i-1]) q[++qt]=(query){X[i]-X[i-1],v[i-1]-v[i],i,1,1};
	for(int i=2;i<=n;i++) if(v[i]>v[i-1]) q[++qt]=(query){X[i]-X[i-1],v[i]-v[i-1],i,0,0};
	//for(int i=1;i<=qt;i++) printf("%d , %d , %d , %d , %d\n",q[i].ds,q[i].v,q[i].id,q[i].a,q[i].b);
	sort(q+1,q+qt+1);for(int i=1;i<=qt;i++)
	{
		mat a1,a2;a1=a[q[i].id],a2[q[i].a][q[i].b]=a1[q[i].a][q[i].b],a[q[i].id]=a2;
		updat(1,1,n,q[i].id);int vl=1ll*q[i].ds*ksm(q[i].v)%P;
		rs=(rs+1ll*vl*(T[1][0][0]+T[1][0][1]))%P,a1[q[i].a][q[i].b]=0,a[q[i].id]=a1,updat(1,1,n,q[i].id);
	}
	return printf("%d\n",rs),0;
}