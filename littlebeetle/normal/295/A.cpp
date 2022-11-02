#include<cstdio>
const int N=100002;
int n,m,q,i,u,v,x,a[N],l[N],r[N],w[N],c[N];
long long p[N],t;
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	for(i=1;i<=m;i++)
		scanf("%d%d%d",l+i,r+i,w+i);
	for(i=1;i<=q;i++){
		scanf("%d%d",&u,&v);
		for(x=u-1;x;x-=x&-x)
			c[x]--;
		for(x=v;x;x-=x&-x)
			c[x]++;
	}
	for(i=1;i<=m;i++){
		t=0;
		for(x=i;x<=m;x+=x&-x)
			t+=c[x];
		t*=w[i];
		for(x=l[i]-1;x;x-=x&-x)
			p[x]-=t;
		for(x=r[i];x;x-=x&-x)
			p[x]+=t;			
	}
	for(i=1;i<=n;i++){
		t=0;
		for(x=i;x<=n;x+=x&-x)
			t+=p[x];
		printf("%lld ",t+a[i]);
	}
}