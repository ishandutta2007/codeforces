#include<cstdio>
#include<cstring>
const int MAXN=2e6+5;
int n;
char s[MAXN];
int ans[MAXN];
int main(){
	//freopen("C.in","r",stdin);
	int t;scanf("%d",&t);
	while(t--){
		scanf("%s",s+1);
		n=strlen(s+1);
		ans[0]=0;
		for(int i=3; i<=n-2; i++)
			if(s[i-2]=='t'&&s[i-1]=='w'&&s[i]=='o'&&s[i+1]=='n'&&s[i+2]=='e')
				ans[++ans[0]]=i,s[i]='a';
		for(int i=2; i<n; i++){
			if(s[i-1]=='o'&&s[i]=='n'&&s[i+1]=='e') ans[++ans[0]]=i,s[i]='a';
			if(s[i-1]=='t'&&s[i]=='w'&&s[i+1]=='o') ans[++ans[0]]=i,s[i]='a';
		}
		printf("%d\n",*ans);
		for(int i=1; i<=*ans; i++) printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}