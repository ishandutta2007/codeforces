#include<cstdio>
const int N=102;
int n,m,i,a[N],x,y;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	scanf("%d",&m);
	while(m--){
		scanf("%d%d",&x,&y);
		a[x-1]+=y-1;
		a[x+1]+=a[x]-y;
		a[x]=0;
	}
	for(i=1;i<=n;i++)
	printf("%d\n",a[i]);
}