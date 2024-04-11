#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> V;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define R(N,S,E) for(int N=(int)(S);N>=(int)(E);N--)
#define D(N,E) for(int N=0;N<(int)(E);N++)
LL read(){LL x;scanf("%lld",&x);return x;}

LL work(){
	LL a=read(),b=read(),c=read(),d=read();
	if(a-b*c>0)return -1;
	LL qaq=a/b/d;
	// assert(a/b<=c);
	// assert(qaq*d<=c);
	LL damage=(qaq+1)*a;
	damage-=b*(qaq*(qaq+1)/2)*d;
	return damage;
}

int main(){
	int t=read();
	D(_,t)printf("%lld\n",work());
	return 0;
}