#include<bits/stdc++.h>

using namespace std;

int test, c[101], n, d[1001], p[101];
char str[1000011], xxx[1000011];
bool b[101];

int main(){
	scanf("%d", &test);
	for (; test--; ) {
		scanf("%s", str + 1);
		int n = strlen(str + 1);
		bool ok = true;
		memset(d, 0, sizeof(d));
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			d[str[i] - 'a']++;
		for (int i = 0; i < 26; i++)
			if (d[i])
				++cnt;
		memset(b, false, sizeof(b));
		int tot = 0;
		for (int i = 1; i <= cnt && ok; i++) {
			int cur = 0;
			for (int j = n; j; --j)
				if (!b[str[j] - 'a']) {
					cur = str[j] - 'a';
					break;
				}
			if (d[cur] % (cnt - i + 1))
				ok = false;
			else {
				int w = d[cur] / (cnt - i + 1), k = 1;
				p[i] = cur;
				tot += w;
				for (int j = n; j && k <= w && ok; --j)
					if (!b[str[j] - 'a'])
						if (str[j] - 'a' == cur)
							++k;
						else
							ok = false;	
				if (k != w + 1)
					ok = false;
				b[cur] = true;
			}
		}
		if (!ok) {
			printf("-1\n");
		} else {
			memset(b, false, sizeof(b));
			int l = 0;
			for (int i = cnt; i; --i) {
				for (int j = 1; j <= tot; j++)
					if (!b[str[j] - 'a'])
						xxx[++l] = str[j];
				b[p[i]] = true;
			}
			for (int i = 1; i <= n && ok; i++)
				if (xxx[i] != str[i])
					ok = false;
			if (!ok) {
				printf("-1\n");
				continue;
			}
			for (int i = 1; i <= tot; i++)
				printf("%c", str[i]);
			printf(" ");
			for (int i = cnt; i; --i)
				printf("%c", p[i] + 'a');
			printf("\n");
		}
	}
}