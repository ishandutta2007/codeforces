#include<bits/stdc++.h>
using namespace std;
char s[500];
int q;
int n;
int main()
{
	scanf("%d",&q);
	while(q--) {
		scanf("%d",&n);
		scanf("%s",s);
		if(n>2 || s[0]<s[1]) {
			printf("YES\n");
			printf("2\n");
			printf("%c ",s[0]);
			for(int i=1;i<n;i++) printf("%c",s[i]);
			printf("\n");
		}
		else printf("NO\n");
	}
	return 0;
}