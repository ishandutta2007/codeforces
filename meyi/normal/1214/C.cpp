#include<bits/stdc++.h>
using namespace std;
#define ri register int
const int maxn=2e5+10;
int m,n;
char s[maxn];
int main(){
	scanf("%d%s",&n,s+1);
	for(ri i=1;i<=n;++i){
		m+=(s[i]=='('?1:-1);
		if(m<-1){
			puts("No");
			return 0;
		}
	}
	puts(m?"No":"Yes");
	return 0;
}