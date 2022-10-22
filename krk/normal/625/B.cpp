#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int Maxa = 100005;
const int Maxb = 35;

char A[Maxa];
int alen;
char B[Maxb];
int blen;

int main()
{
	scanf("%s", A); alen = strlen(A);
	scanf("%s", B); blen = strlen(B);
	int lst = -1, res = 0;
	for (int i = 0; i < alen; i++)
		if (i - lst >= blen) {
			bool chk = true;
			for (int j = 0; chk && j < blen; j++)
				chk = A[i - blen + 1 + j] == B[j];
			if (chk) { lst = i; res++; }
		}
	printf("%d\n", res);
	return 0;
}