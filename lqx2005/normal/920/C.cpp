#include<bits/stdc++.h>
using namespace std;
const int maxn=200000;
int n;
int a[maxn+5];
char s[maxn+5];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%s",s+1);
	int las=1;
	for(int i=1;i<=n-1;i++) if(s[i]=='0') sort(a+las,a+i+1),las=i+1;
	sort(a+las,a+n+1);
	for(int i=2;i<=n;i++) 
	{
		if(a[i-1]>=a[i])
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}