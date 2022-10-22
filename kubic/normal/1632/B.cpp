#include <bits/stdc++.h>
using namespace std;
#define N 200005
int T,n,m;
void slv()
{
	scanf("%d",&n);m=0;while(1<<m<n) ++m;--m;
	for(int i=(1<<m)-1;i>=0;--i) printf("%d ",i);
	for(int i=(1<<m);i<n;++i) printf("%d ",i);puts("");
}
int main() {scanf("%d",&T);while(T--) slv();return 0;}