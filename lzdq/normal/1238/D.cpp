#include<cstdio>
typedef long long ll;
const int MAXN=3e5+5;
int n;
char s[MAXN];
int nx[MAXN],pre[MAXN];
ll ans;
int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	pre[1]=1;
	for(int i=2;i<=n;i++)
		pre[i]=(s[i]==s[i-1])?pre[i-1]:i;
	nx[n]=n;
	for(int i=n-1;i>0;i--)
		nx[i]=(s[i]==s[i+1])?nx[i+1]:i;
	ans=1ll*n*(n-1)/2;
	for(int i=1;i<=n;i++){
		if(i>1&&s[i]!=s[i-1])
			ans-=i-pre[i-1]-1;
		if(i<n&&s[i]!=s[i+1])
			ans-=nx[i+1]-i;
	}
	printf("%I64d\n",ans);
	return 0;
}