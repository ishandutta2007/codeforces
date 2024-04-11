#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n,c1[26],c2[26];
char s[MAXN],t[MAXN];
bool ans;
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		scanf("%s",s+1);
		scanf("%s",t+1);
		memset(c1,0,sizeof(c1));
		memset(c2,0,sizeof(c2));
		int cnt=0;
		for(int i=1; i<=n; i++){
			int c=s[i]-'a';
			for(int j=c+1; j<26; j++)
				cnt^=c1[j];
			c1[c]++;
		}
		for(int i=1; i<=n; i++){
			int c=t[i]-'a';
			for(int j=c+1; j<26; j++)
				cnt^=c2[j];
			c2[c]++;
		}
		ans=1;
		for(int i=0; i<26; i++)
			if(c1[i]!=c2[i]) ans=0;
		if(ans){
			ans=(cnt&1)^1;
			for(int i=0; i<26; i++)
				if(c1[i]>=2) ans=1;
		}
		if(ans) puts("YES");
		else puts("NO");
	}
	return 0;
}