#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define D(N,E) for(int N=0;N<(int)(E);N++)
typedef vector<int> V;

template<class T=int>
T read(){
	T x=0;
	char ch=0;
	bool f=false;
	while(!isdigit(ch))f|=(ch=getchar())=='-';
	for(;isdigit(ch);ch=getchar())x=x*10+(ch^'0');
	return f?-x:x;
}

const int N=300200;
int a[N];

const int MOD=998244353;
int add(int a,int b){return (a+b)%MOD;}
void dadd(int &a,int b){a=add(a,b);}
int sub(int a,int b){return (a-b+MOD)%MOD;}
void dsub(int &a,int b){a=sub(a,b);}
int mul(int a,int b){return (LL)a*b%MOD;}
void dmul(int &a,int b){a=mul(a,b);}
const int I2=(MOD+1)/2;
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
int f(int n){
	int ans=1;
	F(i,1,n)dmul(ans,i);
	return ans;
}
int sqr(int a){return mul(a,a);}
int c2nn(int n){
	return mul(f(2*n),inv(sqr(f(n))));
}
int main(){
	int n=read();
	F(i,1,2*n)a[i]=read();
	sort(a+1,a+2*n+1);
	F(i,1,2*n)a[i]%=MOD;
	int s=0;
	F(i,1,n)dsub(s,a[i]);
	F(i,n+1,2*n)dadd(s,a[i]);
	int ans=mul(s,c2nn(n));
	printf("%d\n",ans);
	return 0;
}