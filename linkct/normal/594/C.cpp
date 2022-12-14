#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 100005;
typedef long long int LL;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;

struct Point{
	int x, y, id;
}p[MAXN], p_[MAXN];
int n, m, removed[MAXN];

bool cmp1(const Point &l, const Point &r){
	return l.x < r.x;
}
bool cmp2(const Point &l, const Point &r){
	return l.y < r.y;
}
int main(){
	//freopen("test.out", "w", stdout);
	int i, tx, ty, j, k, l, cnt, cnt_, t; LL ans = INF;
	scanf("%d%d", &n, &m);
	for(i = 1; i <= n; ++ i){
		scanf("%d%d%d%d", &p[i].x, &p[i].y, &tx, &ty);
		p[i].x += tx, p[i].y += ty; p[i].id = i;
		p_[i] = p[i];
	}
	sort(p + 1, p + 1 + n, cmp1);
	sort(p_ + 1, p_ + 1 + n, cmp2);
	for(i = 1; i <= n && i <= m + 1; ++ i){
		for(j = n; j >= 1; -- j){
			cnt = i - 1 + n - j;
			if(cnt > m) break;
			//printf("i = %d, j = %d, cnt = %d\n", i, j, cnt);
			for(k = 1; k <= n && cnt <= m; ++ k){
				if(removed[p_[k].id] && removed[p_[k].id] < 3) continue;
				cnt_ = cnt;
				for(l = n; l >= 1 && cnt_ <= m; -- l){
					if(removed[p_[l].id] && removed[p_[l].id] < 4) continue;
					//for(t = 1; t <= n; ++ t) printf("%d removed by %d\n", t, removed[t]);
					//printf("x: %d .. %d, y: %d .. %d, %d, %d, %d, %d\n", p[i].x, p[j].x, p_[k].y, p_[l].y, i, j, k, l);
					ans = min(ans, max(LL((p[j].x - p[i].x + 1) >> 1), 1LL) * max(LL((p_[l].y - p_[k].y + 1) >> 1), 1LL));
					removed[p_[l].id] = 4;
					++ cnt_;
				}
				for(++ l; l <= n; ++ l) if(removed[p_[l].id] == 4) removed[p_[l].id] = 0;
				++ cnt;
				removed[p_[k].id] = 3;
			}
			for(-- k; k; -- k) if(removed[p_[k].id] == 3) removed[p_[k].id] = 0;
			removed[p[j].id] = 2;
		}
		for(++ j; j <= n; ++ j) removed[p[j].id] = 0;
		removed[p[i].id] = 1;
	}
	printf("%I64d\n", ans);
	return 0;
}