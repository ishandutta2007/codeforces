#include<cstdio>
const int N=100002;
int n,m,i,j,k,a[N],b[N],c[N],h[N],t[N],v[N],d[N],q[N],id[N],cnt,s,e,sum;
void init(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)
		scanf("%d%d%d",a+i,b+i,c+i);
}
int max(int x,int y){
	return x>y?x:y;
}
void add(int a,int b){
	t[++k]=h[a];h[a]=k;v[k]=b;
}
bool ok(int x){
	for(i=1;i<=n;i++)
		h[i]=0,d[i]=0;
	k=0;
	for(i=1;i<=m;i++)
		if(c[i]>x)
			add(a[i],b[i]),d[b[i]]++;
	s=1;e=0;cnt=0;
	for(i=1;i<=n;i++)
		if(!d[i]){
			q[++e]=i;
			id[i]=++cnt;
		}
	while(s<=e){
		i=q[s++];
		for(j=h[i];j;j=t[j]){
			k=v[j];
			d[k]--;
			if(!d[k]){
				q[++e]=k;
				id[k]=++cnt;
			}
		}
	}
	return e==n;
}
void work(){
	int l,r,mid;
	l=0;
	for(i=1;i<=m;i++)
		r=max(r,c[i]);
	while(l<r){
		mid=l+r>>1;
		if(ok(mid))
			r=mid;
		else
			l=mid+1;
	}
	ok(r);
	for(i=1;i<=m;i++)
		if(c[i]<=r)
			sum+=id[a[i]]>id[b[i]];
	printf("%d %d\n",r,sum);
	for(i=1;i<=m;i++)
		if(c[i]<=r&&id[a[i]]>id[b[i]])
			printf("%d ",i);
}
int main(){
	init();
	work();
}