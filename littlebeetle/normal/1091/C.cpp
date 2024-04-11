#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100002;
typedef long long ll;
int n,i,m;
ll a[N];
ll G(int x){
	int y=n/x;
	return 1ll*x*(y-1)*y/2+y;
}
int main(){
	scanf("%d",&n);
	for(i=1;i*i<=n;i++)
	if(n%i==0){
		a[++m]=G(i);
		if(i*i!=n)
		a[++m]=G(n/i);
	}
	sort(a+1,a+m+1);
	for(i=1;i<=m;i++)
		printf("%lld ",a[i]);
}