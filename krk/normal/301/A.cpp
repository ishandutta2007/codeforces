#include <cstdio>
#include <algorithm>
using namespace std;

const int Inf = 1000000000;
const int Maxn = 205;

int n, a[Maxn];
int mn = Inf, neg, nils;

int main()
{
	scanf("%d", &n);
	int sum = 0;
	for (int i = 0; i < 2 * n - 1; i++) {
		scanf("%d", &a[i]); sum += abs(a[i]);
		if (a[i] < 0) neg++;
		else if (a[i] == 0) nils++; 
		mn = min(mn, abs(a[i]));
	}
	if (n % 2 || nils || neg % 2 == 0) printf("%d\n", sum);
	else printf("%d\n", sum - 2 * mn);
	return 0;
}