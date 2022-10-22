#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,s0[N],s1[N];char s[N];
int main(){
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=2;i<=n;i++)s0[i]=s0[i-1]+(s[i-1]=='0'&&s[i]=='0'),s1[i]=s1[i-1]+(s[i-1]=='1'&&s[i]=='1');
	for(int i=1,l,r;i<=m;i++){
		scanf("%d%d",&l,&r);
		printf("%d\n",1+max(s0[r]-s0[l],s1[r]-s1[l]));
	}
	return 0;
}