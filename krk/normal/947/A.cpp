#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;

vector <int> pr;
bool prime[Maxn];
int X;

int main()
{
	fill(prime, prime + Maxn, true);
	for (int i = 2; i < Maxn; i++) if (prime[i]) {
		pr.push_back(i);
		for (int j = i + i; j < Maxn; j += i) prime[j] = false;
	}
	scanf("%d", &X);
	int a = X, b = X;
	for (int i = 0; i < pr.size() && pr[i] < X; i++)
		if (X % pr[i] == 0) a = X - pr[i] + 1;
	int lw = Maxn;
	for (int i = 0; i < pr.size(); i++) {
		int x = a / pr[i] * pr[i];
		if (x < a) x += pr[i];
		x = max(x, 2 * pr[i]);
		if (x <= b) lw = min(lw, x - pr[i] + 1);
	}
	lw = max(lw, 3);
	printf("%d\n", lw);
	return 0;
}