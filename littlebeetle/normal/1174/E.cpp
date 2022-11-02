#include<cstdio>
const int N=1000002,K=50,M=1000000007;
typedef long long ll;
int n,i,j,k,d[N],g[N],p,x,a[N];
int o[K][K],ct[K],f[N][K],id[N],cnt,val[N];
bool ok[N];
int usd[N];
void init(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		g[i]=n/i;
	for(i=2;i<=n;i++){
		if(!ok[i])d[i]=1,a[k++]=i;
		for(j=0;(!j||i%a[j-1])&&i*a[j]<=n;j++){
			ok[i*a[j]]=1;
			d[i*a[j]]=d[i]+1;
		}
	}
	for(i=1;i<=n;i++)
		if(d[i]>p)
			p=d[i];
	for(i=1;i<=n;i++)
		if(d[i]==p){
			usd[i]=2;
			for(j=1;j<i;j++)
				if(i%j==0&&!usd[j])
					usd[j]=1;
		}
	for(i=1;i<=n;i++)
		if(usd[i]){
			id[i]=++cnt;
			val[cnt]=i;
			if(usd[i]==2)
				f[1][id[i]]=1;
			if(i%2==0)
				o[id[i]][ct[id[i]]++]=2;
			if(i%3==0)
				o[id[i]][ct[id[i]]++]=3;
		}	
}
void work(){
	for(i=1;i<=n;i++)
		for(j=1;j<=cnt;j++)
			if(f[i][j]){
				if(g[val[j]]>i)
					f[i+1][j]=(f[i+1][j]+1ll*f[i][j]*(g[val[j]]-i))%M;
				for(k=0;k<ct[j];k++){
					x=id[val[j]/o[j][k]];
					f[i+1][x]=(f[i+1][x]+1ll*f[i][j]*(g[val[x]]-g[val[j]]))%M;
				}
			}
	printf("%d\n",f[n][1]);			
}
int main(){
	//freopen("gcd.in","r",stdin);
	//freopen("gcd.out","w",stdout);
	init();
	work();
	return 0;
}