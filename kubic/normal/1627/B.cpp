#include <bits/stdc++.h>
using namespace std;
#define N 100005
int T,n,m,a[N];
void slv()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j)
		a[(i-1)*m+j]=max(i-1,n-i)+max(j-1,m-j);
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;++i) printf("%d ",a[i]);puts("");
}
int main() {scanf("%d",&T);while(T--) slv();}