#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 1 << 20;

int n;
vector <int> seq;
bool has[Maxn];
int res;

int main()
{
	scanf("%d", &n);
	while (n--) {
		int a; scanf("%d", &a);
		has[a] = true;
		for (int i = 0; i < seq.size(); i++) {
			seq[i] |= a;
			has[seq[i]] = true;
		}
		seq.push_back(a);
		for (int i = 0; i + 1 < seq.size(); i++)
			if (seq[i] == seq[i + 1]) seq.erase(seq.begin() + i--);
	}
	for (int i = 0; i < Maxn; i++)
		res += has[i];
	printf("%d\n", res);
	return 0;
}