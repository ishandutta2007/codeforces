#include<cstdio>
#include<cstring>
typedef long long LL;
char s[55],t[55];
int q,lent,lens;
inline void Solve(){
	scanf("%s",s+1);
	lens=strlen(s+1);
	scanf("%s",t+1);
	lent=strlen(t+1);
	if(lent>1){
		for(int i=1;t[i];i++)
			if(t[i]=='a'){
				puts("-1");
				return ;
			}
	}
	if(lent==1&&t[1]=='a'){
		puts("1");
		return ;
	}
	LL ans=1ll<<lens;
	printf("%lld\n",ans);
	return ;
}
int main(){
	for(scanf("%d",&q);q;q--)
		Solve();
	return 0;
}