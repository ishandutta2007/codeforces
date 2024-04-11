#include <cstdio>
#include <algorithm>
using namespace std;
#define a first
#define b second
const int MAXN = 100005;
typedef pair <int, int> pii;

pii beacon[MAXN];
int n, f[MAXN];

int main(){
	int i, j, ans = MAXN;
	scanf("%d", &n);
	for(i = 1; i <= n; ++ i)
		scanf("%d%d", &beacon[i].a, &beacon[i].b);
	sort(beacon + 1, beacon + 1 + n);
	for(i = 1; i <= n; ++ i){
		j = lower_bound(beacon + 1, beacon + 1 + n, pii(beacon[i].a - beacon[i].b, 0)) - beacon;
		if(j > 1 && beacon[j - 1].a < beacon[i].a - beacon[i].b) f[i] = f[j - 1] + 1;
		else f[i] = 1;
		if(n - f[i] < ans) ans = n - f[i];
	}
	printf("%d\n", ans);
	return 0;
}