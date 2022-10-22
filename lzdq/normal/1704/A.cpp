#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n,m;
char a[MAXN],b[MAXN];
bool Check(){
	if(n==m){
		for(int i=1; i<=n; i++)
			if(a[i]!=b[i]) return 0;
		return 1;
	}
	for(int i=2; i<=m; i++)
		if(a[i+n-m]!=b[i]) return 0;
	for(int i=1; i<=n-m+1; i++)
		if(a[i]==b[1]) return 1;
	return 0;
}
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d%d",&n,&m);
		scanf("%s",a+1);
		scanf("%s",b+1);
		if(Check()) puts("YES");
		else puts("NO");
	}
	return 0;
}