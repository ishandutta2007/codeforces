#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n,qwq=1078282205,p[8]={5,7,11,13,17,19,23,29},invp[8],r[8];
int qpow(int x,int y,int P){
	int res=1;x%=P;
	for(;y;y>>=1,x=1ll*x*x%P)
		if(y&1)res=1ll*res*x%P;
	return res;
}
int crt(){int res=0;for(int i=0;i<8;i++)res=(res+1ll*r[i]*(qwq/p[i])*invp[i])%qwq;return res;}
int main(){
	scanf("%d",&T);
	for(int i=0;i<8;i++)invp[i]=qpow(qwq/p[i],p[i]-2,p[i]);
	while(T--){
		for(int i=1,g;i<=29;i++){
			printf("? %d %d\n",i,qwq+i),fflush(stdout),scanf("%d",&g);
			for(int j=0;j<8;j++)if(g%p[j]==0)r[j]=(p[j]-i%p[j])%p[j];
		}
		printf("! %d\n",crt()),fflush(stdout);
	}
	return 0;
}