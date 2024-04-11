#include<cstdio>
int a,b,n;
char s[51];
main(){
	scanf("%d%s",&n,s+1);
	for(int i=1;(i<<1)<=n;++i)
		if((s[i]==52||s[i]==55)&&(s[n-i+1]==52||s[n-i+1]==55))
			a+=s[i],b+=s[n-i+1];
		else return puts("NO"),0;
	puts(a==b?"YES":"NO");
}