#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 500005;

struct Interval{
	int l, r;
	bool operator < (const Interval &rhs) const{
		return r < rhs.r;
	}
}interval[MAXN];
int n;

int main(){
	int i, cur, ans = 0;
	scanf("%d", &n);
	for(i = 1; i <= n; ++ i) scanf("%d%d", &interval[i].l, &interval[i].r);
	sort(interval + 1, interval + 1 + n);
	for(i = 1, cur = 0; i <= n; ++ i)
		if(interval[i].l > cur){
			ans ++;
			cur = interval[i].r;
		}
	printf("%d\n", ans);
	return 0;
}