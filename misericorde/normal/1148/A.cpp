#include <bits/stdc++.h>

int a,b,c;

int main() {
	scanf("%d%d%d",&a,&b,&c);
	int d=std::min(a,b);
	c+=d;a-=d;b-=d;
	std::cout<<(long long)c*2+(a||b);
	return 0;
}