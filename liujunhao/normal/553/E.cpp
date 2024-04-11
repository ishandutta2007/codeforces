#include<cstdio>
#include<algorithm>
#include<iostream> 
#include<iomanip>
#include<cmath>
#define INF 0x3fffffff
#define MAXT 20000
#define MAXN 50
#define MAXM 100
const double pi=acos(-1);
using namespace std;
void Read(int &x){
	char c;
	while(c=getchar(),c!=EOF){
		if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			return;
		}
	}
}
struct cpx{
	double r,i;
	inline cpx(){
	}
	inline cpx(double r,double i):r(r),i(i){
	}
	inline cpx operator+(const cpx &b)const{
		return cpx(r+b.r,i+b.i);
	}
	inline cpx operator-(const cpx &b)const{
		return cpx(r-b.r,i-b.i);
	}
	inline cpx operator*(const cpx &b)const{
		return cpx(r*b.r-i*b.i,r*b.i+i*b.r);
	}
	inline cpx& operator*=(const cpx &b){
		return *this=*this*b;
	}
	inline cpx conj()const{
		return cpx(r,-i);
	}
}A[MAXT*4+10],B[MAXT*4+10],T[MAXT*4+10];
void fft(cpx *a,int N,int f){
	int i,j,k,t;
	for(i=1,j=0;i<N-1;i++){
		for(t=N;j^=t>>=1,~j&t;);
		if(i<j)
			swap(a[i],a[j]);
	}
	for(i=1;i<N;i<<=1){
		cpx wn(cos(pi/i),f*sin(pi/i));
		t=i<<1;
		for(j=0;j<N;j+=t){
			cpx w(1,0);
			for(k=0;k<i;k++,w*=wn){
				cpx x(a[j+k]),y(w*a[j+k+i]);
				a[j+k]=x+y,a[j+k+i]=x-y;
			}
		}
	}
	if(f==-1){
		for(i=0;i<N;i++)
			a[i].r/=N;
	}
}
void mul(cpx *a,cpx *b,cpx *c,int N){
	/*int i,j;
	for(i=0;i<N;i++)
		T[i]=cpx(a[i].r,b[i].r);
	fft(T,N,1);
	for(i=0;i<N;i++){
		j=(N-i)&(N-1);
		c[i]=(T[i]*T[i]-(T[j]*T[j]).conj())*cpx(0,-0.25);
	}
	fft(c,N,-1);*/
	fft(a,N,1);
	fft(b,N,1);
	for(int i=0;i<N;i++)
		c[i]=a[i]*b[i];
	fft(c,N,-1);
}
int n,m,t,x,p[MAXM+10][MAXT+10],dist[MAXN+10],psum[MAXM+10][MAXT+10];
double f[MAXN+10][MAXT+10],s[MAXM+10][MAXT+10];
struct Edge{
	int u,v,wt;
	inline Edge(){
	}
	inline Edge(int u,int v,int wt):u(u),v(v),wt(wt){
	}
}eset[MAXM+10];
void read(){
	Read(n),Read(m),Read(t),Read(x);
	int u,v,c,i,j;
	for(i=1;i<=m;i++){
		Read(u),Read(v),Read(c);
		eset[i]=Edge(u,v,c);
		for(j=1;j<=t;j++)
			Read(p[i][j]);
		for(j=t;j;j--)
			psum[i][j]=psum[i][j+1]+p[i][j];
	}
}
void Bellman_ford(){
	int i,j;
	for(i=1;i<n;i++)
		dist[i]=INF;
	for(j=1;j<=n;j++)
		for(i=1;i<=m;i++)
			if(dist[eset[i].u]>dist[eset[i].v]+eset[i].wt)
				dist[eset[i].u]=dist[eset[i].v]+eset[i].wt;
	for(i=1;i<n;i++){
		for(j=0;j<=t;j++)
			f[i][j]=dist[i]+x;
	}
	for(i=1;i<=m;i++){
		for(j=0;j<=t;j++)
			s[i][j]+=psum[i][t-j+1]/100000.0*(dist[eset[i].v]+x);
	}
}
void solve(int id,int l,int r){
	int mid((l+r)>>1),i,N;
	for(N=1;N<r-mid+r-l;N<<=1);
	for(i=mid+1;i<=r;i++)
		A[i-mid-1]=cpx(f[eset[id].v][i],0);
	for(i=r-mid;i<N;i++)
		A[i]=cpx(0,0);
	for(i=1;i<=r-l+1;i++)
		B[r-l-i]=cpx(p[id][i]/100000.0,0);
	for(i=r-l+1;i<N;i++)
		B[i]=cpx(0,0);
	mul(A,B,A,N);
	for(i=l;i<=mid;i++)
		s[id][i]+=A[r+i-l-mid-1].r;
}
void Divide_Conquer(int l,int r){
	if(l==r){
		int i;
		for(i=1;i<=m;i++)
			f[eset[i].u][l]=min(f[eset[i].u][l],s[i][l]+eset[i].wt);
		return;
	}
	int mid((l+r)>>1),i;
	Divide_Conquer(mid+1,r);
	for(i=1;i<=m;i++)
		solve(i,l,r);
	Divide_Conquer(l,mid);
}
int main()
{
	read();
	Bellman_ford();
	Divide_Conquer(0,t);
	cout<<setprecision(10)<<f[1][0]<<endl;
}