#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> V;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define R(N,S,E) for(int N=(int)(S);N>=(int)(E);N--)
#define D(N,E) for(int N=(int)(0);N<(int)(E);N++)
LL read(){LL x;scanf("%lld",&x);return x;}

const int N=100;
int a[N];

int main(){
	int t=read();
	D(_,t){
		int n=read();
		D(i,n)a[i]=read();
		LL t=1;
		D(i,n){
			int x=a[i]&-a[i];
			t*=x;
			a[i]/=x;
		}
		LL ans=(t-1)**max_element(a,a+n);
		D(i,n)ans+=a[i];
		printf("%lld\n",ans);
	}
	return 0;
}