#include <bits/stdc++.h>
using namespace std;
int n;
char s[100];
int main()
{
	scanf("%s",s);
	n=strlen(s);
	int r=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='a') r++;
		if(s[i]=='e') r++;
		if(s[i]=='i') r++;
		if(s[i]=='o') r++;
		if(s[i]=='u') r++;
		if(s[i]=='1') r++;
		if(s[i]=='3') r++;
		if(s[i]=='5') r++;
		if(s[i]=='7') r++;
		if(s[i]=='9') r++;
	}
	printf("%d",r);
	return 0;
}