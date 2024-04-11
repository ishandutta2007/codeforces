#include <cstdio>
#include <algorithm>
using std :: sort;
const int MAXN = 1005;

inline int abs(int x){return x > 0 ? x : -x;}
struct coord{
	int x, y;
}c[MAXN];
int n, x0, y0;
bool cmp(const coord& lhs, const coord& rhs){
	if(rhs.x != x0 && lhs.x != x0){
		int t = (lhs.y - y0) * (rhs.x - x0) < (rhs.y - y0) * (lhs.x - x0);
		return (rhs.x - x0) * (lhs.x - x0) >= 0 ? t : !t;
	}else if(rhs.x != x0) return false;
	else if(lhs.x != x0) return true;
	else return false;
}

int main(){
	int i, cnt;
	scanf("%d%d%d", &n, &x0, &y0);
	for(i = 1; i <= n; ++ i)
		scanf("%d%d", &c[i].x, &c[i].y);
	sort(c + 1, c + 1 + n, cmp);
	for(cnt = 1, i = 2; i <= n; ++ i)
		if((c[i - 1].y - y0) * (c[i].x - x0) != (c[i].y - y0) * (c[i - 1].x - x0))
			cnt ++;
	printf("%d\n", cnt);
	return 0;
}