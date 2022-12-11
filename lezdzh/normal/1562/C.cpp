#include<cstdio>

using namespace std;

char s[20002];
int main(){
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		int n;
		scanf("%d%s",&n,s+1);
		for(int i=1;i<=n;i++)
			if(s[i]=='0'&&i*2-1!=n){
				if(i*2-1>n)printf("%d %d %d %d\n",1,i,1,i-1);
				else printf("%d %d %d %d\n",i,n,i+1,n);
				goto ed;
			}
		printf("%d %d %d %d\n",1,(n+1)/2,n/2+1,n);
			ed:;
	}
}