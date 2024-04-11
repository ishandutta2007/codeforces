#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

const int Maxb = 10;
const int Maxn = 500005;

int n;
char ch[Maxn];
int num[Maxn];
int AND, OR, XOR;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf(" %c %d", &ch[i], &num[i]);
	AND = (1 << Maxb) - 1;
	for (int i = 0; i < Maxb; i++) {
		int zer = 0, one = 1;
		for (int j = 0; j < n; j++)
			if (ch[j] == '|') {
				zer |= bool(num[j] & 1 << i);
				one |= bool(num[j] & 1 << i);
			} else if (ch[j] == '&') {
				zer &= bool(num[j] & 1 << i);
				one &= bool(num[j] & 1 << i);
			} else if (ch[j] == '^') {
				zer ^= bool(num[j] & 1 << i);
				one ^= bool(num[j] & 1 << i);
			}
		if (zer == 0 && one == 0) AND ^= 1 << i;
		else if (zer == 1 && one == 0) XOR ^= 1 << i;
		else if (zer == 1 && one == 1) OR ^= 1 << i;
	}
	printf("3\n");
	printf("& %d\n", AND);
	printf("^ %d\n", XOR);
	printf("| %d\n", OR);
	return 0;
}