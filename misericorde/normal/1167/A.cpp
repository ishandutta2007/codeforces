#include <bits/stdc++.h>

int n,t;
char s[10000];

int main() {
	scanf("%d",&t);
	while (t--) {
		scanf("%d%s",&n,s+1);
		int flag=0;
		for (int i=1;i<=n;++i) {
			if (s[i]=='8') {
				if (n-i+1>=11) {printf("YES\n");flag=1; break;}
				else {printf("NO\n");flag=1;break;}
			}
		}if (!flag) {printf("NO\n");}
	}
	return 0;
}