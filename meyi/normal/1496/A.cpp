#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
int k,n,t;
char s[maxn];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%s",&n,&k,s+1);
		if(!k){
			puts("YES");
			continue;
		}
		if(k*2==n){
			puts("NO");
			continue;
		}
		bool flag=false;
		for(ri i=1;i<=k;++i)
			if(s[i]!=s[n-i+1]){
				flag=true;
				break;
			}
		puts(flag?"NO":"YES");
	}
}