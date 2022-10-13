#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int cnt[3];
int ls,ls1,ls2;
char s[111111];
char s1[111111];
char s2[111111];
void tri(int d,int sz,char*s,int&l){
	for(int i=ls-1; i>=0; i--)
		if((::s[i]-'0')%3==d && sz > 0)
			sz--;
		else
			s[l++] = ::s[i];
	while(l>1 && s[l-1] == '0')
		l--;
	reverse(s,s+l);
	s[l] = 0;
}
int main(){
	scanf("%s",s);
	ls = strlen(s);
	for(int i=0; i<ls; i++){
		cnt[(s[i]-'0')%3]++;
	}
	int sum = (cnt[1] + cnt[2] * 2) % 3;
	if(sum == 0){
		puts(s);
		return 0;
	}
	ls1 = ls2 = 0;
	if(sum == 1){
		if(cnt[1] >= 1)
			tri(1,1,s1,ls1);
		if(cnt[2] >= 2)
			tri(2,2,s2,ls2);
	}else
	if(sum == 2){
		if(cnt[2] >= 1)
			tri(2,1,s1,ls1);
		if(cnt[1] >= 2)
			tri(1,2,s2,ls2);
	}
	if(ls1 == 0 && ls2 == 0)
		puts("-1");
	else
		puts(ls1 > ls2 ? s1 : s2);
	return 0;
}