#include <cstdio>
using namespace std;

const int Maxs = 1000000;

int n;
int seq[Maxs + 1];
int prs;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		seq[x] = 1;
	}
	for (int i = 1; i <= Maxs + 1 - i; i++)
		if (seq[i] + seq[Maxs + 1 - i] == 1) 
			if (seq[i]) seq[Maxs + 1 - i] = 2;
			else seq[i] = 2;
		else if (seq[i] + seq[Maxs + 1 - i] == 2)
				prs++;
	for (int i = 1; i <= Maxs + 1 - i && prs; i++)
		if (seq[i] + seq[Maxs + 1 - i] == 0) { seq[i] = seq[Maxs + 1 - i] = 2; prs--; }
	printf("%d\n", n);
	bool pr = false;
	for (int i = 1; i <= Maxs; i++)
		if (seq[i] == 2) {
			if (pr) printf(" ");
			pr = true;
			printf("%d", i);
		}
	printf("\n");
	return 0;
}