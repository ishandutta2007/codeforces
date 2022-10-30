# include <bits/stdc++.h>
using namespace std;

char a[100010];
int cnt[128];

int main() {
	int n;
	scanf("%d", &n);
	scanf("%s", a);
	if(n == 1) {
		puts("Yes");
		return 0;
	}
	for(int i = 0; i < n; ++i) 
		cnt[a[i] - 'a'] += 1;
	int mx = *max_element(cnt, cnt + 26);
	puts(mx > 1 ? "Yes": "No");
}