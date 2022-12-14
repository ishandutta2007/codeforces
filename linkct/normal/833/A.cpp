#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;

LL gcd(LL a, LL b){return b ? gcd(b, a % b) : a;}
bool check(LL a, LL b){
	LL g = gcd(a, b), p;
	a /= g, b /= g, p = a * b;
	if(g % p) return false;
	g /= p;
	LL base = LL(pow(g * 1.0, 1.0 / 3.0)), i;
	for(i = max(base - 1, 0LL); i * i * i < g; ++ i) ;
	return i * i * i == g;
}
int main(){
	int testcase, a, b;
	scanf("%d", &testcase);
	while(testcase --){
		scanf("%d%d", &a, &b);
		printf("%s\n", check(a, b) ? "Yes" : "No");
	} return 0;
}