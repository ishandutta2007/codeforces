#include<cstdio>
int n,s1,s2;
char s[100005];
int main(){
	scanf("%d",&n);
	scanf("%s",s);
	for(int i=0; i<n; i++)
		if(s[i]=='L') s1++;
		else s2++;
	printf("%d\n",s2+s1+1);
	return 0;
}