#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

bool prime[Maxn];
vector <int> pr;
int T;
int a, b, k;

int Get(int a)
{
	int res = 0;
	for (int i = 0; i < pr.size() && pr[i] * pr[i] <= a; i++)
		while (a % pr[i] == 0) { res++; a /= pr[i]; }
	if (a > 1) res++;
	return res;
}

int main()
{
	fill(prime + 2, prime + Maxn, true);
	for (int i = 2; i < Maxn; i++) if (prime[i]) {
		pr.push_back(i);
		for (int j = i + i; j < Maxn; j += i)
			prime[j] = false;
	}
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d", &a, &b, &k);
		if (k == 1)
			if (a != b && (a % b == 0 || b % a == 0)) printf("Yes\n");
			else printf("No\n");
		else {
			int mx = Get(a) + Get(b);
			if (k <= mx) printf("Yes\n");
			else printf("No\n");
		}
	}
    return 0;
}