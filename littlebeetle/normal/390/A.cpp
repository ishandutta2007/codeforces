#include<cstdio>
const int N=10002;
int n,cntx,cnty,x[N],y[N],a,b;
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d%d",&a,&b);
		if(!x[a])x[a]=1,cntx++;
		if(!y[b])y[b]=1,cnty++;
	}
	printf("%d",cntx<cnty?cntx:cnty);
}