#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int T,n,f[N],lst[26];char s[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1),n=strlen(s+1);
		fill(lst,lst+26,0);
		for(int i=1;i<=n;i++){
			if(lst[s[i]-'a'])f[i]=min(f[i-1]+1,f[lst[s[i]-'a']-1]+i-lst[s[i]-'a']-1);
			else f[i]=f[i-1]+1;
			lst[s[i]-'a']=i;
		}
		printf("%d\n",f[n]);
	}
	return 0;
}