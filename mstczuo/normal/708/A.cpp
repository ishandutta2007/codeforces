# include <iostream>
# include <cstdio>
# include <cstring>

using namespace std;

char a[100010];

int main() {
	scanf("%s", a);
	int n = strlen(a);
	bool flag = true;
	for(int i = 0; i < n; ++i) {
		if(a[i] != 'a') {
			flag = false;
			for(int j = i; j < n && a[j] != 'a'; ++j) {
				a[j] = a[j] - 1;
			}
			break;
		}
	}
	if(flag) {
		a[n - 1] = 'z';
	}
	puts(a);
	return 0;
}