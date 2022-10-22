#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1e5+5;
int n;
char s[MAXN];
int k;
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		scanf("%s",s+1);
		k=1;
		while(k<n&&s[k]>=s[k+1]) k++;
		if(n>1&&s[1]==s[2]) k=1;
		for(int i=1; i<=k; i++)
			putchar(s[i]);
		for(int i=k; i; i--)
			putchar(s[i]);
		puts("");
	}
	return 0;
}