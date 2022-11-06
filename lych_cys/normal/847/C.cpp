#include<bits/stdc++.h>
#define ll long long
using namespace std;

void GG(){ puts("Impossible"); exit(0); }
int main(){
	int n; ll k;
	scanf("%d%lld",&n,&k);
	if ((ll)n*(n-1)/2<k) GG();
	int i,stp=0;
	for (i=1; i<=n; i++) if ((ll)i*(i-1)/2<=k) stp=i; else break;
	if ((ll)stp*(stp-1)/2==k){
		for (i=1; i<=stp; i++) putchar('(');
		for (i=1; i<=stp; i++) putchar(')');
		for (i=1; i<=n-(stp); i++) printf("()");return 0;
	}
	if (stp+1>n) GG();
	ll sum=k-(ll)stp*(stp-1)/2;
	for (i=1; i<=stp; i++) putchar('(');
	for (i=1; i<=stp-sum; i++) putchar(')');
	putchar('('); putchar(')');
	for (i=1; i<=sum; i++) putchar(')');
	for (i=1; i<=n-(stp+1); i++) printf("()");
	return 0;
}