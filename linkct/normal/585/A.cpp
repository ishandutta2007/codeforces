#include <cstdio>
#include <set>
#include <queue>
using namespace std;
const int MAXN = 4005;
typedef long long int ll;

int n, ans[MAXN];
ll v[MAXN], d[MAXN], p[MAXN];
set <int> child;
queue <int> q;

int main(){
	int i, j, now; set <int> :: iterator it, tmp;
	scanf("%d", &n);
	for(i = 1; i <= n; ++ i){
		scanf("%I64d%I64d%I64d", &v[i], &d[i], &p[i]);
		child.insert(i);
	}
	for(i = 1; i <= n; ++ i){
		if(child.empty() || *child.begin() != i) continue;
		ans[++ ans[0]] = i;
		it = child.begin();
		child.erase(it);
		for(j = 0, it = child.begin(); it != child.end() && j < v[i]; ++ j){
			p[*it] -= v[i] - j;
			if(p[*it] < 0){
				q.push(*it);
				tmp = it; ++ tmp;
				child.erase(it);
				it = tmp;
			}else ++ it;
		}
		while(!q.empty()){
			now = q.front(); q.pop();
			for(it = child.upper_bound(now); it != child.end(); ){
				p[*it] -= d[now];
				if(p[*it] < 0){
					q.push(*it);
					tmp = it; ++ tmp;
					child.erase(it);
					it = tmp;
				}else ++ it;
			}
		}
	}
	printf("%d\n", ans[0]);
	for(i = 1; i <= ans[0]; ++ i) printf("%d ", ans[i]);
	printf("\n");
	return 0;
}