#include<cstdio>
const int N=1200002;
int n,m,D,i,j,k,a,id[N],x,y,f[N];
long long ans;
void init(){
	scanf("%d%d",&n,&m);
	for(D=1;D<n+2;D<<=1);
	for(i=1;i<D*2;i++)f[i]=n;
	for(i=1;i<=n;i++){
		scanf("%d",&a);
		id[a]=i;
	}
}
void Swap(int &x,int &y){
	int t=x;x=y;y=t;
}
int min(int x,int y){
	return x<y?x:y;
}
void Update(int x,int y,int z){
	for(x+=D-1,y+=D+1;x^y^1;x>>=1,y>>=1){
		if(~x&1)f[x^1]=min(f[x^1],z);
		if(y&1)f[y^1]=min(f[y^1],z);
	}
}
void work(){
	while(m--){
		scanf("%d%d",&x,&y);
		x=id[x];
		y=id[y];
		if(x>y)
			Swap(x,y);
		Update(1,x,y-1);
	}
	for(i=2;i<D*2;i++)
		f[i]=min(f[i],f[i>>1]);
	for(i=1;i<=n;i++)
		ans+=f[i+D]-i+1;
	printf("%lld",ans);
}
int main(){
	init();
	work();
	//while(1);
}