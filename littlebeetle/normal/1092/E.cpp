#include<cstdio>
const int N=2002;
int n,m,f[N],i,j,k,a,b,h[N],t[N],v[N],d1[N],d2[N],D1[N],D2[N],L[N],l[N],dis[N],ans=1<<30,x,y,u[N],s[N];
int p(int x){
	return x==f[x]?x:f[x]=p(f[x]);
}
int max(int x,int y){
	return x>y?x:y;
}
int min(int x,int y){
	return x<y?x:y;
}
void dfs(int i,int fa){
	d1[i]=d2[i]=0;
	for(int j=h[i];j;j=t[j])
		if(v[j]!=fa){
			dfs(v[j],i);
			if(d1[v[j]]+1>=d1[i])
				d2[i]=d1[i],d1[i]=d1[v[j]]+1;
			else
				if(d1[v[j]]+1>d2[i])
					d2[i]=d1[v[j]]+1;
		}
}
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		f[i]=i,L[i]=1<<30;
	while(m--){
		scanf("%d%d",&a,&b);
		if(p(a)!=p(b))
			f[p(a)]=b;
		t[++k]=h[a];h[a]=k;v[k]=b;
		t[++k]=h[b];h[b]=k;v[k]=a;
	}
	for(i=1;i<=n;i++){
		u[p(i)]++;
		dfs(i,0);
		D1[i]=d1[i];
		D2[i]=d2[i];
		dis[p(i)]=max(dis[p(i)],D1[i]+D2[i]);
		if(D1[i]<L[p(i)])
			L[p(i)]=D1[i],l[p(i)]=i;
	}
	for(i=1;i<=n;i++){
		x=D1[i];y=D2[i];
		for(j=1;j<=n;j++)
			if(u[j]&&j!=p(i)){
				if(L[j]+1>=x)
					y=x,x=L[j]+1;
				else
					if(L[j]+1>y)
						y=L[j]+1;
			}
		ans=min(ans,s[i]=x+y);
	}
	for(i=1;i<=n;i++)
		ans=max(ans,dis[i]);
	printf("%d\n",ans);
	for(i=1;i<=n;i++)
		if(s[i]<=ans)
			break;
	for(j=1;j<=n;j++)
		if(u[j]&&j!=p(i))
			printf("%d %d\n",i,l[j]);
}