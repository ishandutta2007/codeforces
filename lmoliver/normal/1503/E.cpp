#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> V;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define R(N,S,E) for(int N=(int)(S);N>=(int)(E);N--)
#define D(N,E) for(int N=0;N<(int)(E);N++)
LL read(){LL x;scanf("%lld",&x);return x;}

const int MOD=998244353;
int add(int a,int b){return a+b<MOD?a+b:a+b-MOD;}
void dadd(int &a,int b){a=add(a,b);}
int sub(int a,int b){return a>=b?a-b:a-b+MOD;}
void dsub(int &a,int b){a=sub(a,b);}
int mul(int a,int b){return (LL)a*b%MOD;}
void dmul(int &a,int b){a=mul(a,b);}
int ksm(int a,int b){
	int ans=1;
	while(b){
		if(b&1)dmul(ans,a);
		b>>=1;
		dmul(a,a);
	}
	return ans;
}
int inv(int a){return ksm(a,MOD-2);}
struct Z{int v;Z(int v):v(v){}}z(1);
Z operator*(Z a,Z b){return mul(a.v,b.v);}

const int N=1e4;
int fr[N],ifr[N];
int c(int n,int k){return k<0||k>n?0:(z*fr[n]*ifr[k]*ifr[n-k]).v;}
int tp(int a,int b){return c(a+b,a);}
const int TN=2333;
int gp[TN][TN];
int p(int a,int b){return a<0||b<0?0:gp[a][b];}
int pp(int n,int m){return tp(n-1,2*m);}

int n,m;
int calc1(int x,int y,int l){
	int cx=n-x-l,cy=m-y;
	return (z*p(x,y)*p(x,cy)*p(cx,y)*p(cx,cy)).v;
}
int main(){
	D(i,N)fr[i]=i?mul(fr[i-1],i):1;
	D(i,N)ifr[i]=inv(fr[i]);
	D(i,TN)D(j,TN)gp[i][j]=tp(i,j);
	// cerr<<c(5,2)<<endl;
	// cerr<<p(2,2)<<endl;
	n=read();
	m=read();
	int t1=0;
	F(i,0,m){
		int tmp=mul(pp(n,i),pp(n,m-i));
		F(j,0,n){
			int d=sub(calc1(j,i,1),calc1(j-1,i,2));
			dsub(tmp,d);
		}
		// cerr<<"i="<<i<<" tmp="<<tmp<<endl;
		dadd(t1,tmp);
	}
	int t2=0;
	F(i,0,n){
		int tmp=mul(pp(m,i),pp(m,n-i));
		F(j,0,m){
			swap(n,m);
			int d=sub(calc1(j,i,1),calc1(j-1,i,2));
			swap(n,m);
			int w=(z*p(i-1,j)*p(i,m-j-1)*p(n-i,j-1)*p(n-i-1,m-j)).v;
			dadd(d,mul(w,2));
			dsub(tmp,d);
		}
		// cerr<<"i="<<i<<" tmp="<<tmp<<endl;
		dadd(t2,tmp);
	}
	// cerr<<"t1="<<t1<<" t2="<<t2<<endl;
	int ans=add(t1,t2);
	printf("%d\n",ans);
	return 0;
}