#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#define rpt(i,l,r) for(i=l;i<=r;i++)
#define rpd(i,r,l) for(i=r;i>=l;i--)
#define N 150005
int s[233];
int t[N];
int n,m,i,j,k,x,id,flag;
int main(){
	scanf("%d%d%d",&n,&k,&m);
	rpt(i,1,n) scanf("%d",&t[i]);
	rpt(i,1,k) s[i]=0;
	while(m--){
		scanf("%d%d",&x,&id);
		if(x==1){
			s[k+1]=-t[id];
			std::sort(s+1,s+k+2);
		}
		else{
			flag=0;
			rpt(i,1,k) if(-s[i]==t[id]){
				flag=1;
				break;
			}
			printf(flag?"YES\n":"NO\n");
		}
	}
}