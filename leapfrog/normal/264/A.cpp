#include<bits/stdc++.h>
using namespace std;
char s[1000005];int ans[1000005],l,r,n;
int main()
{
	scanf("%s",s+1),l=1,n=r=strlen(s+1);
	for(int i=1;i<=n;i++) if(s[i]=='r') ans[l++]=i;else ans[r--]=i;
	for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
	return 0;
}