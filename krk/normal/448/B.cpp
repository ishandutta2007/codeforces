#include <cstdio>
#include <cstring>
using namespace std;

const int Maxn = 105;
const int Maxl = 26;

char a[Maxn], b[Maxn];
int alen, blen;
int afreq[Maxl], bfreq[Maxl];

void calcFreq(char a[], int len, int freq[])
{
	for (int i = 0; i < len; i++)
		freq[a[i] - 'a']++;
}

bool canRemove()
{
	int i = 0;
	for (int j = 0; j < blen; j++) {
		while (i < alen && a[i] != b[j]) i++;
		if (i == alen) return false;
		i++;
	}
	return true;
}

bool canSwap()
{
	for (int i = 0; i < Maxl; i++)
		if (afreq[i] != bfreq[i])
			return false;
	return true;
}

bool canBoth()
{
	for (int i = 0; i < Maxl; i++)
		if (afreq[i] < bfreq[i])
			return false;
	return true;
}

int main()
{
	scanf("%s", a); alen = strlen(a);
	scanf("%s", b); blen = strlen(b);
	calcFreq(a, alen, afreq);
	calcFreq(b, blen, bfreq);
	if (canRemove()) printf("automaton\n");
	else if (canSwap()) printf("array\n");
	else if (canBoth()) printf("both\n");
	else printf("need tree\n");
	return 0;
}