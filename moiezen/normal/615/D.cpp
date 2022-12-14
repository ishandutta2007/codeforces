#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#define rpt(i,l,r) for(i=l;i<=r;i++)
#define rpd(i,r,l) for(i=r;i>=l;i--)
#define N 200005
#define mod 1000000007
int n,m,i,j,k;
int flag;
int a[N],b[N]={0};
long long cj;
long long ans;
long long mi(long long x,int c){
	if(x==0) return 1;
	long long temp=mi(x>>1,c);
	temp=temp*temp;temp%=mod;
	if(x&1) (temp*=c)%=mod;
	return temp;
}
int main(){
	scanf("%d",&n);
	rpt(i,1,n){
		scanf("%d",&a[i]);
		b[a[i]]++;
	}
	flag=0;
	rpt(i,1,200000) if(b[i]&1){
		flag=1;
		break;
	}
	ans=1;
	if(flag==1){
		rpt(i,1,200000) if(b[i]) (ans*=mi(b[i],i))%=mod;
		rpt(i,1,200000) if(b[i])
		if(((b[i]+1)&1)==0&&flag){
			cj=(b[i]+1)>>1;
			ans=mi(cj,ans);
			flag=0;
		}
		else{
			cj=b[i]+1;
			ans=mi(cj,ans);
		}
	}
	else{
		rpt(i,1,200000) if(b[i]) (ans*=mi(b[i]>>1,i))%=mod;
		rpt(i,1,200000) if(b[i]){
			cj=b[i]+1;
			ans=mi(cj,ans);
		}
	}
	printf("%I64d\n",ans);
}