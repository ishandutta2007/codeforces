#include<cstdio>
#include<cstring>
const int MAXN=105;
int q;
int cnt[30];
char s[MAXN],t[MAXN],p[MAXN];
bool ans;
int main(){
	scanf("%d",&q);
	while(q--){
		scanf("%s%s%s",s+1,t+1,p+1);
		memset(cnt,0,sizeof(cnt));
		for(int i=1;p[i];i++)
			++cnt[p[i]-'a'];
		int x=1;
		ans=1;
		for(int i=1;t[i];i++){
			if(t[i]==s[x]) x++;
			else if(cnt[t[i]-'a']) cnt[t[i]-'a']--;
			else{
				ans=0;
				break;
			}
		}
		if(s[x]) ans=0;
		if(ans) puts("YES");
		else puts("NO");
	}
	return 0;
}