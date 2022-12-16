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
		dmul(a,a);
		b>>=1;
	}
	return ans;
}
int inv(int a){
	assert(a);
	return ksm(a,MOD-2);
}
const int NEG1=sub(0,1);
int pn1(int x){return x&1?NEG1:1;}

struct P{
	int v;
	P(int v):v(v){}
};
ostream &operator<<(ostream &o,P p){
	int v=p.v;
	F(i,1,1000)F(j,-1000,1000){
		if(mul(sub(j,0),inv(i))==v){
			o<<j;
			if(i!=1)o<<"/"<<i;
			return o;
		}
	}
	return o<<"M"<<v;
}

const int N=2.1e6;
int fr[N],ifr[N],ivx[N];
int c(int n,int k){return k<0||k>n?0:mul(fr[n],mul(ifr[k],ifr[n-k]));}
int invc(int n,int k){return k<0||k>n?inv(0):mul(ifr[n],mul(fr[k],fr[n-k]));}
void init(int n){
	F(i,0,n)fr[i]=i?mul(fr[i-1],i):1;
	ifr[n]=inv(fr[n]);
	R(i,n-1,0)ifr[i]=mul(ifr[i+1],i+1);
	F(i,1,n)ivx[i]=mul(fr[i-1],ifr[i]);
	assert(ivx[1]==1);
}

int f(int n,int m,int k){
	int p1=mul(n+m+1,ivx[m+1]);
	return mul(p1,mul(m+k,ivx[k]));
}

int main(){
	int n=read(),m=read();
	init(max(n,m+1));
	int ans=0;
	F(k,1,n){
		// cerr<<"k="<<k<<" e="<<P(f(n,m,k))<<endl;
		dadd(ans,mul(mul(pn1(k^1),c(n,k)),f(n,m,k)));
	}
	// cerr<<P(ans)<<endl;
	printf("%d\n",ans);
	return 0;
}