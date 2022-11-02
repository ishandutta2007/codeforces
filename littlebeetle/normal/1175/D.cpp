#include<cstdio>
#include<algorithm>
using namespace std;
const int N=300002;
typedef long long ll;
int n,i,k,a[N];
ll s[N],ans;
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	for(i=n;i;i--)
		s[i]=a[i]+s[i+1];
	sort(s+2,s+n+1,cmp);
	for(i=1;i<=k;i++)
		ans+=s[i];
	printf("%I64d",ans);
	//while(1);
}