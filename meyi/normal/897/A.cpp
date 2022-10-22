#include<cstdio>
int c1,c2,l,m,n,r;
char s[101];
main(){
	scanf("%d%d%s",&n,&m,s);
	while(m--){
		scanf("%d%d %c %c",&l,&r,&c1,&c2);
		for(register int i=l-1;i<r;++i)if(s[i]==c1)s[i]=c2;
	}
	printf("%s",s);
}