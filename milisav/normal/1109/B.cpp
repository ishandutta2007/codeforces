#include<bits/stdc++.h>
using namespace std;
char s[10000];
char t[10000];
int n;
bool test()
{
	for(int i=0;i<n;i++) {
		bool gp=false;
		for(int j=0;j<n;j++) t[j]=s[(i+j)%n];
		for(int j=0;j<n;j++) {
			if(s[j]!=t[j]) gp=true;
		}
		for(int j=0;j<n;j++) {
			if(t[j]!=t[n-1-j]) gp=false;
		}
		if(gp) return true;
	}
	return false;
}
int main()
{
	scanf("%s",s);
	n=strlen(s);
	bool sm=true;
	bool pal=true;
	for(int i=1;i<n/2;i++) if(s[i]!=s[i-1]) sm=false;
	for(int i=0;i<n/2;i++) if(s[i]!=s[n/2-i-1]) pal=false;
	if(sm) {
		printf("Impossible");
		return 0;
	}
	if(test()) {
		printf("1");
		return 0;
	}
	if(n%2==0) {
		if(pal) printf("2");
		else printf("1");
	}
	else {
		printf("2");
	}
	return 0;
}