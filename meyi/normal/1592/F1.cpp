#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=510;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
int ans,m,n;
bool a[maxn][maxn],f[maxn][maxn],flag;
char s[maxn][maxn];
int main(){
	scanf("%d%d",&n,&m);
	for(ri i=1;i<=n;++i){
		scanf("%s",s[i]+1);
		for(ri j=1;j<=m;++j)f[i][j]=(s[i][j]=='B');
	}
	for(ri i=n;i;--i)
		for(ri j=m;j;--j){
			a[i][j]=f[i][j]^f[i+1][j]^f[i][j+1]^f[i+1][j+1];
			ans+=a[i][j];
			if(i<n&&j<m)flag|=(a[i][j]&a[n][j]&a[i][m]&a[n][m]);
		}
	printf("%d",ans-flag);
	return 0;
}