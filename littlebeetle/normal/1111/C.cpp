#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100002;
typedef long long ll;
int n,k,A,B,i,a[N];
ll min(ll x,ll y){
	return x<y?x:y;
}
ll dfs(int l,int r,int x,int y){
	if(x>y)return A;
	if(l==r)return B*(y-x+1);
	int z=x-1,mid=l+r>>1;
	while(z<y&&a[z+1]<=mid)z++;
	return min(1ll*B*(y-x+1)*(r-l+1),dfs(l,mid,x,z)+dfs(mid+1,r,z+1,y));
}
int main(){
	scanf("%d%d%d%d",&n,&k,&A,&B);
	for(i=1;i<=k;i++)
		scanf("%d",a+i);
	sort(a+1,a+k+1);
	printf("%I64d",dfs(1,1<<n,1,k));
}