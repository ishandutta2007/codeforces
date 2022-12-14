#include <cstdio>
#include <set>
#include <algorithm>
const int MAXN = 100005;
using namespace std;
typedef pair <int, int> pii;
#define x first
#define y second

int n, m, id[MAXN], bit[MAXN];
pii p[MAXN];
set <pii> val;
set <pii> :: iterator it;

void update(int pos, int v){
	++ pos;
	for(; pos <= m; pos += pos & -pos)
		if(v > bit[pos]) bit[pos] = v;
}
int query(int pos){
	++ pos;
	int ret = 0;
	for(; pos; pos -= pos & -pos)
		if(bit[pos] > ret) ret = bit[pos];
	return ret;
}
int main(){
	int i, t;
	scanf("%d", &n);
	for(i = 1; i <= n; ++ i){
		scanf("%d%d", &p[i].x, &p[i].y);
		if(p[i].y > m) m = p[i].y;
	} ++ m;
	sort(p + 1, p + 1 + n);
	for(i = 1; i <= n; ++ i){
		scanf("%d", &t);
		val.insert(pii(t, i));
	}
	for(i = 1; i <= n; ++ i){
		it = val.lower_bound(pii(p[i].y - p[i].x, 1));
		if(it -> x != p[i].y - p[i].x){
			printf("NO\n");
			return 0;
		}
		if(query(p[i].y) > it -> y){
			printf("NO\n");
			return 0;
		}
		id[it -> y] = i;
		update(p[i].y, it -> y);
		val.erase(it);
	}
	printf("YES\n");
	for(i = 1; i <= n; ++ i)
		printf("%d %d\n", p[id[i]].x, p[id[i]].y);
	return 0;
}