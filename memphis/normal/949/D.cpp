#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<set>
#include<iostream>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=200005;

long long n,d,a[N],i,ans,b;
int main(){
	scanf("%I64d%I64d%I64d",&n,&d,&b);

	for(i=1;i<=n;i++)
		scanf("%I64d",&a[i]),a[i]+=a[i-1];
	for(i=1;i<=n+1>>1;i++)
		ans=max(ans,max(i-a[min(n,i*(d+1))]/b,i-(a[n]-a[max(0ll,n-i*(d+1))])/b));
	printf("%I64d\n",ans);
}