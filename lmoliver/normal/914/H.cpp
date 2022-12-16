#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define R(N,S,E) for(int N=(int)(S);N>=(int)(E);N--)
#define D(N,E) for(int N=0;N<(int)(E);N++)
typedef vector<int> V;
LL read(){LL x;scanf("%lld",&x);return x;}

unsigned m;
unsigned add(unsigned a,unsigned b){return a+b<m?a+b:a+b-m;}
void dadd(unsigned &a,unsigned b){a=add(a,b);}
unsigned sub(unsigned a,unsigned b){return a>=b?a-b:a-b+m;}
void dsub(unsigned &a,unsigned b){a=sub(a,b);}
unsigned mul(unsigned a,unsigned b){return (LL)a*b%m;}
void dmul(unsigned &a,unsigned b){a=mul(a,b);}
unsigned ksm(unsigned a,unsigned b){
	unsigned ans=1;
	while(b){
		if(b&1)dmul(ans,a);
		b>>=1;
		dmul(a,a);
	}
	return ans;
}

const int N=222;
unsigned c[N][N];
unsigned tr[N];
unsigned fo[N][N];
unsigned top[N];

int main(){
	int n=read(),d=read();
	m=read();
	if(m==1){
		puts("0");
		exit(0);
	}
	F(i,0,n){
		c[i][0]=1;
		F(j,1,i)c[i][j]=add(c[i-1][j-1],c[i-1][j]);
	}
	// fo[c][n]=[c=0]*[n=0]+[c!=0]*(sum{k>=1}c(n,k)*fo[c-1][n-k]*tr[k])
	// tr[n]=sum{k<=d-1}fo[n-1][k]
	// top[n]=sum{2<=k<=d-1}fo[n-1][k]
	// 
	fo[0][0]=1;
	F(cnt,1,n){
		tr[cnt]=0;
		F(i,0,d-1)dadd(tr[cnt],fo[i][cnt-1]);
		F(i,1,n){
			F(k,1,cnt)dadd(fo[i][cnt],mul(c[cnt-1][k-1],mul(fo[i-1][cnt-k],tr[k])));
		}
		top[cnt]=0;
		F(i,2,d-1)dadd(top[cnt],fo[i][cnt-1]);
	}
	unsigned ans=n==2||d>=2;
	F(i,1,n)F(j,1,n)if(i+j<=n){
		dadd(ans,mul(top[i],top[j]));
	}
	// F(i,1,n)cerr<<i<<" "<<tr[i]<<endl;
	// F(i,1,n)cerr<<i<<" "<<top[i]<<endl;
	F(i,1,n-1)dadd(ans,top[i]);
	F(i,1,n-1)dadd(ans,top[i]);
	F(i,2,d){
		dadd(ans,fo[i][n-1]);
		dadd(ans,fo[i][n-1]);
	}
	// cerr<<"ans="<<ans<<endl;
	F(i,1,n-1){
		F(k1,2,d)F(k2,2,d)if(k1+k2<=d){
			dadd(ans,mul(fo[k1][i],fo[k2][n-1-i]));
		}
	}
	dmul(ans,mul(2%m,mul(n%m,(n-1)%m)));
	printf("%u\n",ans);
	return 0;
}