#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

ll a;
int k;
vector <int> va;

int main()
{
	scanf("%I64d %d", &a, &k);
	while (a) { va.push_back(a % 10); a /= 10; }
	reverse(va.begin(), va.end());
	int tk = va.size();
	for (int i = 0; i < tk; i++)
		for (int j = 9; j >= 0; j--) {
			int pos = 0;
			while (pos < va.size() && va[pos] != j) pos++;
			if (pos < va.size() && pos <= k) {
				printf("%d", j);
				k -= pos;
				va.erase(va.begin() + pos);
				break;
			}
		}
	printf("\n");
	return 0;
}