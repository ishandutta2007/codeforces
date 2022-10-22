#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 10000006;

int res[Maxn];
int best[Maxn];
int T;
int c;

int main()
{
	res[1] = best[1] = 1;
	for (int i = 2; i < Maxn; i++) {
		if (res[i] == 0) {
			for (int j = i; j < Maxn; j += i) if (res[j] < Maxn) {
				int num = j;
				int add = 1, sum = 1;
				while (num % i == 0) {
					num /= i;
					add *= i;
					sum += add;
				}
				if (!res[j]) res[j] = sum;
				else if (res[j] <= Maxn / sum) res[j] *= sum;
					else res[j] = Maxn;
			}
		}
		if (res[i] < Maxn && !best[res[i]]) best[res[i]] = i;
	}
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &c);
		printf("%d\n", best[c]? best[c]: -1);
	}
    return 0;
}