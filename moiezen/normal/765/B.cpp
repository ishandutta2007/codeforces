#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define rpt(i,l,r) for(int i=l;i<=r;i++)
#define rpd(i,r,l) for(int i=r;i>=l;i--)
#define ll long long
int main(){
	char s[505];
	scanf("%s",s+1);int n=strlen(s+1);
	int cnt[26];
	rpt(i,0,25) cnt[i]=0;
	bool flag=1;
	rpt(i,1,n){
		cnt[s[i]-'a']++;
		rpt(j,0,s[i]-'a'-1) if(!cnt[j]) flag=0;
	}
	printf(flag?"YES\n":"NO\n");
}