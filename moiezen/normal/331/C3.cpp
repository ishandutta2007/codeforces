#include <cstdio>
#include <iostream>
#include <map>
#define ll long long
std::map<ll,ll> f[10],g[10];
int mxdig(ll n){
	int res=0;
	while(n){
		if(n%10>res) res=n%10;
		n/=10;
	}
	return res;
}
int maxv(int a,int b){
	return a>b?a:b;
}
ll solv(int x,ll y){
	if(f[x][y]) return f[x][y];
	ll res=0,temp,z=y,t,xx,yy;
	while(z>0){
		t=1;
		while(t*10<=z) t*=10;
		xx=maxv(x,z/t);yy=z%t;
		temp=solv(xx,yy);
		z+=g[xx][yy]-yy;
		res+=f[xx][yy];
	}
	g[x][y]=z;
	return f[x][y]=res;
}
ll n,m,d;
int c,t,x;
int main(){
	std::cin>>n;
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			f[i][j]=1,g[i][j]=j-maxv(i,j);
	if(!n) printf("0");
	else if(n==1000000000000000000LL) std::cout<<solv(0,n-1)+1;
	else std::cout<<solv(0,n);
}