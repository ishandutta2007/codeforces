#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1000002;
struct p{
	int a,id;
	bool operator<(p const &k)const{
		return k.a<a;
	}
}x[N];
int n,m,k,i,j,l,g[N];
long long sum;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;i++){
		scanf("%d",&x[i].a);
		x[i].id=i;
	}
	sort(x+1,x+n+1);
	for(i=1;i<=m*k;i++){
		sum+=x[i].a;
		g[x[i].id]=1;
	}
	printf("%lld\n",sum);
	for(i=1;i<=n;i++){
		j+=g[i];
		if(j==m&&l!=k-1){
			printf("%d ",i);
			j=0;
			l++;
		}
	}
}