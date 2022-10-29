#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,t;
	scanf("%d%d",&n,&t);
	if(t==10){
		if(n==1)printf("-1");
		else {
			putchar('1');
			while(--n)putchar('0');
		}
	}
	else {
		while(n--)putchar('0'+t);
	}
	puts("");
	return 0;
}