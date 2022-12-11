#include<cstdio>
#include<algorithm>
using namespace std;

char c[101],s[101];
int main(){
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		int n;
		scanf("%d%s",&n,c+1);
		for(int i=1;i<=n;i++)
			s[i]=c[i];
		sort(s+1,s+n+1);
		int ans=0;
		for(int i=1;i<=n;i++)
			ans+=(c[i]!=s[i]);
		printf("%d\n",ans);
	}
}