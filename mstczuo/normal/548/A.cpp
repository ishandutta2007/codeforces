# include <iostream>
# include <cstdio>
# include <cstring>

using namespace std;

char a[1200];

bool check(int l,int r) {
	while(l < r) {
		if(a[l] != a[r-1]) return false;
		++l; --r;
	}
	return true;
}

int k;
int main() {
	scanf("%s", a);
	scanf("%d", &k);
	int n = strlen(a);
	
	if(n % k) {
		puts("NO");
		return 0;
	}
	int m = n / k;
	for(int i = 0; i < n; i += m) {
		if(!check(i, i + m)) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}