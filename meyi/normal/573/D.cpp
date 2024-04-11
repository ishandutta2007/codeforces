#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxa=3,maxn=3e4+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
template<class T>inline void ckmax(T &x,const T &y){if(x<y)x=y;}
template<class T>inline void ckmin(T &x,const T &y){if(x>y)x=y;}
typedef ll mat[maxa][maxa];
inline void mul1(mat x,mat y,mat z){
	memset(z,-0x3f,sizeof(mat));
	for(ri i=0;i<maxa;++i)
		for(ri j=0;j<maxa;++j)
			for(ri k=0;k<maxa;++k)
				ckmax(z[i][j],x[i][k]+y[k][j]);	
}
inline void mul2(mat x,mat z){
	mat y;
	memcpy(y,x,sizeof(mat));
	memset(x,-0x3f,sizeof(mat));
	for(ri i=0;i<maxa;++i)
		for(ri j=0;j<maxa;++j)
			ckmax(x[0][i],y[0][j]+z[j][i]);
}
ll a[maxn],b[maxn];
int ban[maxn],id1[maxn],id2[maxn],rk1[maxn],rk2[maxn];
inline ll calc(vector<int>pos){
	ll ret=-inf;
	vector<int>tmp=pos;
	do{
		ll sum=0;
		for(ri i=0;i<pos.size();++i){
			if(ban[id1[pos[i]]]==id2[tmp[i]])goto skip;
			else sum+=a[id1[pos[i]]]*b[id2[tmp[i]]];
		}
		ckmax(ret,sum);
		skip:;
	}while(next_permutation(tmp.begin(),tmp.end()));
	return ret;
}
inline void reset(mat x,int pos){
	memset(x,-0x3f,sizeof(mat));
	if(pos>2)x[0][2]=calc({pos-2,pos-1,pos});
	x[1][0]=0;
	if(pos>1)x[1][2]=calc({pos-1,pos});
	x[2][1]=0;
	x[2][2]=calc({pos});
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
		reset(t[p].v,l);
		return;
	}
	ri mid=l+r>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
	push_up(p);
}
void modify(int p,int k){
	if(k<t[p].l||k>t[p].r)return;
	if(t[p].l==t[p].r){
		reset(t[p].v,k);
		return;
	}
	modify(ls(p),k);
	modify(rs(p),k);
	push_up(p);
}
mat ans;
int m,n;
signed main(){
	scanf("%d%d",&n,&m);
	for(ri i=1;i<=n;++i)scanf("%lld",a+i),ban[i]=id1[i]=i;
	sort(id1+1,id1+n+1,[&](const int &x,const int &y){return a[x]>a[y];});
	for(ri i=1;i<=n;++i)scanf("%lld",b+i),id2[i]=i;
	sort(id2+1,id2+n+1,[&](const int &x,const int &y){return b[x]>b[y];});
	build(1,1,n);
	for(ri i=1;i<=n;++i)rk1[id1[i]]=rk2[id2[i]]=i;
	while(m--){
		ri x,y;
		scanf("%d%d",&x,&y);
		swap(ban[x],ban[y]);
		for(ri i=rk1[x];i<=min(rk1[x]+2,n);++i)modify(1,i);
		for(ri i=rk1[y];i<=min(rk1[y]+2,n);++i)modify(1,i);
		memset(ans,-0x3f,sizeof ans);
		ans[0][2]=0;
		mul2(ans,t[1].v);
		printf("%lld\n",ans[0][2]);
	}
	return 0;
}