#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=510;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
int f[maxn][maxn],n;
char s[maxn];
inline int merge(int x,int y,int z){
	return f[x][y]+f[y+1][z]-(s[x]==s[z]);
}
int main(){
	scanf("%d%s",&n,s+1);
	memset(f,0x3f,sizeof f);
	for(ri i=1;i<=n;++i)f[i][i]=1;
	for(ri len=2;len<=n;++len)
		for(ri i=1;i+len-1<=n;++i){
			ri j=i+len-1;
			for(ri k=i;k<j;++k)ckmin(f[i][j],merge(i,k,j));
		}
	printf("%d",f[1][n]);
	return 0;
}