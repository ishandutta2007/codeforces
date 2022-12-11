#include<cstdio>

using namespace std;

char s[1000002];
int main(){
	int n;
	scanf("%d",&n);
	scanf("%s",s+1);
	int o=0,p=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		if(o==0&&s[i]==')')p=i;
		if(o==-1&&s[i]=='(')ans+=i-p+1;
		o+=s[i]=='('?1:-1;
	}
	if(o!=0)printf("-1\n");
	else printf("%d\n",ans);
}