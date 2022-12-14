#include <cstdio>
#include <iostream>
#include <algorithm>
#define rpt(i,l,r) for(int i=l;i<=r;i++)
#define rpd(i,r,l) for(int i=r;i>=l;i--)
#define ll long long
int main(){
	int n;scanf("%d",&n);
	if(n&1) printf("contest");
	else printf("home");
}