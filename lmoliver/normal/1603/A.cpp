#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> V;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define R(N,S,E) for(int N=(int)(S);N>=(int)(E);N--)
#define D(N,E) for(int N=0;N<(int)(E);N++)
LL read(){LL x;scanf("%lld",&x);return x;}

const int N=3.1e5;
int a[N];

void work(){
	int n=read();
	F(i,1,n)a[i]=read();
	n=min(n,50);
	while(n){
		bool did=false;
		R(i,n,1){
			if(a[i]%(i+1)){
				F(j,i,n-1)a[j]=a[j+1];
				n--;
				did=true;
				break;
			}
		}
		if(!did)break;
	}
	if(n==0)puts("YES");
	else puts("NO");
}

int main(){
	int t=read();
	D(_,t)work();
	return 0;
}