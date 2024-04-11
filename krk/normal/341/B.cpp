#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector <int> seq;

int main()
{
	scanf("%d", &n);
	while (n--) {
		int a; scanf("%d", &a);
		int ind = lower_bound(seq.begin(), seq.end(), a) - seq.begin();
		if (ind < seq.size()) seq[ind] = a;
		else seq.push_back(a);
	}
	printf("%d\n", seq.size());
	return 0;
}