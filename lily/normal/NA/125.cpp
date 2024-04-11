#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)
#define x first
#define y second

const int N = 1011;

char s[N];
bool ans[N];
int main() {

	scanf("%s", s + 1);
	int n = (int)strlen(s + 1);
	for (int i = 1, j = n; i < j;) {
		while (i < j && s[i] != '(') i++;
		while (i < j && s[j] != ')') j--;
		if (i < j) ans[i] = ans[j] = 1;
		i++, j--;
	}
	int tot = 0;
	for (int i = 1; i <= n; i++) tot += ans[i];
	cout << !!tot << endl;
	if (tot) cout << tot << endl;
	for (int i = 1; i <= n; i++) if (ans[i]) {
		printf("%d ", i);
	}
}