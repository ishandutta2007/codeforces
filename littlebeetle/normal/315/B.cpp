#include<cstdio>
const int N=400200;
int n,m,i,a[N],x,d,opt;
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	while(m--){
		scanf("%d",&opt);
		if(opt==1){
			scanf("%d%d",&i,&x);
			a[i]=x-d;
		}
		if(opt==2){
			scanf("%d",&x);
			d+=x;
		}
		if(opt==3){
			scanf("%d",&x);
			printf("%d\n",a[x]+d);
		}
	}
}