#include<cstdio>
#include<cstring>
const int MAXN=105;
int n;
char s[MAXN];
bool a[MAXN];
int main(){
	int t; scanf("%d",&t);
	while(t--){
		scanf("%s",s+1);
		n=strlen(s+1);
		for(int i=1; i<=n; i++)
			a[i]=a[i-1]+(s[i]=='1');
		bool k=0;
		int ans=0;
		for(int i=n;i;i--){
			if(s[i]=='1') k=1;
			else if(k&&a[i]) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}