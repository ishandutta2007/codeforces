#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e6+5,SIZ=1<<20|5;
int n;
char s[MAXN];
int cnt[SIZ];
int ans;
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
		s[i]-='a';
	for(int i=1;i<=n;i++){
		int a=0;
		for(int j=i;j<=n;j++){
			if(a&(1<<s[j])) break;
			a|=1<<s[j];
			cnt[a]=j-i+1;
		}
	}
	for(int i=1;i<1<<20;i++){
		if(cnt[i]) continue;
		for(int j=0;j<20;j++)
			if(i&(1<<j)) cnt[i]=max(cnt[i],cnt[i^(1<<j)]);
	}
	for(int i=1;i<1<<20;i++){
		int t=~i;
		t&=(1<<20)-1;
		ans=max(ans,cnt[i]+cnt[t]);
	}
	printf("%d\n",ans);
	return 0;
}