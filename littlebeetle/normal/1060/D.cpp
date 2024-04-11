#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100002;
int n,l[N],r[N],i;
long long ans;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d%d",l+i,r+i);
	sort(l+1,l+n+1);
	sort(r+1,r+n+1);
	for(i=1;i<=n;i++)
		ans+=max(l[i],r[i]);
	printf("%I64d",ans+n);
}