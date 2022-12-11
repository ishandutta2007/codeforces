#include<cstdio>
#include<algorithm>
using namespace std;

const int md=998244353;
struct dn{int u,v;};
bool operator<(dn x,dn y){
	return x.u<y.u;
}
dn p[1000001];
int p0,a[101],pwa[101],b[101];
int main(){
	int k,A,H;
	scanf("%d%d%d",&k,&A,&H);
	for(int i=pwa[0]=1;i<=100;i++)
		pwa[i]=1ll*pwa[i-1]*A%md;
	for(int o=0;o<2;o++){
		p0=0;
		for(int s=0;s<1<<(1<<k-1)-1;s++){
			int w=0;
			for(int j=1;j<=1<<k-1;j++)
				a[j]=j;
			int ans=0;
			for(int i=k-1;i;i--)
				for(int j=1;j<=1<<i;j+=2){
					if(s>>w&1)ans=(ans+1ll*a[j+1]*pwa[(1<<i)+1])%md,a[(j+1)/2]=a[j];
					else ans=(ans+1ll*a[j]*pwa[(1<<i)+1])%md,a[(j+1)/2]=a[j+1];
					w++;
				}
			if(o)ans=(ans+1ll*a[1]*pwa[1])%md;
			else ans=(ans+1ll*a[1]*pwa[2])%md;
			p[++p0]=(dn){ans,s};
		}
		sort(p+1,p+p0+1);
		for(int s=0;s<1<<(1<<k-1)-1;s++){
			int w=0;
			for(int j=1;j<=1<<k-1;j++)
				a[j]=j+(1<<k-1);
			int ans=0;
			for(int i=k-1;i;i--)
				for(int j=1;j<=1<<i;j+=2){
					if(s>>w&1)ans=(ans+1ll*a[j+1]*pwa[(1<<i)+1])%md,a[(j+1)/2]=a[j];
					else ans=(ans+1ll*a[j]*pwa[(1<<i)+1])%md,a[(j+1)/2]=a[j+1];
					w++;
				}
			if(o)ans=(ans+1ll*a[1]*pwa[2])%md;
			else ans=(ans+1ll*a[1]*pwa[1])%md;
			int pp=lower_bound(p+1,p+p0+1,(dn){(H-ans+md)%md,0})-p;
			if((p[pp].u+ans)%md==H){
				int w1=0,w2=0;
				for(int j=1;j<=1<<k;j++)
					a[j]=j;
				for(int i=k;i>1;i--)
					for(int j=1;j<=1<<i;j+=2){
						if(a[j]<=1<<k-1){
							if(p[pp].v>>w1&1)b[a[j+1]]=(1<<i-1)+1,a[(j+1)/2]=a[j];
							else b[a[j]]=(1<<i-1)+1,a[(j+1)/2]=a[j+1];
							w1++;
						}
						else{
							if(s>>w2&1)b[a[j+1]]=(1<<i-1)+1,a[(j+1)/2]=a[j];
							else b[a[j]]=(1<<i-1)+1,a[(j+1)/2]=a[j+1];
							w2++;
						}
					}
				b[a[1]]=1,b[a[2]]=2;
				if(!o)swap(b[a[1]],b[a[2]]);
				for(int i=1;i<=1<<k;i++)
					printf("%d%c",b[i],i==1<<k?'\n':' ');
			/*	int SS=0,SS2=0;
				for(int i=1;i<=1<<k-1;i++){
					SS=(SS+1ll*i*pwa[b[i]])%md;
					SS2=(SS2+1ll*(i+(1<<k-1))*pwa[b[i+(1<<k-1)]])%md;}
				printf("%d!!!!%d %d %d\n",ans,p[pp].u,SS,SS2);*/
				return 0;
			}
		}
	}
	printf("-1\n");
}