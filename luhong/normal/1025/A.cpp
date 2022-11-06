#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int cnt[1000];char c[1010000];
int main()
{
	int n;scanf("%d%s",&n,c);
	if(n==1)return 0*puts("Yes");
	for(int i=0;i<n;i++)
		cnt[c[i]-'a']++;
	bool ok=0;
	for(int i=0;i<26;i++)
	{
		if(cnt[i]>=2)ok=1;
	}
	if(ok)puts("Yes");
	else puts("No");
	return 0;
 }