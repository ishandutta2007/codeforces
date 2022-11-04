#include<bits/stdc++.h>
using namespace std;
const int N=5009;

int n,c[N],f[N][N];

int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	n=unique(c+1,c+n+1)-c-1;
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int len=2;len<=n;len++)
		for(int l=1;l<=n-len+1;l++) {
			int r=l+len-1;
			f[l][r]=(c[l]==c[r] ? f[l+1][r-1]+1 : min(f[l][r-1],f[l+1][r])+1);
		}
	printf("%d",f[1][n]);
	return 0;
}