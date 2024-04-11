#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
const int Maxd = 10;

int bits[1 << Maxd];
int t;
char str[Maxn];
int slen;

int main()
{
	for (int i = 1; i < 1 << Maxd; i++)
		bits[i] = 1 + bits[i - (i & -i)];
	scanf("%d", &t);
	while (t--) {
		scanf("%s", str); slen = strlen(str);
		int cur = 0;
		for (int i = 0; i < slen; i++)
			cur ^= 1 << int(str[i] - '0');
		bool solved = false;
		for (int i = slen - 1; i >= 0 && !solved; i--) {
			int my = str[i] - '0';
			cur ^= 1 << my;
			for (int j = my - 1; j >= 0 && !solved; j--) {
				cur ^= 1 << j;
				if (i + 1 + bits[cur] <= slen) {
					solved = true;
					str[i] = j + '0';
					int pnt = i + 1;
					int lft = slen - (i + 1 + bits[cur]);
					while (lft--) str[pnt++] = '9';
					for (int l = Maxd - 1; l >= 0; l--) if (cur & 1 << l)
						str[pnt++] = '0' + l;
				}
				cur ^= 1 << j;
			}
		}
		int pnt = 0;
		while (str[pnt] == '0') pnt++;
		for (int i = pnt; i < slen - pnt; i++)
			printf("%c", str[i]);
		printf("\n");
	}
	return 0;
}