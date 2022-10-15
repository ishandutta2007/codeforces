#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)

void work() {
	int s;
	read(s);
	vector <int> ans;
	for (int i = 9; s && i > 0; i--)  {
		if (s >= i) s -= i, ans.push_back(i);
		else ans.push_back(s), s = 0;
	}
	reverse(ans.begin(), ans.end());
	for (auto v : ans) printf("%d", v);
	printf("\n");
	
}

int main() {
	int T;
	read(T);
	while (T--) work();

}