#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
char str[Maxn];
int slen;

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%s", str);
		slen = strlen(str);
		for (int i = 0; i < slen; i += 2)
			if (str[i] == '0') str[i] = '1';
			else if (str[i] == '1') str[i] = '0';
		int cnt0 = 0, cnt1 = 0;
		int l = 0;
		long long res = 0;
		for (int i = 0; i < slen; i++) {
			if (str[i] == '0') cnt0++;
			else if (str[i] == '1') cnt1++;
			while (cnt0 > 0 && cnt1 > 0) {
				if (str[l] == '0') cnt0--;
				else if (str[l] == '1') cnt1--;
				l++;
			}
			res += i - l + 1;
		}
		printf("%I64d\n", res);
	}
    return 0;
}