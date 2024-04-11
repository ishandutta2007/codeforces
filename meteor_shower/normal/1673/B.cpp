#include<cstdio>
#include<cstring>
const int N=2e5+5;
const int M=26;
bool vis[M];
int cnt;
int n,T;
char s[N];
inline void Init(){
	scanf("%s",s+1);
	memset(vis,0,sizeof(vis));
	n=strlen(s+1);
	cnt=0;
	for(int i=1;i<=n;i++)
		if(!vis[s[i]-'a']){
			vis[s[i]-'a']=1;
			cnt++;
		}
	return ;
}
inline bool Check(){
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=cnt;i++){
		if(vis[s[i]-'a']) return 0;
		vis[s[i]-'a']=1;
	}
	for(int i=cnt+1;i<=n;i++)
		if(s[i]!=s[i-cnt]) return 0;
	return 1;
}
int main(){
	for(scanf("%d",&T);T;T--){
		Init();
		if(Check()) puts("YES");
		else puts("NO");
	}
	return 0;
}