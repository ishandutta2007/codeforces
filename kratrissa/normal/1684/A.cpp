#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int read(){
	int res=0;char c=getchar();
	while(c<48)c=getchar();
	while(c>=48)res=res*10+c-48,c=getchar();
	return res;
}
int T,n,a[N];char s[N];
void solve(){
	scanf("%s",s+1),n=strlen(s+1);
	if(n==2){printf("%d\n",s[2]-'0');return;}
	int ans=10;
	for(int i=1;i<=n;i++)ans=min(ans,s[i]-'0');
	printf("%d\n",ans);
}
int main(){
	T=read();
	while(T--)solve();
	return 0;
}