#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define R(N,S,E) for(int N=(int)(S);N>=(int)(E);N--)
#define D(N,E) for(int N=0;N<(int)(E);N++)
typedef vector<int> V;
LL read(){LL x;scanf("%lld",&x);return x;}

const int MOD=1e9+7;
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

const int N=5050;
int a[N];
int f[N];
int main(){
	int n=read(),k=read();
	D(i,n)a[i]=read();
	f[0]=1;
	D(i,n){
		R(j,i,0){
			dsub(f[j+1],f[j]);
			dmul(f[j],a[i]);
		}
	}
	// cerr<<f[0]<<" "<<f[1]<<" "<<f[2]<<endl;
	int ans=0;
	int c=1;
	F(i,0,min(n,k)){
		dadd(ans,mul(c,mul(f[i],ksm(n,k-i))));
		dmul(c,k-i);
	}
	dmul(ans,inv(ksm(n,k)));
	int prod=1;
	D(i,n)dmul(prod,a[i]);
	int res=sub(prod,ans);
	printf("%d\n",res);
	return 0;
}