#include<cstdio>
const int N=300020;
typedef long long ll;
int pre[N],nxt[N],n,i;
ll Ans;
char s[N];
int main(){
	scanf("%d%s",&n,s+1);
	Ans=1ll*n*(n-1)/2;
	pre[1]=1;
	for(i=2;i<=n;i++){
		if(s[i]==s[i-1])
			pre[i]=pre[i-1]+1;
		else
			Ans-=pre[i-1],pre[i]=1;
	}
	nxt[n]=1;
	for(i=n-1;i;i--){
		if(s[i]==s[i+1])
			nxt[i]=nxt[i+1]+1;
		else
			Ans-=nxt[i+1],nxt[i]=1;
	}
	for(i=1;i<n;i++)
		Ans+=s[i]!=s[i+1];
	printf("%lld",Ans);
}