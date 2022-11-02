#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1000002;
int n,m,k,i,a[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;i++)
		scanf("%d",a+i),a[i]--;
	sort(a+1,a+n+1,cmp);
	for(i=0;i<=n;i++){
		k+=a[i];
		if(k>=m){
			printf("%d",i);
			return 0;
		}
	}
	printf("-1");
	return 0;
}