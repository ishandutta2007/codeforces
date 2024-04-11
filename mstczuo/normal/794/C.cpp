# include <bits/stdc++.h>
using namespace std;

int n;
char a[300010];
char b[300010];
char ans[300010];
int la, lb;
int ca, cb;

int main() {
	scanf("%s", a);
	scanf("%s", b);
	n = strlen(a);
	sort(a, a+n);
	sort(b, b+n);
	reverse(b, b+n);
	la = (n + 1) / 2;
	lb = n / 2;
	a[la] = b[lb] = 0;

	int l = 0, r = n;
	for(int i = 0; i < n; ++i) {
		if(~i & 1) {
			if(b[cb] <= a[ca]) {
				ans[--r] = a[--la];
			} else {
				ans[l++] = a[ca++];
			}
		} else {
			if(a[ca] >= b[cb]) {
				ans[--r] = b[--lb];
			} else {
				ans[l++] = b[cb++];
			}
		}
	}
	puts(ans);
	return 0;
}