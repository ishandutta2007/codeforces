#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n;
char s[MAXN];
int ans;
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		scanf("%s",s+1);
		ans=n;
		for(int i=1; i<n*2; i++)
			if(s[i]==')'&&s[i+1]=='(') ans--;
		printf("%d\n",ans);
	}
	return 0;
}