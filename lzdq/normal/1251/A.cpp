#include<cstdio>
#include<cstring>
const int N=505;
char s[N],ch;
bool vis[26];
inline void Query(){
	memset(vis,0,sizeof(vis));
	int sum=0;
	for(int i=0;s[i];i++)
		if(ch!=s[i]){
			if(sum&1) vis[ch-'a']=1;
			ch=s[i];sum=1;
		}
		else sum++;
	if(sum&1) vis[ch-'a']=1;
	for(int i=0;i<26;i++)
		if(vis[i]) putchar(i+'a');
	puts("");
}
int main(){
	int t;scanf("%d",&t);
	while(t--){
		scanf("%s",s);
		Query();
	}
	return 0;
}