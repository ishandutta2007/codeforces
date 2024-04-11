#include<cstdio>
const int N=1000006;
int n,m,i,j,k,a[N],d[N],f[N],opt,l,r;
long long c[N],s;
int p(int x){
	return x==f[x]?x:f[x]=p(f[x]);
}
void add(int x,int y){
	while(y<=n)
		c[y]+=x,y+=y&-y;
}
long long sum(int x){
	for(s=0;x;x-=x&-x)
		s+=c[x];
	return s;
}
int main(){
	for(i=1;i<N;i++)
		for(j=i;j<N;j+=i)
			d[j]++;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",a+i);
		add(a[i],i);
		if(a[i]>2)
			f[i]=i;
		else
			f[i]=i+1;
	}
	f[i]=i;
	while(m--){
		scanf("%d%d%d",&opt,&l,&r);
		if(opt==1){
			while((l=p(l))<=r){
				add(-a[l],l);
				a[l]=d[a[l]];
				add(a[l],l);
				if(a[l]<=2)
					f[l]=l+1;
				l++;
			}
		}
		else
			printf("%lld\n",sum(r)-sum(l-1));
	}
}