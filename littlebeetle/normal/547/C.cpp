#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
const int N=500002;
int n,q,x[N],i,j,k,a[N],pre[N],sum[N];
long long Ans,Sum;
bool f[N],g[N];
struct Nm{
	int p[8],cnt;
	void uzi(int x){
		while(x!=1){
			if(pre[x]!=p[cnt])
				p[++cnt]=pre[x];
			x/=pre[x];
		}
	}
	void dfs1(int i,int s,int ct){
		if(i==cnt+1){
			if(ct){
				if(ct%2)
					Ans+=sum[s];
				else
					Ans-=sum[s];
				sum[s]++;
			}
			return;
		}
		dfs1(i+1,s,ct);
		dfs1(i+1,s*p[i],ct+1);
	}
	void dfs2(int i,int s,int ct){
		if(i==cnt+1){
			if(ct){
				sum[s]--;
				if(ct%2)
					Ans-=sum[s];
				else
					Ans+=sum[s];
			}
			return;
		}
		dfs2(i+1,s,ct);
		dfs2(i+1,s*p[i],ct+1);
	}
	void inse(){
		dfs1(1,1,0);
	}
	void dele(){
		dfs2(1,1,0);
	}
}A[N];
void prework(){
	for(i=2;i<N;i++){
		if(!f[i])a[k++]=i,pre[i]=i;
		for(j=0;(!j||i%a[j-1])&&i*a[j]<N;j++){
			f[i*a[j]]=1;
			pre[i*a[j]]=a[j];
		}
	}
}
void init(){
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++){
		scanf("%d",x+i);
		A[i].uzi(x[i]);
	}
}
void work(){
	while(q--){
		scanf("%d",&i);
		if(g[i]==0){
			g[i]=1;
			A[i].inse();
			Sum++;
		}
		else{
			g[i]=0;
			A[i].dele();
			Sum--;
		}
		printf("%lld\n",Sum*(Sum-1)/2-Ans);
	}
	//while(1);
}
int main(){
	prework();
	init();
	work();
	return 0;
}