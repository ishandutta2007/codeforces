#include <bits/stdc++.h>

int n,ans;
char opt[1000];

int main() {
	scanf("%d%s",&n,opt+1);
	for (int i=0;i<=1000;++i) {
		int p=i,flag=1;
		for (int j=1;j<=n;++j) {
			if (opt[j]=='+') p++;
			else p--;
			if (p<0) {flag=0;break;}
		}if (flag) {printf("%d",p);return 0;}
	}
	return 0;
}