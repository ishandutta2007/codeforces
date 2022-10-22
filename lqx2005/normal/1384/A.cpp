#include<bits/stdc++.h>
using namespace std;
const int N=1100000;
int T,n;
int a[N];
int s[N];
int main()
{
	scanf("%d",&T);
	for(int amo=1;amo<=T;amo++)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		int len=0;
		for(int i=1;i<=n;i++) len=max(len,a[i]);
		len++;
		for(int i=1;i<=len;i++) s[i]=0;
		for(int i=1;i<=len;i++) printf("%c",(char)('a'+s[i]));
		printf("\n");
		for(int i=1;i<=n;i++)
		{
			s[a[i]+1]=(s[a[i]+1]+1)%26;
			for(int j=1;j<=len;j++) printf("%c",(char)('a'+s[j]));
			printf("\n");
		}
	}
	return 0;
}