#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)

const int N = 2e5 + 5;

char s[N];
int f[N];

int getf(int x) {
	return f[x] == x ? x : (f[x] = getf(f[x]));
}



int main() {
	int T;
	read(T);
	while (T--) {
		int n;
		read(n);
		n *= 2;
		scanf("%s", s + 1);
		for (int i = 1; i <= n; i++) f[i] = i;
		stack <int> st;
		for (int i = 1; i <= n; i++) {
			if (s[i] == '(') st.push(i);
			else {
				int j = st.top(); st.pop();
				f[getf(i)] = getf(j);
				if (i < n && s[i + 1] == '(') f[getf(i)] = getf(i + 1);
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) ans += f[i] == i;
		printf("%d\n", ans);
	}

}