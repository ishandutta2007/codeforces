#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,L=505;
typedef long long ll;
int n,B,m,ft[L],b[N],rb[L];ll r[N],c[N],t[N],T,h[N],f[N],tq[N],ans;
int main(){
	scanf("%d",&n),B=sqrt(n);
	for(int i=1;i<=n;i++)scanf("%lld%lld",&c[i],&r[i]),b[i]=(i-1)/L+1;
	for(int i=1;i<b[n];i++)rb[i]=i*B;rb[b[n]]=n;
	scanf("%d",&m);
	for(int i=1;i<=m;i++)scanf("%lld%lld",&t[i],&h[i]),T=max(T,t[i]);
	for(int k=1,lt;k<=b[n];k++){
		fill(f,f+T+1,0);
		for(int i=rb[k-1]+1;i<=rb[k];i++){
			f[1]+=r[i],tq[i]=c[i];
			if(c[i]/r[i]<=T)f[c[i]/r[i]+1]+=c[i]%r[i]-r[i],f[c[i]/r[i]+2]-=c[i]%r[i];
		}
		for(int i=1;i<=T;i++)f[i]+=f[i-1];
		for(int i=1;i<=T;i++)f[i]+=f[i-1];
		lt=-1;
		for(int i=1,lst=0;i<=m;i++)if(h[i]){
			if(lt!=-1&&h[i]>=f[t[i]-lt])h[i]-=f[t[i]-lt],lt=t[i];
			else if(lt!=-1){
				for(int j=rb[k-1]+1;j<=rb[k];j++)tq[j]=min(r[j]*(t[i]-lt),c[j]);
				lt=-1;
				for(int j=rb[k-1]+1;j<=rb[k];j++)
					if(tq[j]<=h[i])h[i]-=tq[j],tq[j]=0;
					else {tq[j]-=h[i],h[i]=0;break;}
				lst=t[i];
			}
			else{
				ll ts=0;
				for(int j=rb[k-1]+1;j<=rb[k];j++)tq[j]=min(tq[j]+r[j]*(t[i]-lst),c[j]),ts+=tq[j];
				if(h[i]>=ts)h[i]-=ts,lt=t[i];
				else{
					lt=-1;
					for(int j=rb[k-1]+1;j<=rb[k];j++)
						if(tq[j]<=h[i])h[i]-=tq[j],tq[j]=0;
						else {tq[j]-=h[i],h[i]=0;break;}
					lst=t[i];
				}
			}
		}
	}
	for(int i=1;i<=m;i++)ans+=h[i];
	printf("%lld\n",ans);
	return 0;
}