#include<bits/stdc++.h>
using namespace std;

const int N = 100000 + 10;

char a[N], b[N], c[N];
int aaa[200], bbb[200], ccc[200];
int maxaa, maxbb, maxcc;
int n;

int main() {
	scanf("%d", &n);
	scanf("%s %s %s", &a, &b, &c);
	int len = strlen(a);
	for(int i = 0; i < len; i++) {
		aaa[a[i]]++;
		maxaa = max(maxaa, aaa[a[i]]);
		bbb[b[i]]++;
		maxbb = max(maxbb, bbb[b[i]]);
		ccc[c[i]]++;
		maxcc = max(maxcc, ccc[c[i]]);
	}
	if(maxaa == len && n == 1) maxaa -= 2;
	if(maxbb == len && n == 1) maxbb -= 2;
	if(maxcc == len && n == 1) maxcc -= 2;
	if((maxaa + n >= len) + (maxbb + n >= len) + (maxcc + n >= len) >= 2) {
		printf("Draw");
		return 0;
	}
	int maxnn = max(maxaa, max(maxbb, maxcc));
	if((maxaa == maxnn) + (maxnn == maxcc) + (maxbb == maxnn) >= 2) {
		printf("Draw");
		return 0;
	}
	if(maxaa > maxbb && maxaa > maxcc) {
		printf("Kuro");
		return 0;
	}
	if(maxbb > maxcc) {
		printf("Shiro");
		return 0;
	}
	printf("Katie");
	return 0;
}