#include <cstdio>
#include <cstring>
using namespace std;

const int Maxn = 5005;
const int Maxl = 26;

char a[Maxn], b[Maxn];
int alen, blen;
int freq[Maxl];

bool Possible(int pos)
{
	int cur = Maxl - 1, tk = 0;
	for (int i = pos; i < blen; i++) {
		while (cur >= 0 && tk == freq[cur]) { cur--; tk = 0; }
		if (cur > b[i] - 'a') return true;
		if (cur < b[i] - 'a') return false;
		tk++;
	}
	while (cur >= 0 && tk == freq[cur]) { cur--; tk = 0; }
	return cur >= 0;
}

bool getMore(char lim, char &bet)
{
	for (bet = lim + 1; bet - 'a' < Maxl; bet++)
		if (freq[bet - 'a']) return true;
	return false;
}

void writeTo(int pos)
{
	for (int i = 0; i < Maxl; i++)
		while (freq[i]--) a[pos++] = 'a' + i;
	printf("%s\n", a);
}

int main()
{
	scanf("%s", a); alen = strlen(a);
	scanf("%s", b); blen = strlen(b);
	for (int i = 0; i < alen; i++)
		freq[a[i] - 'a']++;
	if (!Possible(0)) printf("-1\n");
	else {
		for (int i = 0; i < blen; i++) {
			if (freq[b[i] - 'a']) {
				freq[b[i] - 'a']--;
				if (Possible(i + 1)) { a[i] = b[i]; continue; }
				else freq[b[i] - 'a']++;
			}
			char c;
			if (getMore(b[i], c)) {
				freq[c - 'a']--;
				a[i] = c;
				writeTo(i + 1);
				return 0;
			} else { printf("-1\n"); return 0; }
		}
		writeTo(blen);
	}
	return 0;
}