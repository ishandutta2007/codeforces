#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> V;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define R(N,S,E) for(int N=(int)(S);N>=(int)(E);N--)
#define D(N,E) for(int N=(int)(0);N<(int)(E);N++)
LL read(){LL x;scanf("%lld",&x);return x;}

int main(){
	int t=read();
	D(_,t){
		int n=read(),m=read();
		int ans=(n>1)+(m>1);
		printf("%d\n",ans);
	}
	return 0;
}