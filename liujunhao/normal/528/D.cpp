#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define EPS 0.2
using namespace std;
#define MAXN 200000
const double pi=acos(-1);
void Read(int &x){
	char c;
	while(c=getchar(),c!=EOF)
		if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			return;
		}
}
char S[MAXN+10],T[MAXN+10];
int n,m,k,l[MAXN+10],r[MAXN+10],N,sum[MAXN+10],ans;
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
}A[MAXN*3+10],B[MAXN*3+10],t[MAXN*3+10];
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
	int i,j;
	for(i=0;i<N;i++)
		t[i]=cpx(a[i].r,b[i].r);
	fft(t,N,1);
	for(i=0;i<N;i++){
		j=(N-i)&(N-1);
		c[i]=(t[i]*t[i]-(t[j]*t[j]).conj())*cpx(0,-0.25);
	}
	fft(c,N,-1);
}
void read(){
	Read(n),Read(m),Read(k);
	scanf("%s%s",S,T);
}
char ss[10]="ACGT";
void solve(){
	int i,p,la;
	for(N=1;N<(n+m-1);N<<=1);
	for(p=0;p<4;p++){
		memset(A,0,sizeof A);
		memset(B,0,sizeof B);
		la=-1e9;
		for(i=0;i<n;i++){
			if(S[i]==ss[p])
				la=i;
			l[i]=la;
		}
		la=1e9;
		for(i=n-1;i>=0;i--){
			if(S[i]==ss[p])
				la=i;
			r[i]=la;
		}
		for(i=0;i<n;i++)
			if(i-l[i]<=k||r[i]-i<=k)
				A[i].r=1;
		for(i=0;i<m;i++)
			if(T[i]==ss[p])
				B[m-i-1].r=1;
		mul(A,B,A,N);
		for(i=0;i<n;i++)
			sum[i]+=A[i+m-1].r+EPS;
	}
	for(i=0;i<n;i++)
		if(sum[i]==m)
			ans++;
}
int main()
{
	read();
	solve();
	printf("%d\n",ans);
}