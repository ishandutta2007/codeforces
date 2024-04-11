#include<bits/stdc++.h>
using namespace std;
char s[300000];
int b[300000];
int n;
int main()
{
	scanf("%s",s);
	n=strlen(s);
	for(int i=1;i<n;i++) {
		if(s[i]=='a' && s[i-1]=='b') b[i-1]=1;
		if(s[i]=='a' && (i==n-1 || s[i+1]=='b')) b[i]=1;
	}
	for(int i=0;i<n;i++) printf("%d ",b[i]);
	return 0;
}