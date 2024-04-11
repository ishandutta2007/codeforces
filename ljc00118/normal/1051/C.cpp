#include <bits/stdc++.h>
#define For(i, a, b) for(int i = a; i <= b; i++)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') {if(c == '-') fu = -1; c = getchar();}
    while(c >= '0' && c <= '9') {f = (f << 3) + (f << 1) + (c & 15); c = getchar();}
    f *= fu;
}

const int N = 110;

int a[N], s[N];
int n, last, ko = 0;

int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i]; s[a[i]]++;
	}
	bool ok = 0;
	int ans = 0;
	for(int i = 1; i <= 100; i++) {
		if(s[i] >= 3) ok = 1, last = i;
		if(s[i] == 1) ans++;
	}
	if(!ok && ans & 1) {
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	if(ans & 1) {
		ans /= 2;
		for(int i = 1; i <= n; i++) {
			if(s[a[i]] == 1) {
				if(ans) {
					printf("A");
					ans--;
				} else printf("B"); 
			} else if(a[i] == last) {
				if(!ko) printf("A"), ko = 1;
				else printf("B");
			}
			else printf("B");
		}
	} else {
		ans >>= 1;
		for(int i = 1; i <= n; i++) {
			if(s[a[i]] == 1) {
				if(ans) {
					printf("A");
					ans--;
				} else printf("B");
			} else printf("A");
		}
	}
	return 0;
}