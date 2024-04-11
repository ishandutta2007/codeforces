# include <iostream>
# include <cstdio>
# include <algorithm>
# include <set>

using namespace std;

int a[100010];
int b[100010];
int f[100010];
long long s[100010];
long long ans[100010];

multiset<long long>S;

int get(int x) { return f[x] == x ? x : f[x] = get(f[x]); }

int main() {
	int n; scanf("%d", &n);
	for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
	for(int i = 0; i < n; ++i) scanf("%d", &b[i]);
	for(int i = 0; i < n; ++i) f[i] = -1;
	reverse(b, b + n);
	for(int k = 0; k < n - 1; ++k) {
		int i = b[k] - 1;
		long long sum = a[i];
		f[i] = i;
		if(i && ~f[i-1]) {
			int fx = get(i-1);
			sum += s[fx];
			S.erase(S.find(s[fx]));
			f[fx] = i;
		}
		if(i < n-1 && ~f[i+1]) {
			int fx = get(i+1);
			sum += s[fx];
			S.erase(S.find(s[fx]));
			f[fx] = i;
		}
		S.insert(sum);
		s[i] = sum;
		ans[k+1] = *S.rbegin();
	}
	reverse(ans, ans + n);
	for(int i = 0; i < n; ++i) 
		printf("%I64d\n", ans[i]);
	return 0;
}