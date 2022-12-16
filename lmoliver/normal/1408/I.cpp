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

const int L=16;
const int X=1<<L;
const int K=17;

int main(){
	int n=read(),k=read(),c=read();
	const auto f=[=](int a){return a^(a-k);};
	V a(n);
	D(i,n)a[i]=read();
	int sum=0;
	D(i,n)sum^=a[i];
	sort(a.begin(),a.end(),[&](int a,int b){return f(a)<f(b);});
	int ifrac[K];
	F(i,0,k)ifrac[i]=i?mul(ifrac[i-1],inv(i)):1;

	static unsigned long long dp[K][X]={0};
	dp[0][0]=1;
	int l=0;
	D(aid,n){
		// cerr<<aid<<endl;
		int x=a[aid];
		// cerr<<x<<" "<<f(x)<<endl;
		R(j,k-1,0){
			F(d,1,k-j){
				unsigned long long qaq=ifrac[d];
				int qwq=x^(x-d);
				int id=j+d;
				D(i,1<<l){
					// if(dp[i][j])cerr<<"dp["<<i<<","<<j<<"] -> dp["<<(i^x^(x-d))<<","<<j+d<<"]"<<endl;
					dp[id][i^qwq]+=qaq*dp[j][i];
				}
			}
		}
		int qwq=f(x);
		while((1<<l)<=qwq)l++;
		F(j,0,k)D(i,1<<l)dp[j][i]%=MOD;
	}
	int itot=inv(ksm(n,k));
	F(i,1,k)dmul(itot,i);
	D(i,1<<c){
		// cerr<<(i^sum)<<endl;
		printf("%d%c",mul((int)dp[k][i^sum],itot)," \n"[i+1==(1<<c)]);
	}
	return 0;
}