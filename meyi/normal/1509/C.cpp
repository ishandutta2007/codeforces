#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e3+10;
int a[maxn],n;
ll f[maxn][maxn];
int main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i)scanf("%d",a+i);
	sort(a+1,a+n+1);
	for(ri len=1;len<=n;++len)
		for(ri i=1;i+len-1<=n;++i){
			ri j=i+len-1;
			f[i][j]=min(f[i][j-1],f[i+1][j])+a[j]-a[i];
		}
	printf("%lld",f[1][n]);
	return 0;
}