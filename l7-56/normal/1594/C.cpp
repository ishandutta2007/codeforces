#include <bits/stdc++.h>
typedef long long ll;
typedef double db;
using namespace std;

const int maxn = 3e5 + 10;
char s[maxn],c;
int n,t;

int main() {
	scanf("%d", &t);
	while(t--) {
		cin >> n >> c >> (s + 1);
		bool fl = 0;
		for(int i = 1; i < n; ++i)
			if(s[i] != c) fl = 1;
		if(s[n] == c) {
			printf("%d\n", fl);
			if(fl) printf("%d\n", n);
		}
		else {
			int pos = -1;
			for(int i = n - 1; i * 2 > n && pos == -1; --i)
				if(s[i] == c) pos = i;
			if(pos == -1 && fl) printf("2\n%d %d\n", n, n - 1);
			else if(pos == -1 && !fl) printf("1\n%d\n", n - 1);
			else printf("1\n%d\n", pos);
		}
	}
	return 0;
}