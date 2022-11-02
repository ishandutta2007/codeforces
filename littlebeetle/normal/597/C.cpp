#include<cstdio>
typedef long long ll;
const int N=100002,K=11;
int n,k,i,j,a;
struct BIT{
	ll c[N];
	void Update(int x,ll y){
		while(x<=n)
			c[x]+=y,x+=x&-x;
	}
	ll Query(int x){
		ll s=0;
		while(x)
			s+=c[x],x-=x&-x;
		return s;
	}
}T[K];
void init(){
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++){
		scanf("%d",&a);
		T[0].Update(a,1);
		for(j=1;j<=k;j++)
			T[j].Update(a,T[j-1].Query(a-1));
	}
	printf("%lld",T[k].Query(n));
	//while(1);
}
int main(){
	init();
	return 0;
}