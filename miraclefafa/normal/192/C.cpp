#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int i,j,n,len,ans,dp[200][200];;
char st[10010];
int main() {
	scanf("%d",&n);
	for (i='a';i<='z';i++) for (j='a';j<='z';j++) dp[i][j]=-1000000000;
	for (i=1;i<=n;i++) {
		scanf("%s",&st);len=strlen(st);dp[st[0]][st[0]]=max(0,dp[st[0]][st[0]]);
		for (j='a';j<='z';j++) dp[j][st[len-1]]=max(dp[j][st[len-1]],dp[j][st[0]]+len);
	}
	ans=0;
	for (i='a';i<='z';i++) ans=max(dp[i][i],ans);
	printf("%d\n",ans);
}