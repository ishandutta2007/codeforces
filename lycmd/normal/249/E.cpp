#include<bits/stdc++.h>
#define int __int128
using namespace std;
int const INF=10000000000;
int t,xl,xr,yl,yr;
int read(){
	int x=0;char c=getchar();
	while(c<48||c>57)c=getchar();	
	while(c>47&&c<58)x=x*10+c-48,c=getchar();
	return x;
}
int solve(int x,int y){
	return x<y?(x*x*x+2*y*y*y+3*x*y-3*y*y-x+4*y)*x/6:
		(2*x*x*x+y*y*y+3*x*x-3*x*y+4*x-y)*y/6;
}
signed main(){
	for(t=read();t--;){
		xl=read(),yl=read(),xr=read(),yr=read();
		int ans=solve(xr,yr)-solve(xl-1,yr)-solve(xr,yl-1)+solve(xl-1,yl-1);
		long long t=ans%INF;
		if(ans>=INF)printf("...%010I64d\n",t);
		else printf("%I64d\n",t);
	}
}