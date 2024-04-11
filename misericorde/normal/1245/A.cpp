#include <bits/stdc++.h>
int t,a,b;
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}

int main(){
	scanf("%d",&t);
	while (t--){
		scanf("%d%d",&a,&b);
		if (gcd(a,b)==1)printf("Finite\n");
		else printf("Infinite\n");
	}
	return 0;
}