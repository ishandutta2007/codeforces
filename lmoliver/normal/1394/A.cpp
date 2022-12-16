#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define D(N,E) for(int N=0;N<(int)(E);N++)
typedef vector<LL> V;

template<class T=LL>
T read(){
	T x=0;
	char ch=0;
	bool f=false;
	while(!isdigit(ch))f|=(ch=getchar())=='-';
	for(;isdigit(ch);ch=getchar())x=x*10+(ch^'0');
	return f?-x:x;
}

const int N=100100;
LL lm[N],rm[N];
int lc=0,rc=0;

int main(){
	LL n=read(),d=read(),m=read();
	F(i,1,n){
		int a=read();
		if(a<=m)lm[++lc]=a;
		else rm[++rc]=a;
	}
	sort(lm+1,lm+lc+1,greater<LL>());
	sort(rm+1,rm+rc+1,greater<LL>());
	F(i,1,lc)lm[i]+=lm[i-1];
	F(i,1,rc)rm[i]+=rm[i-1];
	LL ans=0;
	F(i,0,n){
		int l=min(lc,i);
		int r=min((LL)rc,(n-i+d)/(d+1));
		LL tans=lm[l]+rm[r];
		ans=max(ans,tans);
	}
	printf("%lld\n",ans);
	return 0;
}