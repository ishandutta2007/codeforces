#include <bits/stdc++.h>
using namespace std;

int N;

bool is_prime(int n)
{
	for (int i=2;i*i<=n;i++) if (n%i == 0)
		return 0;
	return 1;
}

int main()
{
	cin >> N;
	if (is_prime(N)) puts("1");
	else if (N%2 == 0 || is_prime(N-2)) puts("2");
	else puts("3");
}