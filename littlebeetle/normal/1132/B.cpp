#include<cstdio>
#include<algorithm>
using namespace std;
const int N=300002;
int n,m,i,a[N];
long long s;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i),s+=a[i];
	sort(a+1,a+n+1,cmp);
	scanf("%d",&m);
	while(m--){
		scanf("%d",&i);
		printf("%lld\n",s-a[i]);
	}
}