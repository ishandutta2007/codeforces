#include <bits/stdc++.h>
using namespace std;
#define N 200005
int T,n,m;char a[N];
void slv()
{
	scanf("%d %s",&n,a+1);
	if(n==1) {puts("YES");return;}
	if(n>2) {puts("NO");return;}
	puts(a[1]!=a[2]?"YES":"NO");
}
int main() {scanf("%d",&T);while(T--) slv();return 0;}