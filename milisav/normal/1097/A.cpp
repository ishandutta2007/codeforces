#include<bits/stdc++.h>
char s[5];
char t[5];
int main()
{
	scanf("%s",s);
	bool p=false;
	for(int i=0;i<5;i++) {
		scanf("%s",t);
		if(t[0]==s[0] || t[1]==s[1]) p=true;
	}
	if(p) printf("YES");
	else printf("NO");
	return 0;
}