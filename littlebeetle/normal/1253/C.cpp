#include<cstdio>
#include<algorithm>
using namespace std;
const int N=300020;
typedef long long ll;
int n,m,i,a[N];
ll s,p[N];
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++){
		p[i%m]+=a[i];
		s+=p[i%m];
		printf("%lld ",s);
	}
}