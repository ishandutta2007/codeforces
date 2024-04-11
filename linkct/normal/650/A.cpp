#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long int LL;
const int MAXN = 200005;

struct Point{
	int x, y;
	bool operator < (const Point &rhs) const{
		return x == rhs.x ? y < rhs.y : x < rhs.x;
	}
}p[MAXN];
int n;

inline LL f(LL x){return x * (x - 1) >> 1;}
int main(){
	int i, j; LL ans = 0LL;
	scanf("%d", &n);
	for(i = 1; i <= n; ++ i) scanf("%d%d", &p[i].x, &p[i].y);
	sort(p + 1, p + 1 + n);
	for(i = j = 1; i <= n; ++ i){
		if(i < n && p[i + 1].x == p[i].x) continue;
		ans += f(i - j + 1);
		j = i + 1;
	}
	for(i = 1; i <= n; ++ i) swap(p[i].x, p[i].y);
	sort(p + 1, p + 1 + n);
	for(i = j = 1; i <= n; ++ i){
		if(i < n && p[i + 1].x == p[i].x) continue;
		ans += f(i - j + 1);
		j = i + 1;
	}
	for(i = j = 1; i <= n; ++ i){
		if(i < n && p[i + 1].x == p[i].x && p[i + 1].y == p[i].y) continue;
		ans -= f(i - j + 1);
		j = i + 1;
	}
	printf("%I64d\n", ans);
	return 0;
}