# include <iostream>
# include <cstring>
# include <algorithm>
# include <cstdio>

using namespace std;

int n, m;

char a[200010];

int main() {
	scanf("%d%d", &n, &m);
	scanf("%s", a);
	reverse(a, a + n);
	a[n] = '0';
	int t = -1, dot = -1;
	for(int i = 0; i < n; ++i) if(a[i] == '.') dot = i;

	for(int i = 0, j; i < dot; i = j) {
		if(a[i] >= '5') {
			for(j = i + 1; a[j] == '4'; ++j) ;
			t = i + min(j - i, m);
			i = j;
		} else {
			j = i + 1;
		}
	}

	if(t != -1) {
		while(a[t] == '9') t++;
		if(a[t] == '.') ++t;
		while(a[t] == '9') a[t++] = '0';
		a[t] += 1;
	}

	if(t == -1) {
		for(int i = n - 1; i >= 0; --i) putchar(a[i]);
	} else if(t == n) {
		for(int i = n; a[i] != '.'; --i) putchar(a[i]);
	} else if(t < dot) {
		for(int i = n - 1; i >= t; --i) putchar(a[i]);
	} else {
		for(int i = max(n - 1, t); i > dot; --i) putchar(a[i]);
	}
	puts("");
}