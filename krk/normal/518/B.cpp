#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int Maxl = 52;
const int Maxn = 200005;

char sA[Maxn], sB[Maxn];
int alen, blen;
int A[Maxl], B[Maxl];
int res1, res2;

int getId(char ch)
{
	if ('a' <= ch && ch <= 'z') return ch - 'a';
	else return 26 + ch - 'A';
}

int main()
{
	scanf("%s", sA); alen = strlen(sA);
	scanf("%s", sB); blen = strlen(sB);
	for (int i = 0; i < alen; i++)
		A[getId(sA[i])]++;
	for (int i = 0; i < blen; i++)
		B[getId(sB[i])]++;
	for (int i = 0; i < Maxl; i++) {
		int tk = min(A[i], B[i]);
		A[i] -= tk; B[i] -= tk;
		res1 += tk;
	}
	for (int i = 0; i < 26; i++) {
		int tk = min(A[i], B[i + 26]) + min(A[i + 26], B[i]);
		res2 += tk;
	}
	printf("%d %d\n", res1, res2);
	return 0;
}