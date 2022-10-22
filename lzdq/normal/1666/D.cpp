#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=100;
int n,m;
char s[MAXN],t[MAXN];
bool vis[26];
bool Calc(){
	memset(vis,0,sizeof(vis));
	for(int i=m,j=n; i; i--,j--){
		while(j&&s[j]!=t[i]){
			vis[s[j]-'A']=1;
			j--;
		}
		if(!j) return 0;
		if(vis[s[j]-'A']) return 0;
	}
	return 1;
}
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%s%s",s+1,t+1);
		n=strlen(s+1);
		m=strlen(t+1);
		if(Calc()) puts("YES");
		else puts("NO");
	}
	return 0;
}