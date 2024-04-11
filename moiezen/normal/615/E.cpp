#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#define rpt(i,l,r) for(i=l;i<=r;i++)
#define rpd(i,r,l) for(i=r;i>=l;i--)
#define check printf("%I64d %I64d %I64d\n",half,nowx,nowy)
#define N 100005
long long calc(long long x){
	return 3*x*(x+1)+1;
}
long long n;
long long l,r,mid,base;
long long half;
long long nowx,nowy;
int main(){
	scanf("%I64d",&n);
	if(n==0) printf("0 0\n"); else{
	l=0;r=1<<30;
	while(l<=r){
		mid=(l+r)>>1;
		if(calc(mid)<=n) l=mid+1,base=mid;
		else r=mid-1;
	}
	half=calc(base);
	nowx=2*base+1;nowy=2;
	if(half+base<=n){
		half+=base;
		nowx-=base,nowy+=2*base;
		if(half+base+1<=n){
			half+=base+1;
			nowx-=2*(base+1);
			if(half+base+1<=n){
				half+=base+1;
				nowx-=(base+1),nowy-=2*(base+1);
				if(half+base+1<=n){
					half+=base+1;
					nowx+=(base+1),nowy-=2*(base+1);
					if(half+base+1<=n){
						half+=base+1;
						nowx+=2*(base+1);
						nowx+=(n-half),nowy+=2*(n-half);//youshang
					}
					else nowx+=2*(n-half);//you
				}
				else nowx+=(n-half),nowy-=2*(n-half);//youxia
			}
			else nowx-=(n-half),nowy-=2*(n-half);//zuoxia
		}
		else nowx-=2*(n-half);//zuo
	}
	else nowx-=(n-half),nowy+=2*(n-half);//zuoshang
	printf("%I64d %I64d\n",nowx,nowy);}
}