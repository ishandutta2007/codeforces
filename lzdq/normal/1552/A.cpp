#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n;
char s[100],t[100];
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		scanf("%s",s+1);
		memcpy(t,s,sizeof(s));
		sort(t+1,t+n+1);
		int k=0;
		for(int i=1; i<=n; i++)
			if(s[i]!=t[i]) k++;
		printf("%d\n",k);
	}
	return 0;
}