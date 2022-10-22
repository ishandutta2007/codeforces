#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n,m,a[MAXN];
char s[20];
int ans=1;
int main(){
	scanf("%s",s);
	n=strlen(s);
	for(int i=0; i<n; i++)
		s[i]-='A';
	for(int i=2; i<n; i++){
		int k=(s[i-2]+s[i-1])%26;
		if(k!=s[i]) ans=0;
	}
	if(ans) puts("YES");
	else puts("NO");
	return 0;
}