#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int inf=0x3f3f3f3f,maxa=5,maxn=2e5+10;
template<class T>inline void ckmax(T &x,const T &y){if(x<y)x=y;}
template<class T>inline void ckmin(T &x,const T &y){if(x>y)x=y;}
typedef int mat[maxa][maxa];
inline void mul1(mat x,mat y,mat z){
	memset(z,0x3f,sizeof(mat));
	for(ri i=0;i<maxa;++i)
		for(ri j=0;j<maxa;++j)
			for(ri k=0;k<maxa;++k)
				ckmin(z[i][j],x[i][k]+y[k][j]);	
}
inline void mul2(mat x,mat z){
	mat y;
	memcpy(y,x,sizeof(mat));
	memset(x,0x3f,sizeof(mat));
	for(ri i=0;i<maxa;++i)
		for(ri j=0;j<maxa;++j)
			ckmin(x[0][i],y[0][j]+z[j][i]);
}
inline void reset(mat x,char y){
	memset(x,0x3f,sizeof(mat));
	for(ri i=0;i<maxa;++i)x[i][i]=0;
	if(y=='2')x[0][0]=1,x[0][1]=0;
	if(y=='0')x[1][1]=1,x[1][2]=0;
	if(y=='1')x[2][2]=1,x[2][3]=0;
	if(y=='7')x[3][3]=1,x[3][4]=0;
	if(y=='6')x[3][3]=1,x[4][4]=1;
}
struct segment_tree{
	int l,r;
	mat v;
}t[maxn<<2];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
char s[maxn];
inline void push_up(int p){
	mul1(t[ls(p)].v,t[rs(p)].v,t[p].v);
}
void build(int p,int l,int r){
	t[p].l=l,t[p].r=r;
	if(l==r){
		reset(t[p].v,s[l]);
		return;
	}
	ri mid=l+r>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
	push_up(p);
}
mat ans;
void query(int p,int l,int r){
	if(l>t[p].r||t[p].l>r)return;
	if(l<=t[p].l&&t[p].r<=r){
		mul2(ans,t[p].v);
		return;
	}
	query(ls(p),l,r);
	query(rs(p),l,r);
}
int m,n;
int main(){
	scanf("%d%d%s",&n,&m,s+1);
	build(1,1,n);
	while(m--){
		ri l,r;
		scanf("%d%d",&l,&r);
		memset(ans,0x3f,sizeof ans);
		ans[0][0]=0;
		query(1,l,r);
		printf("%d\n",ans[0][4]==inf?-1:ans[0][4]);
	}
	return 0;
}