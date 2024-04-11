#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
int r, b, d;

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d", &r, &b, &d);
		if (r > b) swap(r, b);
		if (b <= ll(d + 1) * r) printf("YES\n");
		else printf("NO\n"); 
	}
    return 0;
}