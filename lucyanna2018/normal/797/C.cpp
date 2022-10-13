#include<bits/stdc++.h>
char s[111111];
char st[111111];int top;
int cnt[26];
int calc(int x){
	int res=0;
	for(int i=0; i<x; i++)
		res += cnt[i];
	return res;
}
int main(){
	scanf("%s",s);
	for(int i=0; s[i]; i++){
		cnt[s[i]-'a']++;
	}
	for(int i=0; s[i]; i++){
		cnt[s[i]-'a']--;
		st[top++] = s[i];
		while(top > 0 && calc(st[top-1]-'a') == 0){
			top--;
			putchar(st[top]);
		}
	}
	puts("");
	return 0;
}