#include<cstdio>
int T;
char s[5];
int main(){
	for(scanf("%d",&T);T;T--){
		scanf("%s",s+1);
		int ans=(s[1]-'a')*25;
		ans+=s[2]-'a'+1;
		if(s[2]>s[1]) ans--;
		printf("%d\n",ans);
	}
	return 0;
}