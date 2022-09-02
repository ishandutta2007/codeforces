#include <bits/stdc++.h>
using namespace std;

#define Fi first
#define Se second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)
typedef tuple<int, int, int> t3;

int n, a[200020];

int main() {
	int T; scanf("%d", &T);
	for(int t=1;t<=T;t++) {
		scanf("%d", &n);
		for(int i=1;i<=n;i++) scanf("%d", a + i);
		if(*max_element(a+1, a+1+n) == *min_element(a+1, a+1+n)) printf("%d\n", n);
		else puts("1");
	}
	return 0;
}