#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n;
int main()
{
	scanf("%d", &n);
	int ans = 1;
	for(int i = 1; i <= n; i++) ans = 1ll * ans * i % mod;
	int pro = 1;
	for(int i = 1; i <= n - 1; i++) pro = 1ll * pro * 2 % mod;
	ans = (ans - pro + mod) % mod;
	printf("%d\n", ans);
	return 0;
}