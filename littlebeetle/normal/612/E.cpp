#include<cstdio>
#include<vector>
using namespace std;
const int N=1000002;
int n,i,j,k,l,S,p[N],f[N],q[N],s[N],vis[N],L[N],u,v;
int F(int x){
	return x==f[x]?x:f[x]=F(f[x]);
}
void init(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		f[i]=i,s[i]=1;
	for(i=1;i<=n;i++){
		scanf("%d",p+i);
		u=F(i);v=F(p[i]);
		if(u!=v){
			s[v]+=s[u];
			s[u]=0;
			f[u]=v;
		}
	}
}
void d1(int i){
	int j;
	S=s[i];
	l=s[i]+1>>1;
	for(j=i;l;j=p[j],l--);
	while(S--){
		q[i]=j;
		i=p[i];
		j=p[j];
	}
}
void d2(int i,int j){
	S=s[i];
	while(S--){
		q[i]=j;
		q[j]=p[i];
		i=p[i];
		j=p[j];
	}
}
void work(){
	for(j=1;j<=n;j++){
		i=F(j);
		if(i==j)
		if(!vis[i]){
			vis[i]=1;
			if(s[i]&1)
				d1(i);
			else{
				if(L[s[i]]){
					d2(i,L[s[i]]);
					L[s[i]]=0;
				}
				else
					L[s[i]]=i;
			}
		}
	}
	for(i=1;i<=n;i++)
		if(!q[i]){
			printf("-1");
			return;
	}
	for(i=1;i<=n;i++)
		printf("%d ",q[i]);
}
int main(){
	init();
	work();
}