#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n;
char s[MAXN];
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%s",s+1);
		n=strlen(s+1);
		bool ans=1;
		int x=0;
		for(int i=1; i<=n; i++){
			if(s[i]=='A') x++;
			else x--;
			if(x<0) ans=0;
		}
		if(s[n]=='A') ans=0;
		if(ans) puts("YES");
		else puts("NO");
	}
	return 0;
}