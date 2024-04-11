#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
char s[MAXN];
int n,ans;
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%s",s+1);
		n=strlen(s+1);
		ans=0;
		for(int i=1; i<=n; i++)
			if(s[i]=='0'&&(i==1||s[i-1]=='1')) ans++;
		printf("%d\n",min(ans,2));
	}
	return 0;
}