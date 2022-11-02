# include <iostream>
# include <cstdio>
# include <algorithm>
using namespace std;
const int N = 300020;
pair<int,int> a[N];
int n, m, pos=1;
long long s[N], ans, sum;

int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		scanf("%d", &a[i].first),
		a[i].second = i;
	sort(a+1, a+n+1);
	for(int i=1; i<=n; i++)
		s[i] = s[i-1] + a[i].first;
	scanf("%d", &m);
	for(int i=1, j=-(m-1); i<=m; i++,j+=2)
		sum += a[i].first * j;
	ans = sum;
	for(int i=m+1; i<=n; i++) {
		sum -= 2 * (s[i-1] - s[i-m-1]),
		sum += 1LL * (m+1) * a[i-m].first,
		sum += 1LL * (m-1) * a[i].first;
		if(sum < ans) {
			ans = sum;
			pos = i-m+1;
		}
	}
	for(int i=pos; i<pos+m; i++)
		printf("%d ",a[i].second);
	return 0;
}