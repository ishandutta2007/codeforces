#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxl = 26;
const int Inf = 1000000000;
const int Maxn = 100005;

char sa[Maxn], sb[Maxn], sc[Maxn];
int alen, blen, clen;
int A[Maxl], B[Maxl], C[Maxl];

void Read(char s[], int &slen, int F[])
{
	scanf("%s", s); slen = strlen(s);
	for (int i = 0; i < slen; i++)
		F[s[i] - 'a']++;
}

int main()
{
	Read(sa, alen, A); Read(sb, blen, B); Read(sc, clen, C);
	int mx = 0, bi = 0, bj = 0;
	for (int i = 0; i <= alen; i++) {
		bool ok = true;
		int has = Inf;
		for (int j = 0; j < Maxl && ok; j++) {
			ok = A[j] >= ll(B[j]) * i;
			if (ok && C[j]) has = min(has, (A[j] - B[j] * i) / C[j]);
		}
		if (ok && i + has > mx) { mx = i + has; bi = i; bj = has; }
	}
	for (int i = 0; i < bi; i++)
		printf("%s", sb);
	for (int i = 0; i < bj; i++)
		printf("%s", sc);
	for (int i = 0; i < Maxl; i++) {
		A[i] -= bi * B[i] + bj * C[i];
		while (A[i]--) printf("%c", 'a' + i);
	}
	printf("\n");
	return 0;
}