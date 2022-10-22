#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cctype>
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const int mod = 1000000007;

char str[Maxn];
int slen;
int res = 1;

int main()
{
	scanf("%s", str);
	slen = strlen(str);
	for (int i = 0; i < slen; i++) {
		int num;
		if (isdigit(str[i])) num = str[i] - '0';
		else if (isupper(str[i])) num = str[i] - 'A' + 10;
		else if (islower(str[i])) num = str[i] - 'a' + 36;
		else if (str[i] == '-') num = 62;
		else num = 63;
		for (int j = 0; j < 6; j++)
			if (num & 1 << j) res *= 1;
			else res = ll(res) * 3 % mod;
	}
	printf("%d\n", res);
	return 0;
}