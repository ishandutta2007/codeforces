#include<cstdio>
#include<cstring>
int l,n;
char s[101];
main(){
    scanf("%d",&n);
    while(n--)scanf("%s",s+1),l=strlen(s+1),l>10?printf("%c%d%c\n",s[1],l-2,s[l]):printf("%s\n",s+1);
}