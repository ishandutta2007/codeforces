#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
char str[Maxn];
int res[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		scanf("%s", str);
		vector <int> zers, ones;
		for (int i = 0; i < n; i++)
			if (str[i] == '0')
				if (!ones.empty()) { res[i] = ones.back(); zers.push_back(ones.back()); ones.pop_back(); }
				else {
					res[i] = int(zers.size()) + int(ones.size()) + 1;
					zers.push_back(res[i]);
				}
			else if (!zers.empty()) { res[i] = zers.back(); ones.push_back(zers.back()); zers.pop_back(); }
				 else {
				 	res[i] = int(zers.size()) + int(ones.size()) + 1;
				 	ones.push_back(res[i]);
				 }
		printf("%d\n", int(zers.size()) + int(ones.size()));
		for (int i = 0; i < n; i++)
			printf("%d%c", res[i], i + 1 < n? ' ': '\n');
	}
    return 0;
}