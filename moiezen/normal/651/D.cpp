#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#define rpt(i,l,r) for(i=l;i<=r;i++)
#define rpd(i,r,l) for(i=r;i>=l;i--)
#define N 500005
int n,a,b,t,i,j,k,ans,p;
char s[N];
int c[N],d[N],e[N],f[N];
int delta;
void input(){
	scanf("%d%d%d%d",&n,&a,&b,&t);
	scanf("%s",s+1);
}
int main(){
	input();
	
	if(s[1]=='w') t-=b;
	t--;
	
	if(t<0) return printf("0"),0;
	
	ans=1;
	
	c[1]=d[1]=0;
	
	rpt(i,2,n){
		delta=a+1;
		if(s[i]=='w') delta+=b;
		
		c[i]=c[i-1]+delta;
		d[i]=d[i-1]+delta+a;
	}
	
	e[n+1]=f[n+1]=0;
	
	rpd(i,n,2){
		delta=a+1;
		if(s[i]=='w') delta+=b;
		
		e[i]=e[i+1]+delta;
		f[i]=f[i+1]+delta+a;
	}
	
	p=2;
	rpt(i,1,n){
		while(c[i]+f[p]>t&&p<=n) p++;
		if(c[i]+f[p]>t) break;
		if(i+n-p+1>ans) ans=i+n-p+1;
	}
	
	p=2;
	rpt(i,1,n){
		while(d[i]+e[p]>t&&p<=n) p++;
		if(d[i]+e[p]>t) break;
		if(i+n-p+1>ans) ans=i+n-p+1;
	}
	
	if(ans>n) ans=n;
	
	printf("%d",ans);
}