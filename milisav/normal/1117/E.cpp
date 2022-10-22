#include<bits/stdc++.h>
using namespace std;
char t[20000];
char s[20000];
char x[20000];
char y[20000];
char z[20000];
int n;
int main()
{
	scanf("%s",t);
	n=strlen(t);
	for(int i=0;i<n;i++) x[i]=y[i]=z[i]='a';
	x[n]=y[n]=z[n]=0;
	for(int i=0;i<n;i++) {
		x[i]+=(i%26);
		y[i]+=(i/26)%26;
		z[i]+=(i/26/26)%26;
	}
	printf("? %s\n",x);
	fflush(stdout);
	scanf("%s",x);
	printf("? %s\n",y);
	fflush(stdout);
	scanf("%s",y);
	printf("? %s\n",z);
	fflush(stdout);
	scanf("%s",z);
	for(int i=0;i<n;i++) {
		s[x[i]-'a'+(y[i]-'a')*26+(z[i]-'a')*26*26]=t[i];
	}
	printf("! %s\n",s);
	fflush(stdout);
	return 0;
}