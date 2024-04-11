#include <bits/stdc++.h>
using namespace std;

bool is_prime(int x)
{
	for(int i = 2; i <= sqrt(x); i ++)
		if(x % i == 0) return 1;
	return 0;
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= 1000; i ++)
		if(is_prime(i * n + 1)) {cout << i; return 0;}

	return 0;
}