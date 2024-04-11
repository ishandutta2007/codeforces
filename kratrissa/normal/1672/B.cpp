#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int T,n;char s[N];
void solve(){
	scanf("%s",s+1),n=strlen(s+1);
	if(s[n]=='A'){printf("NO\n");return;}
	for(int i=1,ts=0;i<=n;i++)
		if((ts+=(s[i]=='A'?1:-1))<0){printf("NO\n");return;}
	printf("YES\n");
}
int main(){
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}