#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
char s[444444];
int n,q,l,r,cnt[222222][26],crt;
int main()
{
	scanf("%s",s);
	n=strlen(s);
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<26;j++)
		{
			cnt[i][j]=cnt[i-1][j];
		}
		cnt[i][s[i-1]-'a']++;
	}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&l,&r);
		crt=0;
		for (int i=0;i<26;i++)
		{
			if (cnt[r][i]>cnt[l-1][i]) crt++;
		}
		if (l==r) printf("Yes\n");
		else if (s[l-1]==s[r-1] && crt<=2) printf("No\n");
		else printf("Yes\n");  
	}
	return Accepted;
}