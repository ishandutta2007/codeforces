#include<cstdio>
#include<algorithm>
#include<cstring>
typedef long long ll;
using namespace std;
const int MAXN=1e5+5,INF=0x3fffffff;
int n,m,q;
char s[4][MAXN];
struct node{
	int a[2][2],sum[2][2];
	int* operator [](int x){
		return a[x];
	}
}pre[2][2];
struct SGT{
	int n,m;
	char *s0,*s1;
	node dat[MAXN<<2][2][2];
	bool tag[MAXN<<2][2];
#define lc k<<1
#define rc k<<1|1
#define ls lc,l,mid
#define rs rc,mid+1,r
	node Merge(node a,node b){
		static node c;
		for(int i=0; i<2; i++)
			for(int j=0; j<2; j++){
				c[i][j]=min(min(a[i][0]+b[0][j],a[i][1]+b[1][j]),min(a[i][0],a[i][1])+min(b[0][j],b[1][j])+m);
				c.sum[i][j]=a.sum[i][j]+b.sum[i][j];
			}
		return c;
	}
	inline void pushup(int k){
		for(int i=0; i<2; i++)
			for(int j=0; j<2; j++)
				dat[k][i][j]=Merge(dat[lc][i][j],dat[rc][i][j]);
	}
	void Build(int k,int l,int r){
		if(l==r){
			for(int i=0; i<2; i++)
				for(int j=0; j<2; j++)
					dat[k][i][j]=pre[s0[l]^i][s1[l]^j];
			return ;
		}
		int mid=l+r>>1;
		Build(ls);
		Build(rs);
		pushup(k);
		return ;
	}
	inline void rev(int k,int v){
		if(v==0){
			swap(dat[k][0][0],dat[k][1][0]);
			swap(dat[k][0][1],dat[k][1][1]);
		}else{
			swap(dat[k][0][0],dat[k][0][1]);
			swap(dat[k][1][0],dat[k][1][1]);
		}
		tag[k][v]^=1;
	}
	inline void pushdwn(int k){
		if(tag[k][0])
			rev(lc,0),rev(rc,0),tag[k][0]=0;
		if(tag[k][1])
			rev(lc,1),rev(rc,1),tag[k][1]=0;
	}
	void Modify(int k,int l,int r,int x,int y,int v){
		if(x<=l&&r<=y) return rev(k,v);
		pushdwn(k);
		int mid=l+r>>1;
		if(x<=mid) Modify(ls,x,y,v);
		if(mid<y) Modify(rs,x,y,v);
		pushup(k);
		return ;
	}
	void Init(){
		Build(1,1,n);
	}
}A,B;
int Ans(){
	int res=INF;
	node x=A.dat[1][0][0],y=B.dat[1][0][0];
	for(int i=0; i<2; i++)
		for(int j=0; j<2; j++){
			res=min(res,x[i][j]+y.sum[1][i]+y.sum[0][j]);
			res=min(res,y[i][j]+x.sum[0][i]+x.sum[1][j]);
		}
	return res;
}
int main(){
	for(int i=0; i<2; i++)
		for(int j=0; j<2; j++){
			pre[i][j][i][i]++;
			pre[i][j][j][j]++;
			pre[i][j][0][1]=pre[i][j][1][0]=INF;
			pre[i][j].sum[0][i]++;
			pre[i][j].sum[1][j]++;
		}
	scanf("%d%d%d",&n,&m,&q);
	for(int i=0; i<4; i++){
		scanf("%s",s[i]+1);
		for(int j=1; s[i][j]; j++)
			s[i][j]=(s[i][j]=='R');
	}
	A.s0=s[2];
	A.s1=s[3];
	B.s0=s[1];
	B.s1=s[0];
	A.n=m;
	A.m=n;
	B.n=n;
	B.m=m;
	A.Init();
	B.Init();
	printf("%d\n",Ans());
	while(q--){
		char op[5];
		int l,r;
		scanf("%s%d%d",op,&l,&r);
		if(op[0]=='L') B.Modify(1,1,n,l,r,1);
		if(op[0]=='R') B.Modify(1,1,n,l,r,0);
		if(op[0]=='U') A.Modify(1,1,m,l,r,0);
		if(op[0]=='D') A.Modify(1,1,m,l,r,1);
		printf("%d\n",Ans());
	}
	return 0;
}