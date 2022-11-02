#include <bits/stdc++.h>

int n,ans=0;
char s[200005];

int main() {
	scanf("%d%s",&n,s+1);
	int d1=0,d2=0;
	for (int i=1;i<=n;++i) {
		
		if (s[i]=='(') {
			if (d1<d2) {printf("0");d1++;}
			else {printf("1");d2++;}
		} else {
			if (d1<d2) {printf("1");d2--;}
			else {printf("0");d1--;}
		}ans=std::max(ans,std::max(d1,d2));
	}//printf("%d",ans);
	return 0;
}