#include <cstdio>
#include <cstring>
using namespace std;

const int Maxn = 1000005;

char a[Maxn], b[Maxn];
int alen, blen;

bool hasOnes(char a[], int alen)
{
	for (int i = 0; i < alen; i++)
		if (a[i] == '1') return true;
	return false;
}

int main()
{
	scanf("%s", a); alen = strlen(a);
	scanf("%s", b); blen = strlen(b);
	printf("%s\n", alen == blen && hasOnes(a, alen) == hasOnes(b, blen)? "YES": "NO");
	return 0;
}