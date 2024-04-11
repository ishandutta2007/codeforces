#include<cstdio>
#include<algorithm>
#include<cstring>
typedef long long ll;
using namespace std;
const int MAXN=1e6+5;
int n,m;
char s[MAXN],t[MAXN];
int pre[MAXN][3][3];
ll ans;
int main(){
	scanf("%s",s+1);
	scanf("%s",t+1);
	n=strlen(s+1);
	m=strlen(t+1);
	for(int i=1; i<=n; i++)
		s[i]%=3;
	for(int i=1; i<=m; i++)
		t[i]%=3;
	for(int i=2; i<=m; i++){
		memcpy(pre[i],pre[i-1],sizeof(pre[i]));
		pre[i][t[i-1]][t[i]]++;
	}
	for(int i=1,l=1,r=1; i<=n; i++,r=min(r+1,m)){
		while(r<m&&s[i]!=t[r]) r++;
		ans+=r-l+1;
		if(i>1&&s[i-1]!=s[i]) ans-=pre[r][s[i]][s[i-1]]-pre[l-1][s[i]][s[i-1]];
		if(s[i]==t[l]) l=min(l+1,m+1);
	}
	printf("%lld\n",ans);
	return 0;
}