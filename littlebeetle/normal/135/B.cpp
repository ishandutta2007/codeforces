#include<cstdio>
#include<cstdlib>
const int N=12;
int n=8,i,X[N],Y[N],x[N],y[N],us[N],id[N];
int dis(int a,int b,int c,int d){
	return (a-c)*(a-c)+(b-d)*(b-d);
}
void check(){
	int i;
	for(i=1;i<=8;i++)
		x[i]=X[id[i]],y[i]=Y[id[i]];
	int a=x[1]+x[3]>>1,b=y[1]+y[3]>>1;
	if(dis(a,b,x[1],y[1])!=dis(a,b,x[2],y[2]))return;
	if(dis(a,b,x[1],y[1])!=dis(a,b,x[3],y[3]))return;
	if(dis(a,b,x[1],y[1])!=dis(a,b,x[4],y[4]))return;
	if(y[2]-b!=a-x[1])return;
	if(x[2]-a!=y[1]-b)return;
	if(y[2]-b!=x[3]-a)return;
	if(x[2]-a!=b-y[3])return;
	if(b-y[3]!=a-x[4])return;
	if(x[3]-a!=b-y[4])return;
	a=x[5]+x[7]>>1,b=y[5]+y[7]>>1;
	if(a!=(x[6]+x[8]>>1))return;
	if(b!=(y[6]+y[8]>>1))return;	
	if(dis(a,b,x[5],y[5])!=dis(a,b,x[6],y[6]))return;
	if(dis(a,b,x[5],y[5])!=dis(a,b,x[7],y[7]))return;
	if(dis(a,b,x[5],y[5])!=dis(a,b,x[8],y[8]))return;
	printf("YES\n");
	for(i=1;i<=4;i++)
		printf("%d ",id[i]);
	printf("\n");
	for(i=5;i<=8;i++)
		printf("%d ",id[i]);
	exit(0);	
			
}
void dfs(int i){
	if(i==9){
		check();
		return;
	}
	for(int j=1;j<=n;j++){
		if(!us[j]){
			us[j]=1;
			id[i]=j;
			dfs(i+1);
			us[j]=0;
		}
	}
}
int main(){
	for(i=1;i<=n;i++){
		scanf("%d%d",X+i,Y+i);
		X[i]*=2;Y[i]*=2;
	}
	dfs(1);
	printf("NO");
}