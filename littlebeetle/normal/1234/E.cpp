#include<cstdio>
const int N=200002;
typedef long long ll;
int n,m,i,a[N];
ll f[N],x,y,c[N];
void Update(int x,int y){
	while(x)
		c[x]+=y,x-=x&-x;
}
ll Query(int x){
	ll s=0;
	while(x<=n)
		s+=c[x],x+=x&-x;
	return s;
}
int main(){
	scanf("%d%d",&n,&m);
	//for(i=1;i<=n;i++)
	//	f[i]=1ll*i*(i-1)+1+1ll*(i+1)*(n-i);
	for(i=1;i<=m;i++)
		scanf("%d",a+i);
	for(i=1;i<m;i++){
		x=a[i];
		y=a[i+1];
		if(x!=y){
			if(x>y)
				x^=y^=x^=y;
			Update(x-1,1-x);
			Update(x,x);
			Update(y-1,y-2*x-1);
			Update(y,2*x-y);
			Update(n,y-x);
		}
	}
	for(i=1;i<=n;i++)
		printf("%lld ",Query(i));
	//while(1);
}