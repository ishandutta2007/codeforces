#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200002;
struct p{
	int a,b,id;
	bool operator<(const p &k)const{
		return k.a>a;
	}
}x[N];
int T,n,i;
long long sum1,sum2;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		sum1=sum2=0;
		for(i=1;i<=n*2-1;i++)
			scanf("%d%d",&x[i].a,&x[i].b),x[i].id=i;
		sort(x+1,x+n*2);
		x[2*n]=x[2*n-1];
		for(i=1;i<=n;i++){
			sum1+=x[i*2-1].b;
			sum2+=x[i*2].b;
		}
		printf("YES\n");
		if(sum1>=sum2){
			for(i=1;i<=n;i++)
				printf("%d ",x[i*2-1].id);
		}
		else{
			for(i=1;i<=n;i++)
				printf("%d ",x[i*2].id);
		}
		printf("\n");
	}
//	while(1);
}