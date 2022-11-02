#include <bits/stdc++.h>
#define maxn 5005
#define ll long long
ll a[19][maxn],sum=0,tot[19]={0},d,sel[20]={0};
int c[20],to[20],vis[20]={0},con[20][maxn],k,pre[1<<18],f[1<<18]={0};
ll start=0;
std::map<ll,int>table;

int travel(int p,ll x){
	if (vis[p]){
		if (x==start)return 0;
		else return -1;
	}
	vis[p]=1;
	ll d1=d-(tot[p]-x);
	
	if (table.find(d1)==table.end()){vis[p]=0;return -1;}
	int t=table[d1];//printf("%d %lld -> %d\n",p,x,t);
	int s=travel(t,d1);
	sel[p]=x;to[t]=p;
	vis[p]=0;
	if (s>=0)return s|(1<<(p-1));
	else return -1;
}

void print(int S){
	if (!S)return ;
	int min=0;
	for(int i=1;i<=k;++i){if((S>>(i-1))&1){min=i;break;}}
//	printf("travel %d\n",min);
	travel(min,a[min][pre[S]]);
	print(S^con[min][pre[S]]);
}

int main(){
	scanf("%d",&k);
	for(int i=1;i<=k;++i){
		scanf("%d",&c[i]);
		for(int j=1;j<=c[i];++j){
			std::cin>>a[i][j];
			table[a[i][j]]=i;sum+=a[i][j];tot[i]+=a[i][j];
		}
	}if (sum%k){printf("NO");return 0;}
	d=sum/k;
	for(int i=1;i<=k;++i)
		for(int j=1;j<=c[i];++j){
			start=a[i][j];
			con[i][j]=travel(i,a[i][j]);
		//	for(int i=1;i<=15;++i)assert(vis[i]==0);
		}
	f[0]=1;
	for(int S=1;S<(1<<k);++S){
		int min=0;
		for(int i=1;i<=k;++i){if((S>>(i-1))&1){min=i;break;}}
		for(register int i=1;i<=c[min];++i){
			if (con[min][i]!=-1&&((S|con[min][i])==S)&&f[S^con[min][i]]){
				f[S]=1;pre[S]=i;break;
			}
		}
	}
	if (!f[(1<<k)-1]){printf("NO");return 0;}
	else printf("YES\n");
	print((1<<k)-1);
	for(int i=1;i<=k;++i)std::cout<<sel[i]<<" "<<to[i]<<std::endl;
	return 0;
}