#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define D(N,E) for(int N=0;N<(int)(E);N++)
typedef vector<int> V;

template<class T=LL>
T read(){
	T x=0;
	char ch=0;
	bool f=false;
	while(!isdigit(ch))f|=(ch=getchar())=='-';
	for(;isdigit(ch);ch=getchar())x=x*10+(ch^'0');
	return f?-x:x;
}

LL gcd(LL a,LL b){return a?gcd(b,a%b):b;}

LL ext(LL p,LL q,LL v){
	if(v==1)return 1;
	while(p%q==0){
		if(p%v)return 1;
		p/=v;
	}
	return p;
}
LL calc(LL p,LL q){
	LL ans=1;
	F(i,1,q){
		if(q%i==0){
			ans=max(ans,ext(p,q,i));
			ans=max(ans,ext(p,q,q/i));
		}
		if((LL)i*i>q)break;
	}
	return ans;
}

int main(){
	int t=read();
	D(_,t){
		LL p=read(),q=read();
		LL ans=p%q?p:calc(p,q);
		printf("%lld\n",ans);
	}
	return 0;
}