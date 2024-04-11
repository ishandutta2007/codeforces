#include <bits/stdc++.h>
using namespace std;

const int Maxn = 305;

int T;
int n;
int a[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		bool lef = true;
		int l = 0, r = n - 1;
		for (int i = 0; i < n; i++) {
			if (lef) printf("%d%c", a[l++], i + 1 < n? ' ': '\n'); 
			else printf("%d%c", a[r--], i + 1 < n? ' ': '\n');
			lef = !lef;
		}
	}
    return 0;
}