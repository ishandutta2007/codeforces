#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n,k;
char s[MAXN];
int cnt[26];
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d%d",&n,&k);
		scanf("%s",s);
		memset(cnt,0,sizeof(cnt));
		for(int i=0; i<n; i++)
			cnt[s[i]-'a']++;
		for(int _=0; _<k; _++){
			int x=0;
			while(cnt[x]) x++;
			x=min(x,n/k);
			putchar(x+'a');
			while(x--)
				cnt[x]--;
		}
		puts("");
	}
	return 0;
}