#include <cstdio>
#include <iostream>
#define rpt(i,l,r) for(int i=l;i<=r;i++)
#define ll long long
#define N 100005
ll n,k,a,b,rec,ans[N];
void output(ll now){
	printf(now==rec?"G":"B");
}
ll min(ll a,ll b){return (a<b)?a:b;}
int main(){
	scanf("%I64d%I64d%I64d%I64d",&n,&k,&a,&b);
	if((b+1)*k<a||(a+1)*k<b) return printf("NO"),0;
	if(a==b){
		rpt(i,1,n) printf(i&1?"G":"B");
		return 0;
	}
	rec=0;
	if(a<b) std::swap(a,b),rec=1;
	a-=b+1;k--;
	while(a>0) ans[++ans[0]]=min(a,k),a-=k;
	rpt(i,1,b+1) ans[i]++;
	rpt(i,1,b){
		rpt(j,1,ans[i]) output(0);
		output(1);
	}
	rpt(j,1,ans[b+1])output(0);
}