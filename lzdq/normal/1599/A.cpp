#include<cstdio>
#include<algorithm>
#include<cstring>
typedef long long ll;
using namespace std;
const int MAXN=2e5+5;
typedef pair<int,int> pr;
#define mkp make_pair
int n,m;
int a[MAXN];
char s[MAXN];
int main(){
	//freopen("in","r",stdin);
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
	scanf("%s",s+1);
	for(int i=2; i<=n; i++)
		if(s[i]!=s[i-1]) m++;
	int t=(n-m&1)^(s[1]=='L');
	printf("%d %c\n",a[n-m],s[1]);
	int l=n-m,r=n-m;
	for(int i=2; i<=n; i++){
		if(s[i]==s[i-1]) l--,printf("%d %c\n",a[l],(l&1)==t?'R':'L');
		else r++,printf("%d %c\n",a[r],(r&1)==t?'R':'L');
	}
	return 0;
}