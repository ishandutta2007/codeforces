#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=5009;

int n,m,f[N][N],ans;
char a[N],b[N]; 

int main() {
	scanf("%d%d%s%s",&n,&m,a+1,b+1);
	rep(i,1,n) rep(j,1,m) {
		if(a[i]==b[j]) f[i][j]=f[i-1][j-1]+2;
		f[i][j]=max(f[i][j],max(f[i-1][j],f[i][j-1])-1);
		ans=max(ans,f[i][j]);
	}
	printf("%d\n",ans);
	return 0;
}