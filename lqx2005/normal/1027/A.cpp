#include<bits/stdc++.h>
using namespace std;
const int maxn=100;
int T,n;
char s[maxn+5];
int main()
{
	scanf("%d",&T);
	for(int tot=1;tot<=T;tot++)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		int flag=0;
		for(int i=1;i<=n/2;i++)
		{
			int delta=abs((int)s[i]-(int)s[n+1-i]);
			if(delta==0) continue;
			else if(delta==1) flag=1;
			else if(delta==2) continue;
			else flag=1;
		}
		if(flag) printf("NO\n");
		else printf("YES\n");
	}
}