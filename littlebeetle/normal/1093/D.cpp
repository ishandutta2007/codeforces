#include<cstdio>
const int N=600002,M=998244353;
typedef long long ll;
int T,n,m,i,j,k,a,b,h[N],t[N],v[N],c[N],x,y,f;
ll ans;
void init(){
	ans=1;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		h[i]=0;
	k=0;
	while(m--){
		scanf("%d%d",&a,&b);
		t[++k]=h[a];h[a]=k;v[k]=b;
		t[++k]=h[b];h[b]=k;v[k]=a;
	}
	for(i=1;i<=n;i++)
		c[i]=0;
}
void dfs(int i){
	if(c[i]&1)
		x++;
	else
		y++;
	for(int j=h[i];j;j=t[j])
		if(c[v[j]]){
			if(c[v[j]]==c[i])
				f=1;
		}
		else{
			c[v[j]]=c[i]^3;
			dfs(v[j]);
		}
}
ll ksm(int p){
	ll s=1,x=2;
	while(p){
		if(p&1)
			s=s*x%M;
		x=x*x%M;
		p>>=1;
	}
	return s;
}
int main(){
	scanf("%d",&T);
	while(T--){
		init();
		f=0;
		for(i=1;i<=n;i++)
			if(!c[i]){
				x=y=0;
				c[i]=1;
				dfs(i);
				ans=ans*(ksm(x)+ksm(y))%M;
			}
		printf("%I64d\n",f?0:ans);
	}
	//while(1);
}