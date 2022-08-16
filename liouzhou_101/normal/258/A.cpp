#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<iomanip>

using namespace std;

int n;
char s[100010];

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=1;i<=n;++i)
		if (s[i]=='0')
		{
			for (int j=1;j<i;++j)
				putchar(s[j]);
			for (int j=i+1;j<=n;++j)
				putchar(s[j]);
			puts("");
			return 0;
		}
	for (int i=1;i<n;++i)
		putchar('1');
	puts("");
	return 0;
}