#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 105;
const int Maxm = 1000005;

int n;
char ch[Maxn];
int id[Maxn];
bool lib[Maxm];
int in;
int res;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf(" %c %d", &ch[i], &id[i]);
		if (ch[i] == '+') lib[id[i]] = true;
		else {
			if (!lib[id[i]]) in++;
			lib[id[i]] = false;
		}
	}
	res = in;
	for (int i = 0; i < n; i++)
		if (ch[i] == '+') { in++; res = max(res, in); }
		else in--;
	printf("%d\n", res);
	return 0;
}