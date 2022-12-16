#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
typedef vector <int> vi;
#define fir first
#define sec second

void work() {
	char s[4];
	scanf("%s", s);
	set <char> st;
	st.insert(s[0]), st.insert(s[1]);
	scanf("%s", s);
	st.insert(s[0]), st.insert(s[1]);
	printf("%d\n", (int) st.size() - 1);
}

int main() {
	int T; scanf("%d", &T);
	while (T--) work();
	return 0;
}