#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 150005;

int n;
int t[Maxn];
vector <int> bad;

bool Ok(int ind)
{
	return (ind == 1 || (ind % 2 == 1 && t[ind - 1] > t[ind] || ind % 2 == 0 && t[ind - 1] < t[ind])) &&
 		   (ind == n || (ind % 2 == 1 && t[ind] < t[ind + 1] || ind % 2 == 0 && t[ind] > t[ind + 1]));
}

bool Check(int val = -1)
{
	for (int i = 0; i < bad.size(); i++)
		if (!Ok(bad[i]) || !Ok(bad[i] + 1)) return false;
	if (val != -1)
		if (!Ok(val)) return false;
	return true;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &t[i]);
	for (int i = 1; i + 1 <= n; i++)
		if (i % 2 == 1 && t[i] >= t[i + 1] || i % 2 == 0 && t[i] <= t[i + 1]) {
			bad.push_back(i); i++;
		}
	if (bad.size() > 2) { printf("0\n"); return 0; }
	int res = 0;
	if (bad.size() == 2) {
		for (int i = bad[0]; i <= bad[0] + 1; i++)
			for (int j = bad[1]; j <= bad[1] + 1; j++) {
				swap(t[i], t[j]);
				if (Check()) res++;
				swap(t[i], t[j]);
			}
	} else {
		for (int i = 1; i <= n; i++) {
			if (bad[0] != i) {
				swap(t[bad[0]], t[i]);
				if (Check(i)) res++;
				swap(t[bad[0]], t[i]);
			}
			if (bad[0] != i && bad[0] + 1 != i) {
				swap(t[bad[0] + 1], t[i]);
				if (Check(i)) res++;
				swap(t[bad[0] + 1], t[i]);
			}
		}
	}
	printf("%d\n", res);
	return 0;
}