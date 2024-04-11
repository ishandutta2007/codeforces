#include<cstdio>
const int N=2000002;
int n,m,K,D,o,p[N],i,j,k,a,b,c,h[N],t[N],v[N],w[N],fr[N],u[N],ans[N],len;
long long d[N];
int main(){
	scanf("%d%d%d",&n,&m,&K);
	for(i=k=1;i<=m;i++){
		scanf("%d%d%d",&a,&b,&c);
		t[++k]=h[a];h[a]=k;v[k]=b;w[k]=c;
		t[++k]=h[b];h[b]=k;v[k]=a;w[k]=c;
	}
	D=1;
	while(D<n+2)
		D<<=1;
	for(i=0;i<=D;i++)
		p[i+D]=i,d[i]=1ll<<60;
	d[1]=0;
	for(i=D-1;i;i--)
		p[i]=d[p[i<<1]]<d[p[i<<1|1]]?p[i<<1]:p[i<<1|1];
		if(K){
	for(o=1;o<=n;o++){
		i=p[1];
		if(i!=1){
			if(fr[i]==0)
				break;
			ans[++len]=fr[i]>>1;
			if(len==K)
				break;
		}
		for(j=h[i];j;j=t[j])
			if(!u[v[j]]&&d[v[j]]>d[i]+w[j]){
				d[v[j]]=d[i]+w[j];
				fr[v[j]]=j;
				for(k=v[j]+D>>1;k;k>>=1)
					p[k]=d[p[k<<1]]<d[p[k<<1|1]]?p[k<<1]:p[k<<1|1];
			}
		u[i]=1;
		d[i]=1ll<<60;
		for(k=i+D>>1;k;k>>=1)
			p[k]=d[p[k<<1]]<d[p[k<<1|1]]?p[k<<1]:p[k<<1|1];
	}
}
	printf("%d\n",len);
	for(i=1;i<=len;i++)
		printf("%d ",ans[i]);
	return 0;
}