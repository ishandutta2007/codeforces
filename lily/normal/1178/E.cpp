#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define read(a) scanf("%d", &a)

#define N 1010155

int n;
char s[N];
int cnt[1231];
vector <char> ansf, ansb;
int main() {
	scanf("%s", s);
	n = (int)strlen(s);
	for (int i = 0; i < n; i++) {
		cnt[s[i]]++;
	}
	int ma = 'a';
	if (cnt['b'] > cnt[ma]) ma = 'b';
	if (cnt['c'] > cnt[ma]) ma = 'c';
	int l = 0, r = n - 1;
	while (l <= r) {
		if (s[l] == s[r]) {
			ansf.push_back(s[l]);
			if (l != r) ansb.push_back(s[l]);
			l++, r--;
		}
		else {
			if (s[l] == ma) r--;
			else l++;
		}
	}
	for (auto v : ansf) putchar(v);
	reverse(ansb.begin(), ansb.end());
	for (auto v : ansb) putchar(v);
	putchar('\n');
}