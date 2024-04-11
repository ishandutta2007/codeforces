#include<cstdio>
#include<cstring>

#define ran 101101

int len;
char s[ran*2];

int main() {
	scanf("%s", s);
	len = strlen(s);
	for(int i=0;i<len;i++) s[i+len] = s[i];
	
	int ans = 1, cur = 0;
	for(int i=0;i<len*2;i++) {
		if (cur==0 || s[i] != s[i-1]) cur++;
		else cur = 1;
		if (cur>ans) ans = cur;
	}
	if (ans>len) ans = len;
	printf("%d\n", ans);
	
	return 0;
}