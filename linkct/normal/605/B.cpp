#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair <int, int> pii;
#define fi first
#define se second
const int MAXN = 100005;

struct Edge{
	int id, w, isIn, u, v;
	bool operator < (const Edge &rhs) const{
		return w == rhs.w ? isIn > rhs.isIn : w < rhs.w;
	}
}e[MAXN];
int n, m;
vector <pii> option;

bool cmp(const Edge &lhs, const Edge &rhs){
	return lhs.id < rhs.id;
}
int main(){
	int i, j, cnt;
	scanf("%d%d", &n, &m);
	for(i = 1; i <= m; ++ i){
		scanf("%d%d", &e[i].w, &e[i].isIn);
		e[i].id = i;
	}
	sort(e + 1, e + 1 + m);
	for(i = cnt = 1; i <= m; ++ i)
		if(e[i].isIn){
			e[i].u = 1;
			e[i].v = ++ cnt;
			for(j = 2; j < cnt && int(option.size()) < m; ++ j)
				option.push_back(pii(j, cnt));
		}else{
			if(option.empty()){
				printf("-1\n");
				return 0;
			}
			e[i].u = option.back().fi;
			e[i].v = option.back().se;
			option.pop_back();
		}
	sort(e + 1, e + 1 + m, cmp);
	for(i = 1; i <= m; ++ i) printf("%d %d\n", e[i].u, e[i].v);
	return 0;
}