#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int K=2,M=1000000007,N=400020;
int n,m,a[N],i,j,k,l,r,x,opt;
struct Matrix{
	int x[K][K];
	friend Matrix operator+(Matrix A,Matrix B){
		int i,j;
		for(i=0;i<K;i++)
			for(j=0;j<K;j++)
				A.x[i][j]=(A.x[i][j]+B.x[i][j])%M;
		return A;
	}
	Matrix operator*(Matrix B){
		int i,j;
		Matrix t;
		for(i=0;i<K;i++)
			for(j=0;j<K;j++)
				t.x[i][j]=(1ll*x[i][0]*B.x[0][j]+1ll*x[i][1]*B.x[1][j])%M;
		return t;
	}
	bool operator==(Matrix B){
		int i,j;
		for(i=0;i<K;i++)
			for(j=0;j<K;j++)
				if(x[i][j]!=B.x[i][j])
					return 0;
		return 1;
	}
}F,O,T,D,A[N],tag[N],Ans;
Matrix Fib(int p){
	Matrix s=O;
	Matrix x=T;
	while(p){
		if(p&1)
			s=s*x;
		p>>=1;
		x=x*x;
	}
	return s;
}
void Pushup(int rt){
	A[rt]=A[rt<<1]+A[rt<<1|1];
}
void Change(int rt,Matrix Ta){
	tag[rt]=tag[rt]*Ta;
	A[rt]=A[rt]*Ta;
}
void Pushdown(int rt){
	if(!(tag[rt]==O)){
		Change(rt<<1,tag[rt]);
		Change(rt<<1|1,tag[rt]);
		tag[rt]=O;
	}
}
void Build(int rt,int l,int r){
	tag[rt]=O;
	if(l==r){
		A[rt]=F*Fib(a[l]-1);
		return;
	}
	int mid=l+r>>1;
	Build(rt<<1,l,mid);
	Build(rt<<1|1,mid+1,r);
	Pushup(rt);
}
void init(){
	F.x[0][1]=1;
	O.x[0][0]=1;
	O.x[1][1]=1;
	T.x[0][1]=1;
	T.x[1][0]=1;
	T.x[1][1]=1;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	Build(1,1,n);
}
void Update(int rt,int l,int r,int x,int y,Matrix z){
	if(x<=l&&r<=y){
		Change(rt,z);
		return;
	}
	Pushdown(rt);
	int mid=l+r>>1;
	if(x<=mid)
		Update(rt<<1,l,mid,x,y,z);
	if(y>mid)
		Update(rt<<1|1,mid+1,r,x,y,z);
	Pushup(rt);
}
void Query(int rt,int l,int r,int x,int y){
	if(x<=l&&r<=y){
		Ans=Ans+A[rt];
		return;
	}
	Pushdown(rt);
	int mid=l+r>>1;
	if(x<=mid)
		Query(rt<<1,l,mid,x,y);
	if(y>mid)
		Query(rt<<1|1,mid+1,r,x,y);
}
void work(){
	while(m--){
		scanf("%d",&opt);
		if(opt==1){
			scanf("%d%d%d",&l,&r,&x);
			Update(1,1,n,l,r,Fib(x));
		}
		else{
			scanf("%d%d",&l,&r);
			Ans=D;
			Query(1,1,n,l,r);
			printf("%d\n",Ans.x[0][1]);
		}
	}
	//while(1);
}
int main(){
	init();
	work();
	//while(1);
	return 0;
}