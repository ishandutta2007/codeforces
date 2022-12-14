#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
typedef long long int LL;
const int MAXN = 200005;

struct Triple{
	int fi, se, ti;
	Triple(int f, int s, int t){fi = f, se = s, ti = t;}
	bool operator < (const Triple &rhs) const{
		if(fi != rhs.fi) return fi < rhs.fi;
		if(se != rhs.se) return se < rhs.se;
		return ti < rhs.ti;
	}
};
struct Frogs{
	int lft, id, eaten;
	LL rht;
	bool operator < (const Frogs &rhs) const{
		return lft < rhs.lft;
	}
}frog[MAXN];
set <Triple> remain;
set <Triple> :: iterator it;
int n, m, x;
LL maxv[MAXN << 2];

bool cmp(const Frogs &l, const Frogs &r){
	return l.id < r.id;
}
void treeInit(int x, int l, int r){
	if(l == r){
		maxv[x] = frog[l].rht;
		return;
	}
	int mid = (l + r) >> 1;
	treeInit(x << 1, l, mid);
	treeInit(x << 1 | 1, mid + 1, r);
	maxv[x] = max(maxv[x << 1], maxv[x << 1 | 1]);
}
inline int query(int pos){
	if(maxv[1] < pos) return 0;
	x = 1; int l = 1, r = n, mid;
	while(l < r){
		mid = (l + r) >> 1;
		if(maxv[x << 1] >= pos) r = mid, x <<= 1;
		else l = mid + 1, x = x << 1 | 1;
	}
	return r;
}
int main(){
	int i, pos, size, t;
	scanf("%d%d", &n, &m);
	for(i = 1; i <= n; ++ i){
		scanf("%d%d", &frog[i].lft, &size);
		frog[i].rht = frog[i].lft + size;
		frog[i].id = i;
	}
	sort(frog + 1, frog + 1 + n);
	treeInit(1, 1, n);
	for(i = 1; i <= m; ++ i){
		scanf("%d%d", &pos, &size);
		if((t = query(pos)) && frog[t].lft <= pos){
			frog[t].rht += size;
			++ frog[t].eaten;
			while((it = remain.lower_bound(Triple(frog[t].lft, 0, 0))) != remain.end() && it -> fi <= frog[t].rht){
				frog[t].rht += it -> se;
				++ frog[t].eaten;
				remain.erase(it);
			}
			maxv[x] = frog[t].rht;
			while(x > 1){
				x >>= 1;
				maxv[x] = max(maxv[x << 1], maxv[x << 1 | 1]);
			}
		}else remain.insert(Triple(pos, size, i));
	}
	sort(frog + 1, frog + 1 + n, cmp);
	for(i = 1; i <= n; ++ i) printf("%d %I64d\n", frog[i].eaten, frog[i].rht - frog[i].lft);
	return 0;
}