#include<cstdio>
#include<map>
using namespace std;
int n,a,b;
long long ans;
map<int,int>x,y;
map<long long,int>z;
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d%d",&a,&b);
		ans+=x[a];
		ans+=y[b];
		x[a]++;
		y[b]++;
		ans-=z[(1ll*a<<30)+b];
		z[(1ll*a<<30)+b]++;
	}
	printf("%lld",ans);

}