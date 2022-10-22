#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	vector<int> ar(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &ar[i]);
	sort(ar.begin(), ar.end());
	printf("%d", ar[n / 2]);
	return 0;
}