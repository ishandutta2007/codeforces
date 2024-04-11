#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200002;
int n,x[N],ans=1<<30,i;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",x+i);
	sort(x+1,x+n+1);
	for(i=1;i<=n/2;i++)
		ans=min(ans,x[i+n/2]-x[i]);
	printf("%d",ans);
	//while(1);
}