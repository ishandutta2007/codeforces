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

const int N=2.1e5;
int w[N];
LL sw;
int main(){
	int t=read();
	D(_,t){
		int n=read();
		ignore=scanf("%lld",&sw);
		LL l=(sw+1)/2;
		D(i,n)w[i]=read();
		V xs;
		D(i,n)if(w[i]<=sw)xs.push_back(i);
		V ans;
		LL cs=0;
		for(int i:xs){
			if(w[i]>=l){
				ans={i};
				goto ok;
			}
			else{
				cs+=w[i];
				ans.push_back(i);
				if(cs>=l)goto ok;
			}
		}
		puts("-1");
		continue;
		ok:;
		printf("%d\n",(int)ans.size());
		for(int i:ans)printf("%d ",i+1);
		printf("\n");
	}
	return 0;
}