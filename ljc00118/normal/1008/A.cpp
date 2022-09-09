#include <bits/stdc++.h>
using namespace std;

char c[200];
char fu[5] = {'a', 'o', 'u', 'i', 'e'};
int len;

bool pd(int x) {
	for(int i = 0; i < 5; i++) if(c[x] == fu[i]) return 1;
	return 0;
}

int main() {
	scanf("%s", c + 1);
	len = strlen(c + 1);
	for(int i = 1; i < len; i++) {
		if(pd(i) == 0 && pd(i + 1) == 0 && c[i] != 'n') {
			cout << "NO" << endl;
			return 0;
		}
	}
	if(pd(len) == 0 && c[len] != 'n') cout << "NO" << endl;
	else cout <<"YES" << endl;
	return 0;
}