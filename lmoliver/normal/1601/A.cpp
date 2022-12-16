#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> V;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define R(N,S,E) for(int N=(int)(S);N>=(int)(E);N--)
#define D(N,E) for(int N=0;N<(int)(E);N++)
LL read(){LL x;scanf("%lld",&x);return x;}

int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main(){
	int t=read();
	D(_,t){
		int n=read();
		int x[30]={0};
		D(_,n){
			int v=read();
			D(i,30)x[i]+=(v>>i)&1;
		}
		int g=0;
		D(i,30)g=gcd(g,x[i]);
		F(i,1,n)if(g%i==0)printf("%d ",i);
		printf("\n");
	}
	return 0;
}