#include<cstdio>
#include<cstring>
const int MAXN=1e5+5;
int n;
char s[MAXN];
int main(){
	int t;scanf("%d",&t);
	while(t--){
		scanf("%s",s+1);
		n=strlen(s+1);
		bool ans=0;
		for(int i=1;i<n;i++)
			if(s[i]==s[i+1]&&s[i]!='?') ans=1;
		if(ans){
			puts("-1");
			continue;
		}
		for(int i=1;i<=n;i++){
			if(s[i]!='?') continue;
			if(i<n&&s[i+1]!='?'){
				if(i==1){
					if(n>1&&s[2]=='a') s[1]='b';
					else s[1]='a';
				}else if(s[i-1]==s[i+1]){
					if(s[i-1]=='a') s[i]='b';
					else s[i]='a';
				}else s[i]='a'^'b'^'c'^s[i-1]^s[i+1];
			}else if(s[i-1]=='a') s[i]='b';
			else s[i]='a';
		}
		s[n+1]=0;
		puts(s+1);
	}
	return 0;
}