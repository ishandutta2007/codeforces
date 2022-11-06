#include<cstdio>
#include<iostream>
#define N 212222
using namespace std;int n,m,i,x,y,tot,fir[N],la[N<<1],ne[N<<1];long long ans,pfh,hpf,mav,mv1,mv2,w[N];
void ins(int x,int y){la[++tot]=y;ne[tot]=fir[x];fir[x]=tot;}
int main(){
	for(scanf("%d",&n),i=1;i<n;i++)scanf("%d%d",&x,&y),ins(x,y),ins(y,x);
		for (i=1; i<=n; i++)w[i]=1;
	for(x=1;x<=n;mav=max(mav,mv1*mv2),ans+=pfh*pfh-hpf,x++)
		for(pfh=hpf=mv1=mv2=0,i=fir[x];i;i=ne[i]){
			pfh+=w[y=la[i]];hpf+=w[y]*w[y];
			if(w[y]>mv1)mv2=mv1,mv1=w[y];else if(w[y]>mv2)mv2=w[y];
		}
	printf("%lld",ans>>1);
}