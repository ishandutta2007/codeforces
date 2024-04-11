#include <bits/stdc++.h>

int a;
int calc(int x) {
	int res=0;
	while (x>0) {
		res+=x%10;x=x/10;
	}return res%4==0;
}

int main() {
	scanf("%d",&a);
	for (int i=a;i<=4000;++i) {
		if (calc(i)) {printf("%d",i);return 0;}
	}
}