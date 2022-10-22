#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
int cnt[26],n,t;
char s[maxn];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		memset(cnt,0,sizeof cnt);
		for(ri i=1;i<=n;++i){
			scanf("%s",s+1);
			ri l=strlen(s+1);
			for(ri i=1;i<=l;++i)++cnt[s[i]-'a'];
		}
		bool flag=false;
		for(ri i=0;i<26;++i)flag|=(cnt[i]%n);
		puts(flag?"NO":"YES");
	}
	return 0;
}