#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
typedef double db;
using namespace std;

const int maxn = 110;
int a[maxn],b[maxn],n,T;

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
		for(int i = 1; i <= n; ++i) scanf("%d", &b[i]);
		sort(a + 1, a + n + 1);
		sort(b + 1, b + n + 1);
		bool flag = 1;
		for(int i = 1; i <= n; ++i)
			if(a[i] != b[i] && a[i] + 1 != b[i]) flag = 0;
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}