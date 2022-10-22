#include<cstdio>
#include<cstring>
char s[100010];
int main()
{
	scanf("%s",s);
	int l=strlen(s),j,ans=0;
	for(int i=0;i<l;i=j)
	{
		for(j=i+1;j<l&&s[j]=='0';j++);
		if(j-i>i||j-i==i&&s[i]>s[0])
			ans=0;
		ans++;
	}
	printf("%d\n",ans);
}