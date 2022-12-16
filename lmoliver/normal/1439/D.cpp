#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> V;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define R(N,S,E) for(int N=(int)(S);N>=(int)(E);N--)
#define D(N,E) for(int N=0;N<(int)(E);N++)
LL read(){LL x;scanf("%lld",&x);return x;}

int p;
int add(int a,int b){return a+b<p?a+b:a+b-p;}
void dadd(int &a,int b){a=add(a,b);}
int sub(int a,int b){return a>=b?a-b:a-b+p;}
void dsub(int &a,int b){a=sub(a,b);}
int mul(int a,int b){return (LL)a*b%p;}
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
int inv(int a){return ksm(a,p-2);}
int inv2(){return (p+1)>>1;}

int sum(int a){return mul(mul(a,add(a,1)),inv2());}

const int N=555;

int c[N][N];
void init(int n){
	F(i,0,n){
		c[i][0]=1;
		F(j,1,i)c[i][j]=add(c[i-1][j-1],c[i-1][j]);
	}
}

struct P{
	int cnt,sum;
};
ostream &operator<<(ostream &o,P p){return o<<"("<<p.cnt<<","<<p.sum<<")";}
P operator*(P a,P b){return (P){mul(a.cnt,b.cnt),add(mul(a.cnt,b.sum),mul(a.sum,b.cnt))};}
void operator+=(P &a,P b){dadd(a.cnt,b.cnt);dadd(a.sum,b.sum);}
P operator*(int a,P b){return (P){mul(a,b.cnt),mul(a,b.sum)};}

P dp[N];
P f[N][N];
int main(){
	int n=read(),m=read();
	p=read();
	init(m);
	dp[0].cnt=1;
	F(i,1,m){
		F(j,1,i){
			P qaq=dp[j-1]*dp[i-j]*(P){i+1,add(sum(i-j),sum(j-1))};
			// cerr<<c[i-1][i-j]<<" "<<qaq<<endl;
			dp[i]+=c[i-1][i-j]*qaq;
		}
		// cerr<<"dp["<<i<<"]="<<dp[i]<<endl;
	}
	// f[x][y]
	// =[x==y]dp[x]+f[x-1][y]+sum(i,p(i,y-i)*dp[i]*f[x-i-1][y-i])
	F(i,0,n)F(j,0,min(i,m)){
		P &a=f[i][j];
		if(i==j)a=dp[j];
		else{
			F(k,0,j)a+=c[j][k]*dp[k]*f[i-k-1][j-k];
		}
		// cerr<<"f "<<i<<" "<<j<<" "<<f[i][j]<<endl;
	}
	printf("%d\n",f[n][m].sum);
	return 0;
}