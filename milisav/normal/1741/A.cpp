#include<bits/stdc++.h>
using namespace std;
int t;
char a[60];
char b[60];
int main() {
	scanf("%d",&t);
	while(t--) {
		scanf("%s %s",a,b);
		int n=strlen(a);
		int m=strlen(b);
		if(a[n-1]<b[m-1]) {
			printf(">");
		}
		else {
			if(a[n-1]>b[m-1]) {
				printf("<");
			}
			else {
				if(n==m) {
					printf("=");
				}
				else {
					if(a[n-1]=='L') {
						if(n>m) printf(">");
						else printf("<");
					}
					else {
						if(n>m) printf("<");
						else printf(">");
					}
				}
			}
		}
		printf("\n");
	}
	return 0;
}