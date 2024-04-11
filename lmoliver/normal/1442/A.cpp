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

const int N=100100;
int a[N],d[N];
int main(){
	int t=read();
	D(_,t){
		int n=read();
		F(i,1,n)a[i]=read();
		F(i,1,n)d[i]=a[i]-a[i-1];
		LL sl=0,sr=0;
		F(i,2,n)(d[i]<0?sl:sr)+=abs(d[i]);
		bool ans=a[1]>=sl&&a[n]>=sr;
		puts(ans?"YES":"NO");
	}
	return 0;
}