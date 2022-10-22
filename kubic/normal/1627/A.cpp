#include <bits/stdc++.h>
using namespace std;
#define N 55
int T,n,m,n1,m1;bool fl,flN,flM;char a[N][N];
void slv()
{
	scanf("%d %d %d %d",&n,&m,&n1,&m1);fl=flN=flM=0;
	for(int i=1;i<=n;++i) scanf("%s",a[i]+1);
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) if(a[i][j]=='B') fl=1;
	for(int i=1;i<=m;++i) if(a[n1][i]=='B') flN=1;
	for(int i=1;i<=n;++i) if(a[i][m1]=='B') flM=1;
	if(!fl) {puts("-1");return;}if(a[n1][m1]=='B') {puts("0");return;}
	if(flN || flM) {puts("1");return;}puts("2");
}
int main() {scanf("%d",&T);while(T--) slv();}