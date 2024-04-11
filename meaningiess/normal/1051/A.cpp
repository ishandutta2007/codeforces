#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int T,i,c1,c2,c3,n;char s[202];
int main()
{
	cin>>T;int n;
	while(T--)
	{
		scanf("%s",s);
		n=strlen(s),c1=c2=0;
		for (i=0;i<n;i++) if (isdigit(s[i])) c1++;else if (s[i]>='a'&&s[i]<='z') c2++;
		c3=n-c1-c2;
		if (c1&&c2&&c3) {printf("%s\n",s);continue;}
		if (!c1&&c2&&c3)
		{
			if (c2>1){for (i=0;i<n;i++) if (s[i]>='a'&&s[i]<='z') {s[i]='0';break;}}
			else if (c3>1){for (i=0;i<n;i++) if (s[i]>='A'&&s[i]<='Z') {s[i]='0';break;}}
			printf("%s",s);puts("");continue;
		}
		if (c1&&!c2&&c3)
		{
			if (c1>1){for (i=0;i<n;i++) if (isdigit(s[i])) {s[i]='y';break;}}
			else if (c3>1){for (i=0;i<n;i++) if (s[i]>='A'&&s[i]<='Z') {s[i]='x';break;}}
			printf("%s",s);puts("");continue;
		}
		if (c1&&c2&&!c3)
		{
			if (c2>1){for (i=0;i<n;i++) if (s[i]>='a'&&s[i]<='z') {s[i]='P';break;}}
			else if (c1>1){for (i=0;i<n;i++) if (isdigit(s[i])) {s[i]='Y';break;}}
			printf("%s",s);
			puts("");continue;
		}
		if (c1&&!c2&&!c3)
		{
			printf("aA");
			for (i=2;i<n;i++) printf("%c",s[i]);
			puts("");continue;
		}
		if (!c1&&c2&&!c3)
		{
			printf("A0");
			for (i=2;i<n;i++) printf("%c",s[i]);
			puts("");continue;
		}
		if (!c1&&!c2&&c3)
		{
			printf("0a");
			for (i=2;i<n;i++) printf("%c",s[i]);
			puts("");continue;
		}
	}
}