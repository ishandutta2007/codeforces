#include<bits/stdc++.h>
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
using namespace std;
int const N=333333,MOD=777777777;
int n,q,a[3][3];
void add(int&x,int y){
	if((x+=y)>=MOD)x-=MOD;
}
struct matrix{
	static int const N=3;
	int v[N][N];
	matrix(int x=-2){
		memset(v,0,sizeof v);
		for(int i=0;i<N;i++)
			v[i][i]=x==-1||i==x;
	}
	int*operator[](int x){
		return v[x];
	}
	const int*operator[](int x)const{
		return v[x];
	}
	matrix operator*(const matrix&rhs)const{
		matrix res;
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				for(int x=0;x<N;x++)
					for(int y=0;y<N;y++)
						add(res[i][j],1ll*a[y][x]*v[i][y]*rhs[x][j]%MOD);
		return res;
	}
	int sum(){
		int res=0;
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				add(res,v[i][j]);
		return res;
	}
};
matrix tr[N];
void update(int x){
	tr[x]=tr[ls(x)]*tr[rs(x)];
}
void build(int x,int l,int r){
	if(l==r)
		return tr[x]=matrix(-1),void();
	int mid=(l+r)>>1;
	build(ls(x),l,mid);
	build(rs(x),mid+1,r);
	update(x);
}
void modify(int x,int l,int r,int p,int w){
	if(l==r)
		return tr[x]=matrix(w),void();
	int mid=(l+r)>>1;
	if(p<=mid)
		modify(ls(x),l,mid,p,w);
	else
		modify(rs(x),mid+1,r,p,w);
	update(x);
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>q;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			cin>>a[i][j];
	build(1,1,n);
	for(int v,t;q--;)
		cin>>v>>t,modify(1,1,n,v,t-1),cout<<tr[1].sum()<<"\n";
}