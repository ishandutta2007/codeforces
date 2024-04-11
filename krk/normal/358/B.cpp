#include <cstdio>
#include <cstring>
using namespace std;

const int Maxn = 1000005;

int n;
char need[Maxn];
int nlen;
char got[Maxn];
int glen;
char msg[Maxn];
int mlen;

int main()
{
	scanf("%d", &n);
	need[nlen++] = '<'; need[nlen++] = '3';
	while (n--) {
		scanf("%s", got); glen = strlen(got);
		for (int i = 0; i < glen; i++)
			need[nlen++] = got[i];
		need[nlen++] = '<'; need[nlen++] = '3';
	}
	scanf("%s", msg); mlen = strlen(msg);
	int j = 0;
	for (int i = 0; i < mlen; i++)
		if (j < nlen && need[j] == msg[i]) j++;
	printf("%s\n", j == nlen? "yes": "no");
	return 0;
}