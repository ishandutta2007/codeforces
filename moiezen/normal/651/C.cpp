#include<cstdio>
#include<iostream>
#include<map>
#define rpt(i,l,r) for(i=l;i<=r;i++)
#define N 200005
using namespace std;
int n,i;
int x[N],y[N];
map<int,int> f;
map<int,int> g;
map<long long,int> h;
long long key,ans;
void input(){
	scanf("%d",&n);
	rpt(i,1,n) scanf("%d%d",&x[i],&y[i]);
}
void init(){
	ans=0;
	rpt(i,1,n) ans+=f[x[i]],f[x[i]]++;
	rpt(i,1,n) ans+=g[y[i]],g[y[i]]++;
	rpt(i,1,n){
		key=x[i]*2100000000LL+y[i];
		ans-=h[key];
		h[key]++;
	}
	
}
void work(){
	
}
void output(){
	printf("%I64d",ans);
	
}
int main(){
	input();
	init();
	work();
	output();
}