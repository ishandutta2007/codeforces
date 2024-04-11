# include <bits/stdc++.h>
using namespace std;

char s[200010];
bool a[200010];
stack<int> st;

int main() {
	int n, m; scanf("%d%d", &n, &m);
	m = m >> 1;
	scanf("%s", s);
	for(int i = 0; i < n; ++i) {
		if(s[i] == '(') {
			st.push(i);
		} else {
			if(st.empty()) continue;
			if(m > 0) {
				int p = st.top(); 
				st.pop();
				a[p] = a[i] = true;
				m = m - 1;
			}
		}
	}
	for(int i = 0; i < n; ++i) if(a[i]) putchar(s[i]);
	puts("");
	return 0;
}