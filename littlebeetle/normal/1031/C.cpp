#include<cstdio>
const int N=100002;
int a,b,i,f[N],p[N],u,q[N],v;
long long x;
int main(){
	scanf("%d%d",&a,&b);
	while((x+2)*(x+1)/2<=a+b)
		x++;
	for(i=x;i;i--)
		if(i<=a){
			a-=i;
			f[i]=1;
			p[++u]=i;
		}
	printf("%d\n",u);
	for(i=1;i<=u;i++)
		printf("%d ",p[i]);
	printf("\n%lld\n",x-u);
	for(i=1;i<=x;i++)
		if(f[i]==0)
			printf("%d ",i);
}