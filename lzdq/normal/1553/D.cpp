#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
char s[MAXN],t[MAXN];
int n,m;
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%s%s",s+1,t+1);
		n=strlen(s+1);
		m=strlen(t+1);
		while(n>0&&m){
			if(s[n]==t[m]) n--,m--;
			else n-=2;
		}
		if(!m) puts("YES");
		else puts("NO");
	}
	return 0;
}