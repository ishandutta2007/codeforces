#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n;
char s[MAXN];
int cnt[26];
int main(){
	int _; scanf("%d",&_);
	while(_--){
		memset(cnt,0,sizeof(cnt));
		scanf("%s",s);
		n=strlen(s);
		for(int i=0; i<n; i++)
			cnt[s[i]-'a']++;
		int w=0;
		while(cnt[s[w]-'a']>1)
			cnt[s[w++]-'a']--;
		puts(s+w);
	}
	return 0;
}